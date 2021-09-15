// Fill out your copyright notice in the Description page of Project Settings.


#include "MannequinAnimInstance.h"

//

UMannequinAnimInstance::UMannequinAnimInstance()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> Combo01MontageAsset(TEXT("AnimMontage'/Game/Indie/Pawn/Player/Mannequin/Animation/HeavyLancer/MTMannequinHeavyLancerCombo1.MTMannequinHeavyLancerCombo1'"));

	if (Combo01MontageAsset.Succeeded())
		m_HeavyLancerComboMontage.Add(Combo01MontageAsset.Object);

	m_StartCombo = false;
}

void UMannequinAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
}

void UMannequinAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}

void UMannequinAnimInstance::UpdatePawnType(EPawnAnimType BeforePawnAnimType, EPawnAnimType AfterPawnAnimType)
{
	Super::UpdatePawnType(BeforePawnAnimType, AfterPawnAnimType);
}

void UMannequinAnimInstance::UpdateAnimCombo(UPawnAnimCombo* PawnAnimCombo, int32 AttackType, int32 ComboType)
{
	PawnAnimCombo->SetAnimMontage(m_HeavyLancerComboMontage[0], 3);
}