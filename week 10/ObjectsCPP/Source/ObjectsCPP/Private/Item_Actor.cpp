// Fill out your copyright notice in the Description page of Project Settings.


#include "Item_Actor.h"

// Sets default values
AItem_Actor::AItem_Actor() : value_01(12), value_02(44) // value_01(12), value_02(value_01) --> value_02 = value_01 ->12
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem_Actor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int AItem_Actor::static_int_01 = 4;
