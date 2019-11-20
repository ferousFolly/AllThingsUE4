// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item_Actor_BP.generated.h"

UCLASS()
class OBJECTSCPP_API AItem_Actor_BP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem_Actor_BP();




	// .. your comment for Value_01
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Actor_BP integer")
		int Value_01; 

	//.. your comment for Value_02
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Actor_BP Float")
		float Value_02;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Actor_BP Bool")
		bool Flag_01;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "Actor_BP Actor")
		AActor* Object_01;
	
	// --

	UPROPERTY(BlueprintReadWrite, Category = "Actor_BP A")
		int Value_A;

	UPROPERTY(BlueprintReadOnly, Category = "Actor_BP B")
		int Value_B;
	
	// https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Reference/Properties/Specifiers/index.html  Property Specifiers
	// ---------------------------------------------------------------------------

	// identity of player in level 2 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Actor_BP C", meta = (DisplayName = "Identity in System"))
		int Value_C_01;

	// range of skils on indentity in level 2
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Actor_BP C", meta = (ClampMin = "1", ClampMax = "120"))
		int Value_C_02;

	// https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Reference/Metadata/index.html  Metadata Specifiers

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// void
	void setDistance();
	void setName(FString name);
	void setActive(bool bActive = true);
	//void setActive(bool bActive = true, int value); //	<-- ERROR --------------- !
	//void setActive(int value, bool bActive = true); //	<-- OK
	//void setActive(bool bActive = true, int value = 4); //<-- OK
	//void setActive(int value, bool bActive = true, int set = 4, bool bExtra = false); //	<-- OK

	// return
	int getDistance();
	FString getName(int id);

	// blueprint
	
	// check activation
	UFUNCTION(BlueprintCallable, Category = "Actor_BP Functions")
		bool isActive();
	// check extra 
	UFUNCTION(BlueprintPure, Category = "Actor_BP Functions")
		bool isExtra();





	




};
