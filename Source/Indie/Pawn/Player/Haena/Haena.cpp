// Fill out your copyright notice in the Description page of Project Settings.


#include "Haena.h"
#include "Animation/HaenaAnimInstance.h"
#include "../../Animation/PawnCopyPoseAnimInstance.h"

AHaena::AHaena()
{
	m_Hair = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Hair"));
	m_Hair->SetupAttachment(GetMesh());

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("SkeletalMesh'/Game/Haena/Meshes/Character/Combined/SK_Haena_Combined_01.SK_Haena_Combined_01'"));

	if (MeshAsset.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimAssert(TEXT("AnimBlueprint'/Game/Indie/Pawn/Player/Haena/Animation/HaenaAnimInstance.HaenaAnimInstance_C'"));

	if (AnimAssert.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(AnimAssert.Class);
	}
	
	if (IsValid(m_Hair))
	{
		static ConstructorHelpers::FObjectFinder<USkeletalMesh> HairAsset(TEXT("SkeletalMesh'/Game/Haena/Meshes/Character/SK_Haena_Hair_Long.SK_Haena_Hair_Long'"));

		if (HairAsset.Succeeded())
		{
			m_Hair->SetSkeletalMesh(HairAsset.Object);
		}

		static ConstructorHelpers::FClassFinder<UAnimInstance> HairAnimAssert(TEXT("AnimBlueprint'/Game/Indie/Pawn/Player/Haena/Animation/HaenaHairAnimInstance.HaenaHairAnimInstance_C'"));

		if (HairAnimAssert.Succeeded())
		{
			m_Hair->SetAnimInstanceClass(HairAnimAssert.Class);
		}
	}
}

void AHaena::BeginPlay()
{
	Super::BeginPlay();

	Cast<UPawnCopyPoseAnimInstance>(m_Hair->GetAnimInstance())->SetSrcSkeletalMeshComponent(GetMesh());
}

void AHaena::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}