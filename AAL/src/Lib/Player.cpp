#include "pch.h"
#include "Player.h"
#include "InputSystem.h"


void Player::Init()
{
	m_pEntity = cpuEngine.CreateEntity();
	m_meshPlayer.CreateSphere(mPlayerSize, 6, 6, CPU_WHITE, CPU_WHITE);
	m_pEntity->pMesh = &m_meshPlayer;
	m_pEntity->transform.pos = mPosition;
	m_pEntity->transform.SetYPR(0.0f, 0.0f, 0.0f);
	

	mPosition = XMFLOAT3(0.0f, 0.0f, 0.0f);
	mSpeed = mBaseSpeed;
	mCrouchedSpeed *= mSpeed;
}

void Player::Update(float dt)
{
	HandleInput(dt);
	RefreshAttack(dt);
}

void Player::HandleInput(float dt)
{
	if (mIsActive)
		return;
	

	if (InputSystem::IsKeyPressed(Z))
		MoveForward(dt);
	if (InputSystem::IsKeyPressed(S))
		MoveBackward(dt);
	if (InputSystem::IsKeyPressed(Q))
		StrafeLeft(dt);
	if (InputSystem::IsKeyPressed(D))
		StrafeRight(dt);

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
	mPosition.y += mSpeed * dt;
}

void Player::MoveBackward(float dt)
{
	mPosition.y -= mSpeed * dt;
}

void Player::StrafeLeft(float dt)
{
	mPosition.x -= mSpeed * dt;
}

void Player::StrafeRight(float dt)
{
	mPosition.x += mSpeed * dt;
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

	//Attack part

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