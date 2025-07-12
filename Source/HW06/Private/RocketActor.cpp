#include "RocketActor.h"

// Sets default values
ARocketActor::ARocketActor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
 	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Fab/Toy_Rocket/toy_rocket.toy_rocket"));
	if (MeshAsset.Succeeded()) {
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
	
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Fab/Toy_Rocket/blue.blue"));
	if (MaterialAsset.Succeeded()) {
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	StaticMeshComp->SetWorldScale3D(FVector(0.1f));
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARocketActor::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	
}

// Called every frame
void ARocketActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();

	if (bMovingUp && CurrentLocation.Z >= MaxHeight)
	{
		bMovingUp = false;
		MoveSpeed.Z = -FMath::Abs(MoveSpeed.Z);
		SetActorRotation(FRotator(180.f, 0.f, 0.f));  // 아래 방향
	}
	// 아래로 이동 중인데 시작 지점보다 낮아지면 다시 위로
	else if (!bMovingUp && CurrentLocation.Z <= StartLocation.Z)
	{
		bMovingUp = true;
		MoveSpeed.Z = FMath::Abs(MoveSpeed.Z);
		SetActorRotation(FRotator::ZeroRotator);  // 위 방향
	}

	SetActorLocation(CurrentLocation + MoveSpeed * DeltaTime);
}



