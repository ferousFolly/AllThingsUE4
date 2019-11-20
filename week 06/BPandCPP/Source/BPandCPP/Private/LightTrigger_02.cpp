// Fill out your copyright notice in the Description page of Project Settings.

#include "LightTrigger_02.h"


// Sets default values
ALightTrigger_02::ALightTrigger_02()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// set up Box Collision ( in BP -> creat, drag and drop to root, resize)
	Frame_Box = CreateDefaultSubobject<UBoxComponent>("Element Box");
	RootComponent = Frame_Box;

	// add collision event functions  ( in BP , choose Box, add events on BeginOverlap and EndOverlap)
	Frame_Box->OnComponentBeginOverlap.AddDynamic(this, &ALightTrigger_02::OnEntering);
	Frame_Box->OnComponentEndOverlap.AddDynamic(this, &ALightTrigger_02::OnLeaving);

}

// Called when the game starts or when spawned
void ALightTrigger_02::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightTrigger_02::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// on collision with ANY visitor object
void ALightTrigger_02::OnEntering(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	/*
	// get all properties of OtherActor 
	for (TFieldIterator<UProperty> PropIt(OtherActor->GetClass()); PropIt; ++PropIt) {
		UProperty* ItemProperty = *PropIt;
		// print all public properties of other actor 
		UE_LOG(LogTemp, Warning, TEXT(" - PROPERTIES -- OtherActor --- %s"), *(ItemProperty->GetName()));
	}
	*/

	// check if character has a property called "Special" 
	UProperty* SpecialProperty = OtherActor->GetClass()->FindPropertyByName(TEXT("Special")); 
	if (SpecialProperty) {
		bool* ptrValue = SpecialProperty->ContainerPtrToValuePtr<bool>(OtherActor); // get property as bool 
		
		// use boolean pointer property, to make boolean varialbe
		if (ptrValue) {
			bool temp = *ptrValue;	// convert to normal boolean variable
			if (temp) {
				UE_LOG(LogTemp, Warning, TEXT(" - iekt --using normal bool- %s"), *(OtherActor->GetName()));
				LightOperator();
			}
		}

		/*
		// use boolean pointer property, directly
		if (ptrValue) {
			if (*ptrValue) {
				UE_LOG(LogTemp, Warning, TEXT(" - iekt --using actual bool- %s"), *(OtherActor->GetName()));
				LightOperator();
			}
		}
		*/
		
	}

}

// on leaving with ANY visitor object
void ALightTrigger_02::OnLeaving(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{

	UProperty* SpecialProperty = OtherActor->GetClass()->FindPropertyByName(TEXT("Special"));
	if (SpecialProperty) {
		bool* ptrValue = SpecialProperty->ContainerPtrToValuePtr<bool>(OtherActor); // get property as bool 
		if (ptrValue) {
			bool temp = *ptrValue;
			if (temp) {
				UE_LOG(LogTemp, Warning, TEXT(" - dakt --- %s"), *(OtherActor->GetName()));
				LightOperator();
			}
		}
	}
}

void ALightTrigger_02::LightOperator(){
	for (ASpotLight* Actor : Lights) {
		Actor->SpotLightComponent->SetVisibility(LightsVisibility);
	}
	UE_LOG(LogTemp, Warning, TEXT(" - light checked ---"));
	LightsVisibility = !LightsVisibility; // change light visibility flag at the end
}

