// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "../../../../GameInfo.h"
#include "../../Animation/PlayerAnimInstance.h"
#include "MannequinAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class INDIE_API UMannequinAnimInstance : public UPlayerAnimInstance
{
	GENERATED_BODY()

protected :
	TArray<UAnimMontage*>	m_HeavyLancerComboMontage;
	bool					m_StartCombo;
	
public :
	UMannequinAnimInstance();

public:
	virtual void NativeInitializeAnimation();
	virtual void NativeUpdateAnimation(float DeltaSeconds);

private :
	virtual void UpdatePawnType(EPawnAnimType BeforePawnAnimType, EPawnAnimType AfterPawnAnimType) override;
	virtual void UpdateAnimCombo(UPawnAnimCombo* PawnAnimCombo, int32 AttackType, int32 ComboType) override;

protected :
};
