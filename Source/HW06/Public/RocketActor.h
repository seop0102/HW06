#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RocketActor.generated.h"

UCLASS()
class HW06_API ARocketActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARocketActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RocketActor|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RocketActor|Components")
	UStaticMeshComponent* StaticMeshComp;

	FVector MoveSpeed;
	float MaxHeight;
	FVector StartLocation;
	bool bMovingUp = true;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
};
