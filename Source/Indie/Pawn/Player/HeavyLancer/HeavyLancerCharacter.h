// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../../GameInfo.h"
#include "../PlayerCharacter.h"
#include "HeavyLancerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class INDIE_API AHeavyLancerCharacter : public APlayerCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHeavyLancerCharacter();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	UStaticMeshComponent* m_Shield;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	UStaticMeshComponent* m_Lance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
