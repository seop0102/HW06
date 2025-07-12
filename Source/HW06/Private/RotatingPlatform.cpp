#include "RotatingPlatform.h"

ARotatingPlatform::ARotatingPlatform() {
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/SciFiShelter/Meshes/SM_Healty_Kit.SM_Healty_Kit"));
	if (MeshAsset.Succeeded()) {
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}


	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/SciFiShelter/Materials/M_Scifi_cabin.M_Scifi_cabin"));
	if (MaterialAsset.Succeeded()) {
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;

	RotationSpeed = 90.0f;
}

void ARotatingPlatform::BeginPlay() {
	Super::BeginPlay();


	SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
	SetActorScale3D(FVector(1.5f, 1.5f, 1.5f));

	GetWorld()->GetTimerManager().SetTimer(
		DirectionChangeTimer, 
		this, 
		&ARotatingPlatform::ChangeRotationDirection, 
		2.0f, 
		true);

}

void ARotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(RotationSpeed)) {
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
	
}

void ARotatingPlatform::ChangeRotationDirection() {
	RotationSpeed *= -1.0f; // 회전 방향을 반전
}