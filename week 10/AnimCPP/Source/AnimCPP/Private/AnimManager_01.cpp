// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimManager_01.h"

// Sets default values for this component's properties
UAnimManager_01::UAnimManager_01()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}

// Called when the game starts
void UAnimManager_01::BeginPlay() {
	Super::BeginPlay();
}



// ---------------------------------------------------------------
// setup  -------------------------------------------------------- 
void UAnimManager_01::SetupValues(UObject* animMeter, USkeletalMeshComponent* mesh){
	
	UE_LOG(LogTemp, Warning, TEXT(">>Debug: ---- SetupValues: Begin"));

	// check if BP_AnimMeter is exist
	if (animMeter != NULL) {
		AnimMeter_01 = animMeter;
		AnimMeter_Value = AnimMeter_01->GetClass()->FindPropertyByName(TEXT("Value"));
		if (AnimMeter_Value) Active = true;
	}

	// check if parent`s mesh has animation blueprint 
	if (mesh != NULL) {
		TArray<USkeletalMeshComponent*> Components;
		this->GetOwner()->GetRootComponent()->GetOwner()->GetComponents<USkeletalMeshComponent>(Components);
		for (int32 i = 0; i < Components.Num(); i++) {
			Animation_01 = Cast<UAnimInstance>(Components[i]->GetAnimInstance());
			if (Animation_01 != nullptr) SetAnimationVars_01(); 
		}
	}

	UE_LOG(LogTemp, Warning, TEXT(">>Debug: ---- SetupValues: End"));

	/* find and check infividual boolien variables from blueprint
	UBoolProperty* Bool_01 = FindField<UBoolProperty>(Animation_01->GetClass(), TEXT("anim_example_variable"));
	if (Bool_01){
		if (Bool_01->GetPropertyValue(Bool_01->ContainerPtrToValuePtr<bool>(Animation_01)) == false) 	UE_LOG(LogTemp, Warning, TEXT(">>Debug: -- FALSE"));
		if (Bool_01->GetPropertyValue(Bool_01->ContainerPtrToValuePtr<bool>(Animation_01)) == true) 	UE_LOG(LogTemp, Warning, TEXT(">>Debug: -- TRUE"));
	}
	*/

}

// map animation blueprint variables to this c++ class
void UAnimManager_01::SetAnimationVars_01()
{
	// Default Motion variables,
	anim_state_switch = FindField<UBoolProperty>(Animation_01->GetClass(), TEXT("anim_state_switch"));
	anim_idel =			FindField<UBoolProperty>(Animation_01->GetClass(), TEXT("anim_idel"));
	anim_clapping =		FindField<UBoolProperty>(Animation_01->GetClass(), TEXT("anim_clapping"));

	// Random Motion variables 
	anim_phone_01 =		FindField<UBoolProperty>(Animation_01->GetClass(), TEXT("anim_phone_01"));
	anim_phone_02 =		FindField<UBoolProperty>(Animation_01->GetClass(), TEXT("anim_phone_02"));
	anim_random_01 =	FindField<UBoolProperty>(Animation_01->GetClass(), TEXT("anim_random_01"));
	//UE_LOG(LogTemp, Warning, TEXT(">>Debug: --oooo-- >"));
	ValidateAnimVars_01(); // validate animation blueprint variable 
}

// validate variables which are maped from animation blueprint
void UAnimManager_01::ValidateAnimVars_01()
{
	if (
			(anim_state_switch != nullptr) &&
			(anim_idel != nullptr) &&
			(anim_clapping != nullptr) &&
			(anim_phone_01 != nullptr) &&
			(anim_phone_02 != nullptr) &&
			(anim_random_01 != nullptr)			
		) 
	{
		AnimVars_Valid = true;
		UE_LOG(LogTemp, Warning, TEXT(">>Debug: ---AnimBlueprint variables -----Alle OK -- >"));
		
		TriggerValue_01_Buffer = GetTrigger();
		
		anim_state_switch->SetPropertyValue_InContainer(Animation_01, false);	// using "anim_state_B" from animation blueprint
		anim_random_01->SetPropertyValue_InContainer(Animation_01, false);		// disable random animations at start

	}
}





// ---------------------------------------------------------------
// action --------------------------------------------------------

// get trigget value
int UAnimManager_01::GetTrigger(){
	// grab value in AnimMeter
	TriggerValue_01 = FMath::GetMappedRangeValueClamped(
		FVector2D(0, 60),
		FVector2D(0, 3),
		(*(AnimMeter_Value->ContainerPtrToValuePtr<float>(AnimMeter_01)) + 10)
	);

	//UE_LOG(LogTemp, Warning, TEXT(" - vv - %d -- %f"), TriggerValue_01, *(AnimMeter_Value->ContainerPtrToValuePtr<float>(AnimMeter_01)));
	return TriggerValue_01;
}

// animate 
void UAnimManager_01::Animate_01(int triggerValue){
	if (triggerValue == 0) {
		anim_idel->SetPropertyValue_InContainer(Animation_01, false);
		anim_clapping->SetPropertyValue_InContainer(Animation_01, false);
	}

	if (triggerValue == 1) {
		anim_idel->SetPropertyValue_InContainer(Animation_01, true);
		anim_clapping->SetPropertyValue_InContainer(Animation_01, false);
	}

	if (triggerValue == 2) {
		anim_idel->SetPropertyValue_InContainer(Animation_01, true);
		anim_clapping->SetPropertyValue_InContainer(Animation_01, true);
	}
	UE_LOG(LogTemp, Warning, TEXT(">>Debug: --- Change -- >"));
	Animate_Random_01();
}

// animate random
void UAnimManager_01::Animate_Random_01(){
	if (FMath::RandBool()) {
		UE_LOG(LogTemp, Warning, TEXT(">>Debug: --- Random Active-- >"));
		
		anim_random_01->SetPropertyValue_InContainer(Animation_01, true); // activate random flags
		bool b = FMath::RandBool();
		anim_phone_01->SetPropertyValue_InContainer(Animation_01, b);
		anim_phone_02->SetPropertyValue_InContainer(Animation_01, !b);
		
	}else {
		UE_LOG(LogTemp, Warning, TEXT(">>Debug: --- Random Stop -- >"));
		
		anim_random_01->SetPropertyValue_InContainer(Animation_01, false); // de-activate random flags
		
	}
}



// ---------------------------------------------------------------
// Called every frame
void UAnimManager_01::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Active && AnimVars_Valid) {
		if (TriggerValue_01_Buffer != GetTrigger()) {	// check for change in animTrigger
			TriggerValue_01_Buffer = GetTrigger();		// buffer value from animTrigger
			Animate_01(TriggerValue_01_Buffer);			// animate character on chnages
		}
	}

}

