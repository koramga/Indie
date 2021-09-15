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
	EPawnAnimType	m_PawnAnimType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	float				m_Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	float				m_Angle;

public :
	virtual void SetPawnAnimType(EPawnAnimType PawnAnimType);
	void SetAngle(float Angle);
	void SetSpeed(float Speed);

public :
	virtual EPawnAnimType GetPawnAnimType() const;
	float GetAngle() const;
	float GetSpeed() const;

public :
	virtual void AddEndAnimationState(EPawnAnimType AnimType);
	virtual void SetEndAnimationState(EPawnAnimType AnimType, EPawnAnimType NextAnimType = EPawnAnimType::Idle);
	virtual void ResetAnimationState(EPawnAnimType AnimType);
	virtual void SetAnimationStateEndCount(EPawnAnimType AnimType, int32 Count);
};
