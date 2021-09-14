// Fill out your copyright notice in the Description page of Project Settings.


#include "HeavyLancerCharacter.h"

AHeavyLancerCharacter::AHeavyLancerCharacter()
{
	//static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("SkeletalMesh'/Game/Haena/Meshes/Character/Combined/SK_Haena_Combined_01.SK_Haena_Combined_01'"));

	if (MeshAsset.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(MeshAsset.Object);
	}

	//static ConstructorHelpers::FClassFinder<UAnimInstance> AnimAssert(TEXT("AnimBlueprint'/Game/Indie/Pawn/Player/HeavyLancer/Animation/Mannequin/HeavyLancerAnimation.HeavyLancerAnimation_C'"));
	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimAssert(TEXT("AnimBlueprint'/Game/Indie/Pawn/Player/HeavyLancer/Haena/Animation/Heana_HeavyLancerAnimation.Heana_HeavyLancerAnimation_C'"));

	if (AnimAssert.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(AnimAssert.Class);
	}
}

void AHeavyLancerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AHeavyLancerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}