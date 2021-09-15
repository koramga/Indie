// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Animation/PlayerAnimInstance.h"
#include "../../Controller/User/UserPlayerController.h"

APlayerCharacter::APlayerCharacter()
{
	m_Arm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Arm"));
	m_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	m_LHandMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LHandComponent"));
	m_RHandMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RHandComponent"));

	m_LHandMeshComponent->SetupAttachment(GetMesh());
	m_RHandMeshComponent->SetupAttachment(GetMesh());

	//Arm을 Root에 붙여준다.
	m_Arm->SetupAttachment(RootComponent);

	//

	//Camera를 Arm에 붙여준다.
	m_Camera->SetupAttachment(m_Arm);
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	m_PlayerAnimInstance = Cast<UPlayerAnimInstance>(GetMesh()->GetAnimInstance());

	SetPlayerWeaponType(EPlayerWeaponType::Lance);

	//m_PlayerAnimInstance->SetPlayerWeaponType(EPlayerWeaponType::Lance);

	GetCharacterMovement()->MaxWalkSpeed = 100.f;

	m_DilationToggle = false;
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateMoveAnimation();
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForwardBack"), this, &APlayerCharacter::__InputMoveForwardBack);
	PlayerInputComponent->BindAxis(TEXT("MoveLeftRight"), this, &APlayerCharacter::__InputMoveLeftRight);
	PlayerInputComponent->BindAxis(TEXT("AttackTypeKey"), this, &APlayerCharacter::__InputAttackTypeKey);
	PlayerInputComponent->BindAxis(TEXT("ComboTypeKey"), this, &APlayerCharacter::__InputComboTypeKey);

	PlayerInputComponent->BindAction(TEXT("ToggleWalkAndRun"), EInputEvent::IE_Pressed,
		this, &APlayerCharacter::__InputToggleWalkAndRun);

	PlayerInputComponent->BindAction(TEXT("ToggleKey"), EInputEvent::IE_Pressed,
		this, &APlayerCharacter::__InputToggleKey);

	PlayerInputComponent->BindAction(TEXT("DefenceKey"), EInputEvent::IE_Pressed,
		this, &APlayerCharacter::__InputDefenceKey);

	PlayerInputComponent->BindAction(TEXT("AttackKey"), EInputEvent::IE_Pressed,
		this, &APlayerCharacter::__InputAttackKey);
	
	//PlayerInputComponent->BindAction(TEXT("Attack01"), EInputEvent::IE_Pressed,
	//	this, &ADragonCharacter::__Attack01);
	//PlayerInputComponent->BindAction(TEXT("Attack02"), EInputEvent::IE_Pressed,
	//	this, &ADragonCharacter::__Attack02);

}

bool APlayerCharacter::CanMove()
{
	EPawnAnimType PawnAnimType = m_PlayerAnimInstance->GetPawnAnimType();

	if (EPawnAnimType::Idle == PawnAnimType
		|| EPawnAnimType::Walk == PawnAnimType
		|| EPawnAnimType::Run == PawnAnimType)
	{
		return true;
	}

	return false;
}

void APlayerCharacter::UpdateMoveAnimation()
{
	EPawnAnimType PawnAnimType = m_PlayerAnimInstance->GetPawnAnimType();

	if (m_Speed > 0.f)
	{
		if (EPawnAnimType::Idle == PawnAnimType)
		{
			if (EToggleWalkAndRun::Walk == m_ToggleWalkAndRun)
			{
				m_PlayerAnimInstance->SetPawnAnimType(EPawnAnimType::Walk);
			}
			else if (EToggleWalkAndRun::Run == m_ToggleWalkAndRun)
			{
				m_PlayerAnimInstance->SetPawnAnimType(EPawnAnimType::Run);
			}
		}
		else if (EPawnAnimType::Run == PawnAnimType)
		{
			if (EToggleWalkAndRun::Walk == m_ToggleWalkAndRun)
			{
				m_PlayerAnimInstance->SetPawnAnimType(EPawnAnimType::Walk);
			}
		}
		else if (EPawnAnimType::Walk == PawnAnimType)
		{
			if (EToggleWalkAndRun::Run == m_ToggleWalkAndRun)
			{
				m_PlayerAnimInstance->SetPawnAnimType(EPawnAnimType::Run);
			}
		}
	}
	else
	{
		if (EPawnAnimType::Walk == PawnAnimType
			|| EPawnAnimType::Run == PawnAnimType)
		{
			m_PlayerAnimInstance->SetPawnAnimType(EPawnAnimType::Idle);
		}
	}
}

void APlayerCharacter::__InputMoveForwardBack(float Scale)
{
	if (CanMove())
	{
		UpdateMoveAnimation();
		AddMovementInput(GetActorForwardVector(), Scale);
	}
}

void APlayerCharacter::__InputMoveLeftRight(float Scale)
{
	if (CanMove())
	{
		UpdateMoveAnimation();

		if (Scale != 0.f)
		{
			FVector vForwardVector = GetActorForwardVector();

			const FRotator rot(0.f, 90 * Scale, 0.f);

			FVector vResult = rot.RotateVector(vForwardVector);

			//PrintViewport(1.f, FColor::Red, FString::Printf(TEXT("%.2f, %.2f, %.2f : %.2f, %.2f, %.2f"), vForwardVector.X, vForwardVector.Y, vForwardVector.Z, vResult.X, vResult.Y, vResult.Z));

			AddMovementInput(vResult);
		}
	}
}

void APlayerCharacter::__InputAttackTypeKey(float Scale)
{
	m_AttackType = static_cast<int32>(Scale);

	if (m_AttackType > 0)
	{
		m_AttackType--;
	}
}

void APlayerCharacter::__InputComboTypeKey(float Scale)
{
	m_ComboType = static_cast<int32>(Scale);

	if (m_ComboType > 0)
	{
		m_ComboType--;
	}
}

void APlayerCharacter::__InputToggleWalkAndRun()
{
	if (EToggleWalkAndRun::Walk == m_ToggleWalkAndRun)
	{
		m_ToggleWalkAndRun = EToggleWalkAndRun::Run;

		GetCharacterMovement()->MaxWalkSpeed = 600.f;
	}
	else if (EToggleWalkAndRun::Run == m_ToggleWalkAndRun)
	{
		m_ToggleWalkAndRun = EToggleWalkAndRun::Walk;

		GetCharacterMovement()->MaxWalkSpeed = 100.f;
	}

	UpdateMoveAnimation();
}

void APlayerCharacter::__InputToggleKey()
{
	m_DilationToggle = !m_DilationToggle;

	if (m_DilationToggle)
	{
		GetWorldSettings()->SetTimeDilation(1.f);
	}
	else
	{
		GetWorldSettings()->SetTimeDilation(0.5f);
	}
}

void APlayerCharacter::__InputDefenceKey()
{
	//PLAYERCONTROLLER->CameraShake();
	//UGameplayStatics::PlayWorldCameraShake(GetWorld(), )

	m_PlayerAnimInstance->SetPawnAnimType(EPawnAnimType::Defence);
}

void APlayerCharacter::__InputAttackKey()
{
	//PrintViewport(1.f, FColor::Red, TEXT("AttackKey"));
	m_PlayerAnimInstance->SetPawnAnimType(EPawnAnimType::Attack);
}

void APlayerCharacter::AddArmPitch(float Value)
{
	FRotator Rotator = m_Arm->GetRelativeRotation();

	Rotator.Pitch += Value;

	if (Rotator.Pitch > 90.f)
	{
		Rotator.Pitch = 90.f;
	}
	else if (Rotator.Pitch < -90.f)
	{
		Rotator.Pitch = -90.f;
	}

	m_Arm->SetRelativeRotation(Rotator);
}

void APlayerCharacter::SetPlayerWeaponType(EPlayerWeaponType PlayerWeaponType)
{
	FName LSocketName;
	FName RSocketName;

	FString LMeshPath;
	FString RMeshPath;

	m_PlayerAnimInstance->SetPlayerWeaponType(PlayerWeaponType);

	switch (PlayerWeaponType)
	{
	case EPlayerWeaponType::Lance :
		LSocketName = L"HeavyLancerWeaponSocket";
		LMeshPath = TEXT("StaticMesh'/Game/Heavy_Lancer_Set/mesh/SM_lance.SM_lance'");
		RSocketName = L"HeavyLancerShieldSocket";
		RMeshPath = TEXT("StaticMesh'/Game/Weapon_Pack/Mesh/Weapons/Weapons_Kit/SM_Shield.SM_Shield'");
		break;
	}

	UStaticMesh* LMesh = LoadObject<UStaticMesh>(nullptr, *LMeshPath);
	UStaticMesh* RMesh = LoadObject<UStaticMesh>(nullptr, *RMeshPath);

	if (IsValid(LMesh))
	{
		m_LHandMeshComponent->SetStaticMesh(LMesh);
	}

	if (IsValid(RMesh))
	{
		m_RHandMeshComponent->SetStaticMesh(RMesh);
	}

	bool Attach = m_LHandMeshComponent->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, LSocketName);
	m_RHandMeshComponent->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, RSocketName);
}