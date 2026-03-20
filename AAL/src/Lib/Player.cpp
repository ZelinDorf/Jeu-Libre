#include "pch.h"
#include "Player.h"
#include "InputSystem.h"


void Player::Init()
{
	
	//cpuEngine.GetCamera()->transform.SetYPR(0.f, 1.570796f, 0.f);

	m_pEntity = cpuEngine.CreateEntity();
	m_meshPlayer.CreateSphere(mPlayerSize, 20, 20, CPU_WHITE, CPU_WHITE);
	m_pEntity->pMesh = &m_meshPlayer;
	m_pEntity->transform.pos = mPosition;
	m_pEntity->transform.SetYPR(0.0f, 0.0f, 0.0f);
	

	mPosition = XMFLOAT3(0.0f, 0.0f, 0.0f);
	mSpeed = mBaseSpeed;
	mCrouchedSpeed *= mSpeed;

}

void Player::Update(float dt)
{
	m_pEntity->transform.pos = mPosition;

	XMFLOAT3 m_camPos = XMFLOAT3(mPosition.x + 2.f, mPosition.y + 2.f, mPosition.z - 4.f);
	//cpuEngine.GetCamera()->transform.SetYPR(0.f, .2f, 0.f);
	cpuEngine.GetCamera()->transform.pos = m_camPos;

	m_pEntity->transform.dir = cpuEngine.GetCamera()->transform.dir;

	HandleInput(dt);
	RefreshAttack(dt);
}

void Player::HandleInput(float dt)
{
	if (mIsActive)
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
		mIsJumping = true;
	}

	if (InputSystem::IsKeyDown(LCTRL))
	{
		Crouch();
		mIsCrouched = true;
	}
	else
	{
		Uncrouch();
		mIsCrouched = false;
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

void Player::SetPosition(XMFLOAT3 _position)
{
	mPosition = _position;
}

XMFLOAT3 Player::GetPosition()
{
	return mPosition;
}

void Player::MouseInput()
{
}

void Player::MoveForward(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	mPosition.x += m_xDir * mSpeed * dt;
	mPosition.z += m_zDir * mSpeed * dt;
}

void Player::MoveBackward(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	mPosition.x -= m_xDir * mSpeed * dt;
	mPosition.z -= m_zDir * mSpeed * dt;
}

void Player::StrafeLeft(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	mPosition.x -= m_zDir * mSpeed * dt;
	mPosition.z += m_xDir * mSpeed * dt;
}

void Player::StrafeRight(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	mPosition.x += m_zDir * mSpeed * dt;
	mPosition.z -= m_xDir * mSpeed * dt;
}

void Player::Jump()
{

}

void Player::Crouch()
{
	mSpeed = mCrouchedSpeed;
}
void Player::Uncrouch()
{
	mSpeed = mBaseSpeed;
}

void Player::Attack()
{
	if (mAttackRefreshing < mAttackRefreshDuration)
		return;

	mPlayerWeapon.BasicAttack();

	mAttackRefreshing = 0.f;
}

void Player::RefreshAttack(float dt)
{
	mAttackRefreshing += dt;
}

void Player::SwapWeapon()
{
	if (mAttackRefreshing < mAttackRefreshDuration)
		return;

	if (mCurrentWeapon == 0)
		mCurrentWeapon = 1;
	else
		mCurrentWeapon = 0;
}

void Player::Inventory()
{
	if (mIsInventoryOpened == false)
	{
		mIsInventoryOpened = true;
	}
		
	else
	{
		mIsInventoryOpened = false;
	}
		
}

void Player::UpgradesPage()
{
	if (mIsUpgradePageOpened == false)
	{
		mIsUpgradePageOpened = true;
	}

	else
	{
		mIsUpgradePageOpened = false;
	}
}