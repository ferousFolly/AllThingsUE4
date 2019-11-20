// Fill out your copyright notice in the Description page of Project Settings.

#include "LightTrigger_03.h"


// Sets default values
ALightTrigger_03::ALightTrigger_03()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// set up Box Collision ( in BP -> creat, drag and drop to root, resize)
	Frame_Box = CreateDefaultSubobject<UBoxComponent>("Element Box");
	RootComponent = Frame_Box;

	// add collision event functions  ( in BP , choose Box, add events on BeginOverlap and EndOverlap)
	Frame_Box->OnComponentBeginOverlap.AddDynamic(this, &ALightTrigger_03::OnEntering);
	Frame_Box->OnComponentEndOverlap.AddDynamic(this, &ALightTrigger_03::OnLeaving);

}

// Called when the game starts or when spawned
void ALightTrigger_03::BeginPlay()
{
	Super::BeginPlay();

	// get player character
	CollisionCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);

	// get lights from stage
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpotLight::StaticClass(), Lights); // get spot lights into an array
	/*
	check: https://answers.unrealengine.com/questions/289453/get-all-actors-of-class-in-c.html
	and: https://answers.unrealengine.com/questions/605880/getworld-pointer-to-incomplete-class-type-is-not-a.html
	*/
	
}

// on collision with ANY visitor object
void ALightTrigger_03::OnEntering(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	
	/*
	// get all properties of OtherActor, only if OtherActor is equal to player character
	if (OtherActor == CollisionCharacter) {
		for (TFieldIterator<UProperty> PropIt(OtherActor->GetClass()); PropIt; ++PropIt) {
			UProperty* Property = *PropIt;
			// print all public properties of other actor
			UE_LOG(LogTemp, Warning, TEXT(" - PROPERTIES -- OtherActor --- %s"), *(Property->GetName()));
		}
	}
	*/

	// check if character has a property called "Special" 
	UProperty* SpecialProperty = OtherActor->GetClass()->FindPropertyByName(TEXT("Special"));
	if (SpecialProperty) {
		bool* ptrValue = SpecialProperty->ContainerPtrToValuePtr<bool>(OtherActor); // get property as bool 

		/*
		// use boolean pointer property, to make normal boolean
		if (ptrValue) {
			bool temp = *ptrValue;	// convert to normal boolean variable
			if (temp) {
				UE_LOG(LogTemp, Warning, TEXT(" - iekt --using normal bool- %s"), *(OtherActor->GetName()));
				LightOperator();
			}
		}
		*/
		
		// use boolean pointer property, directly
		if (ptrValue) {
			UE_LOG(LogTemp, Warning, TEXT(" - iekt --using actual bool- %s"), *(OtherActor->GetName()));
			LightOperator();
		}

	}

}

// on leaving with ANY visitor object
void ALightTrigger_03::OnLeaving(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
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

// Called every frame
void ALightTrigger_03::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALightTrigger_03::LightOperator(){
	for (AActor* LightActor : Lights) {
		ASpotLight* s = Cast<ASpotLight>(LightActor); // cast spotlight as an actors from Lights array
		
		if (s != nullptr) s->SpotLightComponent->SetVisibility(LightsVisibility);
		UE_LOG(LogTemp, Warning, TEXT(" -            light:  %s"), *(LightActor->GetName()));
	}
	
	UE_LOG(LogTemp, Warning, TEXT(" - light checked ---"));
	LightsVisibility = !LightsVisibility; // change light visibility flag at the end


	/*
	check:
	HARRISON MCGUIRE - C++ Examples for UE
	https://unrealcpp.com/
	https://www.youtube.com/c/HarrisonMcGuire
	*/
}

