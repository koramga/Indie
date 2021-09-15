// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnAnimInstance.h"

UPawnAnimInstance::UPawnAnimInstance()
{
	m_PawnAnimType = EPawnAnimType::Idle;
}

void UPawnAnimInstance::SetPawnAnimType(EPawnAnimType PawnAnimType)
{
	m_PawnAnimType = PawnAnimType;
}

void UPawnAnimInstance::SetAngle(float Angle)
{
	m_Angle = Angle;
}

void UPawnAnimInstance::SetSpeed(float Speed)
{
	m_Speed = Speed;
}

EPawnAnimType UPawnAnimInstance::GetPawnAnimType() const
{
	return m_PawnAnimType;
}

float UPawnAnimInstance::GetAngle() const
{
	return m_Angle;
}

float UPawnAnimInstance::GetSpeed() const
{
	return m_Speed;
}

void UPawnAnimInstance::AddEndAnimationState(EPawnAnimType AnimType)
{

}

void UPawnAnimInstance::SetEndAnimationState(EPawnAnimType AnimType, EPawnAnimType NextAnimType)
{

}

void UPawnAnimInstance::ResetAnimationState(EPawnAnimType AnimType)
{

}

void UPawnAnimInstance::SetAnimationStateEndCount(EPawnAnimType AnimType, int32 Count)
{

}