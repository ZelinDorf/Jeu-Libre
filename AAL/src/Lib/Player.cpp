#include "pch.h"
#include "Player.h"
#include "InputSystem.h"


Player::~Player()
{
	Destroy();
}

void Player::Init(int _class)
{
	
	//cpuEngine.GetCamera()->transform.SetYPR(0.f, 1.570796f, 0.f);

	m_pEntity = cpuEngine.CreateEntity();
	m_meshPlayer.CreateSphere(m_playerSize, 20, 20, CPU_WHITE, CPU_WHITE);
	m_pEntity->pMesh = &m_meshPlayer;
	m_pEntity->transform.pos = m_position;
	m_pEntity->transform.SetYPR(0.0f, 0.0f, 0.0f);
	

	m_position = XMFLOAT3(0.0f, 0.0f, 0.0f);
	m_speed = m_baseSpeed;
	m_crouchedSpeed *= m_speed;

	//mAttackRefreshDuration = mCurrentWeapon->GetBasicAttackRefreshTime();

	m_playerClass = _class;

}

void Player::Update(float dt)
{
	m_pEntity->transform.pos = m_position;

	XMFLOAT3 m_camPos = XMFLOAT3(m_position.x + 2.f, m_position.y + 2.f, m_position.z - 4.f);
	//cpuEngine.GetCamera()->transform.SetYPR(0.f, .2f, 0.f);
	cpuEngine.GetCamera()->transform.pos = m_camPos;

	m_pEntity->transform.dir = cpuEngine.GetCamera()->transform.dir;
	SetWeaponDirection();

	HandleInput(dt);
	RefreshAttack(dt);
}

void Player::HandleInput(float dt)
{
	if (m_isActive)
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
		m_isJumping = true;
	}

	if (InputSystem::IsKeyDown(LCTRL))
	{
		Crouch();
		m_isCrouched = true;
	}
	else
	{
		Uncrouch();
		m_isCrouched = false;
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
	if (m_currentWeapon == nullptr)
		return;

	m_currentWeapon->SetDirection(m_pEntity->transform.dir);
}

void Player::SetPosition(XMFLOAT3 _position)
{
	m_position = _position;
}

XMFLOAT3 Player::GetPosition()
{
	return m_position;
}

void Player::MouseInput()
{
}

void Player::MoveForward(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	m_position.x += m_xDir * m_speed * dt;
	m_position.z += m_zDir * m_speed * dt;
}

void Player::MoveBackward(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	m_position.x -= m_xDir * m_speed * dt;
	m_position.z -= m_zDir * m_speed * dt;
}

void Player::StrafeLeft(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	m_position.x -= m_zDir * m_speed * dt;
	m_position.z += m_xDir * m_speed * dt;
}

void Player::StrafeRight(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	m_position.x += m_zDir * m_speed * dt;
	m_position.z -= m_xDir * m_speed * dt;
}

void Player::Jump()
{

}

void Player::Crouch()
{
	m_speed = m_crouchedSpeed;
}
void Player::Uncrouch()
{
	m_speed = m_baseSpeed;
}

void Player::WeaponEquiped(float dt)
{
	m_weaponEquipement += dt;
	if (m_weaponEquipement > m_weaponEquipementDuration)
	{
		m_isWeaponEquiped = true;
	}
}

void Player::Attack()
{
	if (m_currentWeapon == nullptr)
		return;

	if (m_attackRefreshing < m_attackRefreshDuration || m_isWeaponEquiped == false)
		return;

	m_currentWeapon->BasicAttack();

	m_attackRefreshing = 0.f;
}

void Player::RefreshAttack(float dt)
{
	m_attackRefreshing += dt;
}

void Player::SwapWeapon()
{
	if (m_currentWeapon == nullptr)
		return;

	if (m_attackRefreshing < m_attackRefreshDuration)
		return;

	if (m_currentWeapon == m_weapon1)
	{
		m_currentWeapon = m_weapon2;
	}
	else if (m_currentWeapon == m_weapon2)
	{
		m_currentWeapon = m_weapon1;
	}

	m_isWeaponEquiped = false;
	m_weaponEquipement = 0.0f;
	m_weaponEquipementDuration = m_currentWeapon->GetPulloutTime();
	
	m_attackRefreshDuration = m_currentWeapon->GetBasicAttackRefreshTime();
}

void Player::Inventory()
{
	if (m_isInventoryOpened == false)
	{
		m_isInventoryOpened = true;
	}
		
	else
	{
		m_isInventoryOpened = false;
	}
		
}

void Player::UpgradesPage()
{
	if (m_isUpgradePageOpened == false)
	{
		m_isUpgradePageOpened = true;
	}

	else
	{
		m_isUpgradePageOpened = false;
	}
}