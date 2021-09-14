// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnAnimInstance.h"

UPawnAnimInstance::UPawnAnimInstance()
{
	m_PawnCharacterAnimType = EPawnCharacterAnimType::Idle;
}

void UPawnAnimInstance::SetPawnCharacterAnimType(EPawnCharacterAnimType PawnCharacterAnimType)
{
	m_PawnCharacterAnimType = PawnCharacterAnimType;
}

void UPawnAnimInstance::SetAngle(float Angle)
{
	m_Angle = Angle;
}

void UPawnAnimInstance::SetSpeed(float Speed)
{
	m_Speed = Speed;
}

EPawnCharacterAnimType UPawnAnimInstance::GetPawnCharacterAnimType() const
{
	return m_PawnCharacterAnimType;
}

float UPawnAnimInstance::GetAngle() const
{
	return m_Angle;
}

float UPawnAnimInstance::GetSpeed() const
{
	return m_Speed;
}