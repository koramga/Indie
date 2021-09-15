// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../GameInfo.h"
#include "PawnAnimState.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	UPawnAnimState*		m_PawnAnimState;

public:
	virtual void NativeInitializeAnimation();
	virtual void NativeUpdateAnimation(float DeltaSeconds);

public :
	virtual void SetPawnAnimType(EPawnAnimType PawnAnimType, bool EndAnimationStateOffset = false);
	void SetAngle(float Angle);
	void SetSpeed(float Speed);

public :
	virtual EPawnAnimType GetPawnAnimType() const;
	float GetAngle() const;
	float GetSpeed() const;

public :
	virtual void AddEndAnimationState(EPawnAnimType PawnAnimType);
	virtual void SetEndAnimationState(EPawnAnimType PawnAnimType, EPawnAnimType NextPawnAnimType = EPawnAnimType::Idle);
	virtual void ResetAnimationState(EPawnAnimType PawnAnimType);
	virtual void SetAnimationStateEndCount(EPawnAnimType PawnAnimType, int32 Count);
};
