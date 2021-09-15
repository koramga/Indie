// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../../GameInfo.h"
#include "PawnAnimState.h"
#include "PawnAnimCombo.h"
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
	int32				m_AttackType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	int32				m_ComboType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	UPawnAnimState*		m_PawnAnimState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"));
	UPawnAnimCombo*		m_PawnAnimCombo;

public:
	virtual void NativeInitializeAnimation();
	virtual void NativeUpdateAnimation(float DeltaSeconds);

private :
	UFUNCTION()
	void AnimNotify_EnableCombo();
	
	UFUNCTION()
	void AnimNotify_DisableCombo();

protected :
	virtual void UpdatePawnType(EPawnAnimType BeforePawnAnimType, EPawnAnimType AfterPawnAnimType);
	virtual void UpdateAnimCombo(UPawnAnimCombo* PawnAnimCombo, int32 AttackType, int32 ComboType);

public :
	virtual void SetPawnAnimType(EPawnAnimType PawnAnimType, bool EndAnimationStateOffset = false);
	void SetAngle(float Angle);
	void SetSpeed(float Speed);
	void SetAttackType(int32 AttackType);
	void SetComboType(int32 ComboType);

public :
	virtual EPawnAnimType GetPawnAnimType() const;
	float GetAngle() const;
	float GetSpeed() const;
	int32 GetAttackType() const;
	int32 GetComboType() const;

public :
	virtual void AddEndAnimationState(EPawnAnimType PawnAnimType);
	virtual void SetEndAnimationState(EPawnAnimType PawnAnimType, EPawnAnimType NextPawnAnimType = EPawnAnimType::Idle);
	virtual void ResetAnimationState(EPawnAnimType PawnAnimType);
	virtual void SetAnimationStateEndCount(EPawnAnimType PawnAnimType, int32 Count);
};
