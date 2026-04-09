#include "pch.h"
#include "Player.h"
#include "InputSystem.h"


Player::Player()
{
	s_pInstance = this;
}

Player::~Player()
{
	Destroy();
}

void Player::Init(int _class, int _weapon1Class, int _weapon2Class)
{
	JSON_OBJ(JSON_PATH"fox.json", nullptr, s_pInstance->m_pEntity);

	m_speed = m_baseSpeed;
	m_crouchedSpeed *= m_speed;
	s_pInstance->m_entityType = PLAYER;

	m_playerClass = _class;

	m_weapon1 = new Weapon();
	m_weapon1->Init(_weapon1Class, m_playerClass);
	m_weapon1->Equip();
}

void Player::Update(float dt)
{
	m_pEntity->transform.pos = m_position;
	m_weapon1->SetPosition(m_position);

	HandleInput(dt);
	RefreshAttack(dt);
	WeaponEquiped(dt);
}

void Player::HandleInput(float dt)
{
	if (m_isActive)
		return;

	InputSystem::LockMouseCursor();
	InputSystem::HideMouseCursor();

	m_center = { cpuEngine.GetWindow()->GetWidth() / 2.f, cpuEngine.GetWindow()->GetHeight() / 2.f };

	UpdateCamera();

	s_pInstance->m_pEntity->transform.dir = CAMERA->transform.dir;

	if (InputSystem::IsKeyPressed(Z))
		MoveForward(dt);
	if (InputSystem::IsKeyPressed(S))
		MoveBackward(dt);
	if (InputSystem::IsKeyPressed(Q))
		StrafeLeft(dt);
	if (InputSystem::IsKeyPressed(D))
		StrafeRight(dt);

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
	s_pInstance->m_pEntity = cpuEngine.Release(s_pInstance->m_pEntity);
}

Weapon* Player::GetWeapon(int _weapon)
{
	if (_weapon == 1)
	{
		return m_weapon1;
	}
	else if (_weapon == 2)
	{
		return m_weapon2;
	}
}

void Player::SetWeaponDirection()
{
	if (m_currentWeapon == 0)
		return;
	if (m_currentWeapon == 1)
		m_weapon1->SetDirection(s_pInstance->m_pEntity->transform.dir);
	if (m_currentWeapon == 2)
		m_weapon2->SetDirection(s_pInstance->m_pEntity->transform.dir);
}

void Player::SetPosition(XMFLOAT3 _position)
{
	//m_position = _position;
}

XMFLOAT3 Player::GetPosition()
{
	return s_pInstance->m_pEntity->transform.pos;
}

void Player::UpdateCamera()
{
	XMINT2 mousePos = InputSystem::GetMousePosition();

	float deltaX = mousePos.x - m_center.x;
	float deltaY = mousePos.y - m_center.y;

	m_yaw += deltaX * s_pInstance->m_sensivity;
	m_pitch += deltaY * s_pInstance->m_sensivity;

	if (m_pitch > 1.55) { m_pitch = 1.55; }
	if (m_pitch < -1.55) { m_pitch = -1.55; }

	
	CAMERA->transform.SetYPR(m_yaw, m_pitch);
	s_pInstance->m_pEntity->transform.SetYaw(m_yaw);

	InputSystem::SetMousePosition({ cpuEngine.GetWindow()->GetWidth() / 2, cpuEngine.GetWindow()->GetHeight() / 2 });

	CAMERA->transform.pos = s_pInstance->m_pEntity->transform.pos;
	CAMERA->transform.pos.y += 2.f;

	CAMERA->transform.Move(-2);
}

void Player::MouseInput()
{
}

void Player::MoveForward(float dt)
{
	float m_xDir = s_pInstance->m_pEntity->transform.dir.x;
	float m_zDir = s_pInstance->m_pEntity->transform.dir.z;

	m_position.x += m_xDir * m_speed * dt;
	m_position.z += m_zDir * m_speed * dt;
}

void Player::MoveBackward(float dt)
{
	float m_xDir = s_pInstance->m_pEntity->transform.dir.x;
	float m_zDir = s_pInstance->m_pEntity->transform.dir.z;

	m_position.x -= m_xDir * m_speed * dt;
	m_position.z -= m_zDir * m_speed * dt;
}

void Player::StrafeLeft(float dt)
{
	float m_xDir = s_pInstance->m_pEntity->transform.dir.x;
	float m_zDir = s_pInstance->m_pEntity->transform.dir.z;

	m_position.x -= m_zDir * m_speed * dt;
	m_position.z += m_xDir * m_speed * dt;
}

void Player::StrafeRight(float dt)
{
	float m_xDir = s_pInstance->m_pEntity->transform.dir.x;
	float m_zDir = s_pInstance->m_pEntity->transform.dir.z;

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
	if (m_currentWeapon == 0)
		return;

	if (m_attackRefreshing < m_attackRefreshDuration || m_isWeaponEquiped == false)
		return;

	if (m_currentWeapon == 1)
		m_weapon1->BasicAttack();
	else if (m_currentWeapon == 2)
		m_weapon2->BasicAttack();
	
	m_attackRefreshing = 0.f;
}

void Player::RefreshAttack(float dt)
{
	m_attackRefreshing += dt;
}

void Player::SwapWeapon()
{
	if (m_currentWeapon == 0)
		return;

	if (m_attackRefreshing < m_attackRefreshDuration)
		return;

	if (m_currentWeapon == 1)
	{
		m_currentWeapon = 2;
		m_weaponEquipementDuration = m_weapon2->GetPulloutTime();
		m_attackRefreshDuration = m_weapon2->GetBasicAttackRefreshTime();
	}
	else if (m_currentWeapon == 2)
	{
		m_currentWeapon = 1;
		m_weaponEquipementDuration = m_weapon1->GetPulloutTime();
		m_attackRefreshDuration = m_weapon1->GetBasicAttackRefreshTime();
	}

	m_isWeaponEquiped = false;
	m_weaponEquipement = 0.0f;
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