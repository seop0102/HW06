#include "MyActorSpawner.h"
#include "Components/BoxComponent.h"
#include "RocketActor.h"
#include "Engine/World.h"

// ������
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
    SpawnActor();  // ������ �� �� �� ����
}

void AMyActorSpawner::SpawnActor()
{
    if (!SpawnVolume) return;

    FVector Origin = SpawnVolume->Bounds.Origin;
    FVector Extent = SpawnVolume->Bounds.BoxExtent;

    int32 NumToSpawn = FMath::RandRange(5,10);  // ���� ���� ����

    for (int32 i = 0; i < NumToSpawn; ++i)
    {
        // SpawnVolume �ȿ��� ���� ��ġ ���
        float RandX = FMath::RandRange(-Extent.X, Extent.X);
        float RandY = FMath::RandRange(-Extent.Y, Extent.Y);
        float RandZ = FMath::RandRange(-Extent.Z, Extent.Z);
        FVector SpawnLocation = Origin + FVector(RandX, RandY, RandZ);

        // ȸ���� �⺻��
        FRotator SpawnRotation = FRotator::ZeroRotator;

        // ���� ����
        ARocketActor* Rocket = GetWorld()->SpawnActor<ARocketActor>(ARocketActor::StaticClass(), SpawnLocation, SpawnRotation);

        if (Rocket)
        {
            // ���� �Ӽ� �ο�
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
