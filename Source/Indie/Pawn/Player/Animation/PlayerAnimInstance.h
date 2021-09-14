// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../../GameInfo.h"
#include "../../Animation/PawnAnimInstance.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class INDIE_API UPlayerAnimInstance : public UPawnAnimInstance
{
	GENERATED_BODY()

public:
	UPlayerAnimInstance();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	EPlayerWeaponType	m_PlayerWeaponType;

public :
	void SetPlayerWeaponType(EPlayerWeaponType WeaponType);
	EPlayerWeaponType GetPlayerWeaponType() const;
	
};
