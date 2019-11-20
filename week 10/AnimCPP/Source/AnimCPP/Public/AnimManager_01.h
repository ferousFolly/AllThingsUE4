// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Animation/AnimInstance.h"
#include "AnimManager_01.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ANIMCPP_API UAnimManager_01 : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAnimManager_01();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Setup Variables")
		void SetupValues(UObject* AnimMeter, USkeletalMeshComponent* mesh);


	USkeletalMeshComponent* Mesh_01;	// mesh with animation blueprint
	UAnimInstance* Animation_01;		// animation blueprint
	UObject* AnimMeter_01;				// BP_AnimMeter
	UProperty* AnimMeter_Value;			// "Value" property in BP_AnimMeter

	bool Active = false;
	int TriggerValue_01 = 0;			// "Value" property in BP_AnimMeter save in this variable
	int TriggerValue_01_Buffer = 0;		// "Value" property in BP_AnimMeter buffers in this variable

	int GetTrigger();					// getting "Value" property in BP_AnimMeter and set into TriggerValue_01
	void SetAnimationVars_01();			// map animation blueprint variable to this class
	void ValidateAnimVars_01();			// validate animation blueprint variable 
	bool AnimVars_Valid = false;		// validation flag on animation blueprint variable 
	
	void Animate_01(int id);			// execute animation 
	void Animate_Random_01();			// execute random animation 

	
	// Default Motion variables, maped from animation blueprint 
	UBoolProperty* anim_state_switch;
	UBoolProperty* anim_idel;
	UBoolProperty* anim_clapping;

	// Random Motion variables, maped from animation blueprint 
	UBoolProperty* anim_phone_01;
	UBoolProperty* anim_phone_02;
	UBoolProperty* anim_random_01;

		
};


/// Links
// General advices and methods on C++
// https://www.youtube.com/watch?v=2ToUvURP4tE&t=325s
// https://www.youtube.com/watch?v=a5gA7q5GD7Q
// https://www.youtube.com/watch?v=m-YX6L8flGQ  
// https://www.youtube.com/watch?v=Zxjf4efpgGY
// https://www.youtube.com/watch?v=30XEdBoPw6c

// https://www.unrealengine.com/en-US/blog/unreal-property-system-reflection  Unreal Property System (Reflection)

// sample code and protfolio
// https://www.orfeasel.com/tech_demos/
// https://www.tomlooman.com/
// http://www.binarytorgb.com/category/gamedevelopment/