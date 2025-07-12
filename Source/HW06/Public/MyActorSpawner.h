#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActorSpawner.generated.h"

UCLASS()
class HW06_API AMyActorSpawner : public AActor
{
	GENERATED_BODY()

public:
	AMyActorSpawner();

	UFUNCTION()
	void SpawnActor();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBoxComponent* SpawnVolume;

public:
	virtual void Tick(float DeltaTime) override;

};
