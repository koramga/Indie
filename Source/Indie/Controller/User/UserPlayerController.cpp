// Fill out your copyright notice in the Description page of Project Settings.


#include "UserPlayerController.h"
#include "../../Pawn/Player/PlayerCharacter.h"

AUserPlayerController::AUserPlayerController()
{
	static ConstructorHelpers::FClassFinder<UMatineeCameraShake> CameraShake(TEXT("Blueprint'/Game/Indie/Camera/BPCameraShake.BPCameraShake_C'"));

	if (CameraShake.Succeeded())
	{
		m_CameraShake = CameraShake.Class;
	}
}

void AUserPlayerController::BeginPlay()
{
	Super::BeginPlay();

	m_PlayerCharacter = Cast<APlayerCharacter>(GetCharacter());
}

void AUserPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	//Picking();

	if (IsValid(m_PlayerCharacter))
	{
		float fDeltaX, fDeltaY;

		GetInputMouseDelta(fDeltaX, fDeltaY);

		//PrintViewport(1.f, FColor::Red, *FString::Printf(TEXT("%.2f, %.2f"), fDeltaX, fDeltaY));

		if (fDeltaX != 0.f)
		{
			//m_PlayerCharacter->AddArmYaw(fDeltaX);

			//float fYaw = 1.f;
			//
			//if (fDeltaX < 0.f)
			//{
			//	fYaw *= -1.f;
			//}
			//
			//if (IsLookInputIgnored())
			//{
			//	LOG(TEXT("LookInputIgnored.."));
			//}
			//
			//PrintViewport(1.f, FColor::Red, *FString::Printf(TEXT("Yaw : %.2f"), fYaw));

			if (EPawnAnimType::Attack != m_PlayerCharacter->GetPawnAnimType())
			{
				AddYawInput(fDeltaX);
			}
		}

		if (fDeltaY != 0.f)
		{
			m_PlayerCharacter->AddArmPitch(fDeltaY);
			//AddPitchInput(fDeltaY);
		}
	}

	UpdateRotation(DeltaTime);

	//LOG(TEXT("DeltaMouseXY : %.2f, %.2f"), fDeltaX, fDeltaY);
}

void AUserPlayerController::CameraShake()
{
	LOG(TEXT("Call Camera Shake"));
	ClientPlayCameraShake(m_CameraShake);
}

void AUserPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
}