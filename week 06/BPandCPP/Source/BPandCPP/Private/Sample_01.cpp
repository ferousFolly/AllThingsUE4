// Fill out your copyright notice in the Description page of Project Settings.

#include "Sample_01.h"


// Sets default values
ASample_01::ASample_01()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// set up Box Collision ( in BP -> creat, drag and drop to root, resize)
	Frame_Box = CreateDefaultSubobject<UBoxComponent>("Element Box");
	RootComponent = Frame_Box;

	// add collision event functions  ( in BP , choose Box, add events on BeginOverlap and EndOverlap)
	Frame_Box->OnComponentBeginOverlap.AddDynamic(this, &ASample_01::OnCollision_Start);
	
	//////------------------ text
	///////////////////////// FObjectFinder method
	infoText = CreateDefaultSubobject<UTextRenderComponent>(FName("name"));
	infoText->AttachTo(Frame_Box);
	infoText->SetRelativeLocation(FVector(.0f, -40.0f, 75.0f));
	infoText->SetRelativeRotation(FRotator(.0f, 180.0f, 30.0f));
	infoText->SetXScale(1.0f);
	infoText->SetYScale(1.0f);
	infoText->SetWorldSize(32);
	

}

// Called when the game starts or when spawned
void ASample_01::BeginPlay()
{
	Super::BeginPlay();
	
	infoText->SetText(FText::FromString(infoName));
}

// Called every frame
void ASample_01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASample_01::OnCollision_Start(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	infoText->SetText("Collision Detected");
}

void ASample_01::DestroyItem()
{
	//Destroy();
}

