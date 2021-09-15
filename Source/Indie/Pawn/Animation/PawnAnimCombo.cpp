// Fill out your copyright notice in the Description page of Project Settings.

#include "PawnAnimCombo.h"
#include "PawnAnimInstance.h"

UPawnAnimCombo::UPawnAnimCombo()
{
	m_EnableUpdateMontage = false;
}

FName UPawnAnimCombo::GetComboStartName(int32 ComboIndex)
{
	return FName(*FString::Printf(TEXT("Combo%02dStart"), ComboIndex));
}

FName UPawnAnimCombo::GetComboEndeName(int32 ComboIndex)
{
	return FName(*FString::Printf(TEXT("Combo%02dEnd"), ComboIndex));
}

void UPawnAnimCombo::SetAnimMontage(UAnimMontage* AnimMontage, int32 ComboCount)
{
	m_ComboMontage = AnimMontage;
	m_ComboCount = ComboCount;
	m_ComboIndex = 1;
	m_EnableUpdateMontage = false;
}

void UPawnAnimCombo::StartAnimMontage(UAnimInstance* AnimInstance)
{
	if (IsValid(m_ComboMontage))
	{
		AnimInstance->Montage_Play(m_ComboMontage);
		AnimInstance->Montage_SetNextSection(UPawnAnimCombo::GetComboStartName(m_ComboIndex), UPawnAnimCombo::GetComboEndeName(m_ComboIndex));
	}
}

void UPawnAnimCombo::UpdateAnimMontage(UAnimInstance* AnimInstance)
{
	if (IsValid(m_ComboMontage))
	{
		m_ComboIndex++;
		AnimInstance->Montage_SetNextSection(UPawnAnimCombo::GetComboStartName(m_ComboIndex - 1), UPawnAnimCombo::GetComboStartName(m_ComboIndex));
		AnimInstance->Montage_SetNextSection(UPawnAnimCombo::GetComboStartName(m_ComboIndex), UPawnAnimCombo::GetComboEndeName(m_ComboIndex));
	}
}

void UPawnAnimCombo::SetEnableUpdateAnimMontage(bool EnableUpdateAnimMontage)
{
	if (IsValid(m_ComboMontage))
	{
		m_EnableUpdateMontage = EnableUpdateAnimMontage;
	}
}

bool UPawnAnimCombo::IsEnableUpdateAnimMontage() const
{
	return m_EnableUpdateMontage;
}