// Fill out your copyright notice in the Description page of Project Settings.


#include "Item_Actor_BP.h"

// Sets default values
AItem_Actor_BP::AItem_Actor_BP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem_Actor_BP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem_Actor_BP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem_Actor_BP::setDistance() {}
void AItem_Actor_BP::setName(FString name) {}
void AItem_Actor_BP::setActive(bool bActive) {}


int AItem_Actor_BP::getDistance() {
	return 0;
}

FString AItem_Actor_BP::getName(int id) {
	return FString();
}

bool AItem_Actor_BP::isActive() {
	return false;
}

bool AItem_Actor_BP::isExtra() {
	return false;
}


