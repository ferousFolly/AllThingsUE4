// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Runtime/Engine/Classes/Engine/SpotLight.h"
#include "Components/SpotLightComponent.h"
#include "LightTrigger_01.generated.h"

UCLASS()
class BPANDCPP_API ALightTrigger_01 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALightTrigger_01();

	UPROPERTY(BlueprintReadWrite, Instanced, EditAnywhere)
		UBoxComponent* Frame_Box;				// Box collision element in BP

	UPROPERTY(EditAnywhere)
		TArray<ASpotLight*> Lights;				// Arrays of "Pickable" lights on stage. Because we use SpotLight class, then (in editor) we can pick items on stage same as BP

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

	bool LightsVisibility = true;			// visibility boolean flag
	void LightOperator();					// function for manage light actors 
	
};
