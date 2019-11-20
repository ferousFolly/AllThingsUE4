// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Runtime/Engine/Classes/Components/TextRenderComponent.h"
#include "Engine/World.h"
#include "Sample_01.generated.h"

UCLASS()
class BPANDCPP_API ASample_01 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASample_01();

	UPROPERTY(EditAnywhere)
		UBoxComponent* Frame_Box;			// same like BoxCollision in BP
	
	UPROPERTY(EditAnywhere)
		UTextRenderComponent* infoText;		// same like TextRender in BP

	UPROPERTY(EditAnywhere)
		FString infoName;

	/* UPROPERTY - Declaration, Description(s) and usage
	https://wiki.unrealengine.com/UPROPERTY
	https://docs.unrealengine.com/en-us/Programming/UnrealArchitecture/Reference/Properties
	*/

	UFUNCTION()
		void OnCollision_Start(
			UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult & SweepResult
		);

	/* UFUNCTION - Declaration for Blueprint, Description(s) and example
	https://wiki.unrealengine.com/UFUNCTION
	https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Reference/Functions
	https://answers.unrealengine.com/questions/543285/global-blueprint-callable-c-functions.html
	*/

	/*
	 collision -base
	https://www.youtube.com/watch?v=zZPyMjEWpF8&t=1262s
	https://www.youtube.com/watch?v=XmSnzDIKfTw

	collision -c++ example
	https://www.youtube.com/watch?v=LACvuJgQU5c

	answer hub -search
	https://answers.unrealengine.com/questions/320852/collision-detection-in-c.html

	check collision on Hit
	https://www.youtube.com/watch?v=1oiOi5peMCg
	*/
	
	void DestroyItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
