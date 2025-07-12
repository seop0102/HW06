#include "MyActorSpawner.h"
#include "Components/BoxComponent.h"
#include "RocketActor.h"
#include "Engine/World.h"

// 생성자
AMyActorSpawner::AMyActorSpawner()
{
    PrimaryActorTick.bCanEverTick = true;

    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));

    SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolume"));
    SpawnVolume->SetupAttachment(RootComponent);
}

void AMyActorSpawner::BeginPlay()
{
    Super::BeginPlay();
    SpawnActor();  // 시작할 때 한 번 실행
}

void AMyActorSpawner::SpawnActor()
{
    if (!SpawnVolume) return;

    FVector Origin = SpawnVolume->Bounds.Origin;
    FVector Extent = SpawnVolume->Bounds.BoxExtent;

    int32 NumToSpawn = FMath::RandRange(5,10);  // 로켓 개수 랜덤

    for (int32 i = 0; i < NumToSpawn; ++i)
    {
        // SpawnVolume 안에서 랜덤 위치 계산
        float RandX = FMath::RandRange(-Extent.X, Extent.X);
        float RandY = FMath::RandRange(-Extent.Y, Extent.Y);
        float RandZ = FMath::RandRange(-Extent.Z, Extent.Z);
        FVector SpawnLocation = Origin + FVector(RandX, RandY, RandZ);

        // 회전은 기본값
        FRotator SpawnRotation = FRotator::ZeroRotator;

        // 로켓 생성
        ARocketActor* Rocket = GetWorld()->SpawnActor<ARocketActor>(ARocketActor::StaticClass(), SpawnLocation, SpawnRotation);

        if (Rocket)
        {
            // 랜덤 속성 부여
            float RandomSpeedZ = FMath::RandRange(20.0f, 100.0f);
            float RandomHeight = FMath::RandRange(100.0f, 400.0f);

            Rocket->MoveSpeed = FVector(0.f, 0.f, RandomSpeedZ);
            Rocket->MaxHeight = RandomHeight;
        }
    }
}

void AMyActorSpawner::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
