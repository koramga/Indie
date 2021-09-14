// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnCopyPoseAnimInstance.h"


void UPawnCopyPoseAnimInstance::SetSrcSkeletalMeshComponent(USkeletalMeshComponent* SrcMeshComponent)
{
	m_SrcMeshComponent = SrcMeshComponent;
}

USkeletalMeshComponent* UPawnCopyPoseAnimInstance::GetSrcSkeletalMeshComponent() const
{
	return m_SrcMeshComponent;
}