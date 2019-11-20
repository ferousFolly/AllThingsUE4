// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/SpotLightComponent.h"
#include "Runtime/Engine/Classes/Engine/SpotLight.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "LightTrigger_03.generated.h"

UCLASS()
class BPANDCPP_API ALightTrigger_03 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALightTrigger_03();

	UPROPERTY(BlueprintReadWrite, Instanced, EditAnywhere)
		UBoxComponent* Frame_Box;				// Box collision element in BP

	UFUNCTION()
		void OnEntering(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
		void OnLeaving(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	bool LightsVisibility = true;

	ACharacter*	CollisionCharacter = NULL;	// Use for detect character in collision funtion

	TArray<AActor*> Lights;		// Arrays of lights on stage.

	void LightOperator();

	
};
