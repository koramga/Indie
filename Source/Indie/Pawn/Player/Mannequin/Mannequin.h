// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../PlayerCharacter.h"
#include "Mannequin.generated.h"

/**
 * 
 */
UCLASS()
class INDIE_API AMannequin : public APlayerCharacter
{
	GENERATED_BODY()

public :
	AMannequin();

protected :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	USkeletalMesh*	m_MaleSkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	USkeletalMesh*	m_FemalSkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	EGender			m_Gender;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
