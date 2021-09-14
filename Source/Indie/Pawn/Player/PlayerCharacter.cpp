// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Animation/PlayerAnimInstance.h"

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
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UCharacterMovementComponent* pMovement = GetCharacterMovement();

	FVector vForward = GetActorForwardVector();
	FVector vVelocity = pMovement->Velocity;

	m_Speed = vVelocity.Size();

	if (m_Speed > 0)
	{
		//https://amored8701.tistory.com/132

		vForward.Z = 0.f;
		vVelocity.Z = 0.f;

		vForward.Normalize();
		vVelocity.Normalize();

		float fDot = FVector::DotProduct(vForward, vVelocity);
		float fAcosAngle = FMath::Acos(fDot);
		float fAngle = FMath::RadiansToDegrees(fAcosAngle);

		//if (fDot < -0.3f)
		//{
		//	m_Speed *= -1.f;
		//}

		FVector vCross = FVector::CrossProduct(vForward, vVelocity);

		if (vCross.Z < 0)
		{
			//fAngle *= -1.f;
			fAngle = 360 - fAngle;
		}

		m_Angle = fAngle;

		//PrintViewport(1.f, FColor::Red, FString::Printf(TEXT("%.2f %.2f"), m_Angle, m_Speed));
	}

	if (0.f == m_Speed)
	{
		m_PlayerAnimInstance->SetPawnCharacterAnimType(EPawnCharacterAnimType::Idle);
	}
	else
	{
		if (EToggleWalkAndRun::Walk == m_ToggleWalkAndRun)
		{
			m_PlayerAnimInstance->SetPawnCharacterAnimType(EPawnCharacterAnimType::Walk);
		}
		else if (EToggleWalkAndRun::Run == m_ToggleWalkAndRun)
		{
			m_PlayerAnimInstance->SetPawnCharacterAnimType(EPawnCharacterAnimType::Run);
		}
	}

	m_PlayerAnimInstance->SetSpeed(m_Speed);
	m_PlayerAnimInstance->SetAngle(m_Angle);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForwardBack"), this, &APlayerCharacter::__InputMoveForwardBack);
	PlayerInputComponent->BindAxis(TEXT("MoveLeftRight"), this, &APlayerCharacter::__InputMoveLeftRight);

	PlayerInputComponent->BindAction(TEXT("ToggleWalkAndRun"), EInputEvent::IE_Pressed,
		this, &APlayerCharacter::__InputToggleWalkAndRun);
	//PlayerInputComponent->BindAction(TEXT("Attack01"), EInputEvent::IE_Pressed,
	//	this, &ADragonCharacter::__Attack01);
	//PlayerInputComponent->BindAction(TEXT("Attack02"), EInputEvent::IE_Pressed,
	//	this, &ADragonCharacter::__Attack02);

}

void APlayerCharacter::__InputMoveForwardBack(float Scale)
{
	AddMovementInput(GetActorForwardVector(), Scale);
}

void APlayerCharacter::__InputMoveLeftRight(float Scale)
{
	if (Scale != 0.f)
	{
		FVector vForwardVector = GetActorForwardVector();

		const FRotator rot(0.f, 90 * Scale, 0.f);

		FVector vResult = rot.RotateVector(vForwardVector);

		//PrintViewport(1.f, FColor::Red, FString::Printf(TEXT("%.2f, %.2f, %.2f : %.2f, %.2f, %.2f"), vForwardVector.X, vForwardVector.Y, vForwardVector.Z, vResult.X, vResult.Y, vResult.Z));

		AddMovementInput(vResult);
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