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
	//Tick(float DeltaTime)���� ��ġ�� �����Ͽ� �պ� �̵� ����
	//MoveSpeed, MaxRange, StartLocation ���� ����� ���� ������ ����� 
	// �̵� ������ ������Ű�� ���� ����
	//�̵�/ȸ�� �� �ݵ�� DeltaTime�� Ȱ��

	FVector CurrentLocation = GetActorLocation();
	if((CurrentLocation - StartLocation).Size() >= MaxRange) {
		MoveSpeed *= -1; 
		StartLocation = CurrentLocation; 
	}
	SetActorLocation(CurrentLocation + MoveSpeed * DeltaTime);	
}