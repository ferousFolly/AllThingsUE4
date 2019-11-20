// Fill out your copyright notice in the Description page of Project Settings.

#include "LightTrigger_01.h"


// Sets default values
ALightTrigger_01::ALightTrigger_01()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// set up Box Collision ( in BP -> creat, drag and drop to root)
	Frame_Box = CreateDefaultSubobject<UBoxComponent>("Element Box");
	RootComponent = Frame_Box;

	// add collision event functions  ( in BP , choose Box, add events on BeginOverlap and EndOverlap)
	Frame_Box->OnComponentBeginOverlap.AddDynamic(this, &ALightTrigger_01::OnEntering);
	Frame_Box->OnComponentEndOverlap.AddDynamic(this, &ALightTrigger_01::OnLeaving);
}

// Called when the game starts or when spawned
void ALightTrigger_01::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightTrigger_01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// on collision with ANY visitor object
void ALightTrigger_01::OnEntering(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT(" - iekt --- %s"), *(OtherActor->GetName()));
	LightOperator();

	/*
	LOG in Unreal Engine
	https://unrealcpp.com/debug-logging/
	https://wiki.unrealengine.com/Logs,_Printing_Messages_To_Yourself_During_Runtime
	*/


}

// on leaving with ANY visitor object
void ALightTrigger_01::OnLeaving(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT(" - dakt --- %s"), *(OtherActor->GetName()));
	LightOperator();
}

void ALightTrigger_01::LightOperator(){
	for (ASpotLight* LightObject : Lights){
		
		LightObject->SpotLightComponent->SetVisibility(LightsVisibility);
		/*
		check : http://api.unrealengine.com/INT/API/Runtime/Engine/Engine/ASpotLight/index.html
		and find and check SpotLightComponent , it is a variable, it is public and have couple of 
		settings (functions & variables to use)... try
		Actor->SpotLightComponent->SetIntensity(3000.0f);
		 
		 and then try 
		Actor->SpotLightComponent->SetIntensity(3000000.0f); --------- > for this value , try to set camera 
		between your character and spoptlights during play time.. it showes kind of art effect 
		which can be switched and customized here in C++ mode with much better performance than blueprint. 
		*/
	}
	UE_LOG(LogTemp, Warning, TEXT(" - light checked ---"));
	LightsVisibility = !LightsVisibility; // change light visibility flag at the end
}

