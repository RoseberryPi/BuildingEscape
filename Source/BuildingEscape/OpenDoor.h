// William Roseberry 2021

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

	public:
	// Sets default values for this component's properties
	UOpenDoor();

	protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);

	private:
	float InitialYaw;
	float CurrentYaw;
	float DoorLastOpen = 0.f;

	UPROPERTY(EditAnywhere)
		float DoorOpenAngle = 90.f;

	UPROPERTY(EditAnywhere)
		float DoorOpenSpeed = 2.f;

	UPROPERTY(EditAnywhere)
		float DoorCloseSpeed = 2.f;

	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 2.f;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere)
		AActor* ActorThatOpens;
};
