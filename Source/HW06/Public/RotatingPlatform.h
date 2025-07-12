#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatform.generated.h" //�׻� ������

UCLASS()
class HW06_API ARotatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingPlatform();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="RotatingPlatform|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RotatingPlatform|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RotatingPlatform|Components")
	float RotationSpeed;

	FTimerHandle DirectionChangeTimer;

	virtual void ChangeRotationDirection();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	

};
