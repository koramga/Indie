// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnimInstance.h"

UPlayerAnimInstance::UPlayerAnimInstance()
{
	m_PlayerWeaponType = EPlayerWeaponType::None;
}

void UPlayerAnimInstance::SetPlayerWeaponType(EPlayerWeaponType WeaponType)
{
	m_PlayerWeaponType = WeaponType;
}

EPlayerWeaponType UPlayerAnimInstance::GetPlayerWeaponType() const
{
	return m_PlayerWeaponType;
}