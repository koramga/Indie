// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../GameInfo.h"
#include "Animation/AnimInstance.h"
#include "PawnAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class INDIE_API UPawnAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public :
	UPawnAnimInstance();

protected :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	EPawnCharacterAnimType	m_PawnCharacterAnimType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	float				m_Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	float				m_Angle;

public :
	virtual void SetPawnCharacterAnimType(EPawnCharacterAnimType PawnCharacterAnimType);
	void SetAngle(float Angle);
	void SetSpeed(float Speed);

public :
	virtual EPawnCharacterAnimType GetPawnCharacterAnimType() const;
	float GetAngle() const;
	float GetSpeed() const;
};
