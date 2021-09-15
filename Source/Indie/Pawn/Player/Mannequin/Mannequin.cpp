// Fill out your copyright notice in the Description page of Project Settings.


#include "Mannequin.h"

AMannequin::AMannequin()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MaleMeshAsset(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"));

	if (MaleMeshAsset.Succeeded())
	{
		m_MaleSkeletalMesh = MaleMeshAsset.Object;
		GetMesh()->SetSkeletalMesh(MaleMeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> FeMaleMeshAsset(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/SK_Mannequin_Female.SK_Mannequin_Female'"));

	if (FeMaleMeshAsset.Succeeded())
	{
		m_FemalSkeletalMesh = FeMaleMeshAsset.Object;
	}

	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimAssert(TEXT("AnimBlueprint'/Game/Indie/Pawn/Player/Mannequin/Animation/BPMannequinAnimInstance.BPMannequinAnimInstance_C'"));

	if (AnimAssert.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(AnimAssert.Class);
	}
}

void AMannequin::BeginPlay()
{
	Super::BeginPlay();

	if (EGender::Female == m_Gender)
	{
		GetMesh()->SetSkeletalMesh(m_FemalSkeletalMesh);
	}
}

void AMannequin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}