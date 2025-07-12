#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform() {
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/SciFiShelter/Meshes/SM_Healty_Kit.SM_Healty_Kit"));
	if (MeshAsset.Succeeded()) {
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}


	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/SciFiShelter/Materials/M_Wall.M_Wall"));
	if (MaterialAsset.Succeeded()) {
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();

}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Tick(float DeltaTime)에서 위치를 변경하여 왕복 이동 구현
	//MoveSpeed, MaxRange, StartLocation 등을 고려해 일정 범위를 벗어나면 
	// 이동 방향을 반전시키는 로직 구성
	//이동/회전 시 반드시 DeltaTime을 활용

	FVector CurrentLocation = GetActorLocation();
	if((CurrentLocation - StartLocation).Size() >= MaxRange) {
		MoveSpeed *= -1; 
		StartLocation = CurrentLocation; 
	}
	SetActorLocation(CurrentLocation + MoveSpeed * DeltaTime);	
}