#include "pch.h"
#include "Player.h"
#include "InputSystem.h"


void Player::Init(int _class)
{
	
	//cpuEngine.GetCamera()->transform.SetYPR(0.f, 1.570796f, 0.f);

	m_pEntity = cpuEngine.CreateEntity();
	m_meshPlayer.CreateSphere(m_PlayerSize, 20, 20, CPU_WHITE, CPU_WHITE);
	m_pEntity->pMesh = &m_meshPlayer;
	m_pEntity->transform.pos = m_Position;
	m_pEntity->transform.SetYPR(0.0f, 0.0f, 0.0f);
	

	m_Position = XMFLOAT3(0.0f, 0.0f, 0.0f);
	m_Speed = m_BaseSpeed;
	m_CrouchedSpeed *= m_Speed;

	//mAttackRefreshDuration = mCurrentWeapon->GetBasicAttackRefreshTime();

	m_PlayerClass = _class;

}

void Player::Update(float dt)
{
	m_pEntity->transform.pos = m_Position;

	XMFLOAT3 m_camPos = XMFLOAT3(m_Position.x + 2.f, m_Position.y + 2.f, m_Position.z - 4.f);
	//cpuEngine.GetCamera()->transform.SetYPR(0.f, .2f, 0.f);
	cpuEngine.GetCamera()->transform.pos = m_camPos;

	m_pEntity->transform.dir = cpuEngine.GetCamera()->transform.dir;
	SetWeaponDirection();

	HandleInput(dt);
	RefreshAttack(dt);
}

void Player::HandleInput(float dt)
{
	if (m_IsActive)
		return;

	InputSystem::LockMouseCursor();

	

	if (InputSystem::IsKeyPressed(Z))
		MoveForward(dt);
	if (InputSystem::IsKeyPressed(S))
		MoveBackward(dt);
	if (InputSystem::IsKeyPressed(Q))
		StrafeLeft(dt);
	if (InputSystem::IsKeyPressed(D))
		StrafeRight(dt);

	if (InputSystem::IsKeyPressed(C))
		cpuEngine.GetCamera()->transform.AddYPR(-1.5f * dt);
	if (InputSystem::IsKeyPressed(V))
		cpuEngine.GetCamera()->transform.AddYPR(+1.5f * dt);


	XMFLOAT3 m_camOffset = XMFLOAT3(2.f * cpuEngine.GetCamera()->transform.dir.x, 0.f, 4.f * cpuEngine.GetCamera()->transform.dir.z);
	if (InputSystem::IsKeyDown(T))


	if (InputSystem::IsKeyPressed(SPACEBAR))
	{
		Jump();
		m_IsJumping = true;
	}

	if (InputSystem::IsKeyDown(LCTRL))
	{
		Crouch();
		m_IsCrouched = true;
	}
	else
	{
		Uncrouch();
		m_IsCrouched = false;
	}

	if (InputSystem::IsMouseButtonPressed(LEFT_MOUSE))
	{
		Attack();
	}


	if (InputSystem::IsKeyPressed(F))
		SwapWeapon();

	if (InputSystem::IsKeyPressed(E))
		Inventory();

	if (InputSystem::IsKeyPressed(A))
		UpgradesPage();
}

void Player::Destroy()
{
	m_pEntity = cpuEngine.Release(m_pEntity);
}

void Player::SetWeaponDirection()
{
	if (m_CurrentWeapon == nullptr)
		return;

	m_CurrentWeapon->SetDirection(m_pEntity->transform.dir);
}

void Player::SetPosition(XMFLOAT3 _position)
{
	m_Position = _position;
}

XMFLOAT3 Player::GetPosition()
{
	return m_Position;
}

void Player::MouseInput()
{
}

void Player::MoveForward(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	m_Position.x += m_xDir * m_Speed * dt;
	m_Position.z += m_zDir * m_Speed * dt;
}

void Player::MoveBackward(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	m_Position.x -= m_xDir * m_Speed * dt;
	m_Position.z -= m_zDir * m_Speed * dt;
}

void Player::StrafeLeft(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	m_Position.x -= m_zDir * m_Speed * dt;
	m_Position.z += m_xDir * m_Speed * dt;
}

void Player::StrafeRight(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	m_Position.x += m_zDir * m_Speed * dt;
	m_Position.z -= m_xDir * m_Speed * dt;
}

void Player::Jump()
{

}

void Player::Crouch()
{
	m_Speed = m_CrouchedSpeed;
}
void Player::Uncrouch()
{
	m_Speed = m_BaseSpeed;
}

void Player::WeaponEquiped(float dt)
{
	m_WeaponEquipement += dt;
	if (m_WeaponEquipement > m_WeaponEquipementDuration)
	{
		m_IsWeaponEquiped = true;
	}
}

void Player::Attack()
{
	if (m_CurrentWeapon == nullptr)
		return;

	if (m_AttackRefreshing < m_AttackRefreshDuration || m_IsWeaponEquiped == false)
		return;

	m_CurrentWeapon->BasicAttack();

	m_AttackRefreshing = 0.f;
}

void Player::RefreshAttack(float dt)
{
	m_AttackRefreshing += dt;
}

void Player::SwapWeapon()
{
	if (m_CurrentWeapon == nullptr)
		return;

	if (m_AttackRefreshing < m_AttackRefreshDuration)
		return;

	if (m_CurrentWeapon == m_Weapon1)
	{
		m_CurrentWeapon = m_Weapon2;
	}
	else if (m_CurrentWeapon == m_Weapon2)
	{
		m_CurrentWeapon = m_Weapon1;
	}

	m_IsWeaponEquiped = false;
	m_WeaponEquipement = 0.0f;
	m_WeaponEquipementDuration = m_CurrentWeapon->GetPulloutTime();
	
	m_AttackRefreshDuration = m_CurrentWeapon->GetBasicAttackRefreshTime();
}

void Player::Inventory()
{
	if (m_IsInventoryOpened == false)
	{
		m_IsInventoryOpened = true;
	}
		
	else
	{
		m_IsInventoryOpened = false;
	}
		
}

void Player::UpgradesPage()
{
	if (m_IsUpgradePageOpened == false)
	{
		m_IsUpgradePageOpened = true;
	}

	else
	{
		m_IsUpgradePageOpened = false;
	}
}