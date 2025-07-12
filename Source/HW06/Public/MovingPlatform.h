#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h" //항상 마지막에 쓰기

UCLASS()
class HW06_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	

	AMovingPlatform();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RotatingPlatform|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotatingPlatform|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatform|Components")
	FVector MoveSpeed = FVector(200.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatform|Components")
	float MaxRange= 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingPlatform|Components")
	FVector StartLocation;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


};
