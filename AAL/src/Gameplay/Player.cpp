#include "pch.h"
#include "Player.h"


void Player::Init()
{
	mSpeed = mBaseSpeed;
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

	if (cpuInput.IsKey('Z'))
		MoveForward(dt);
	if (cpuInput.IsKey('S'))
		MoveBackward(dt);
	if (cpuInput.IsKey('Q'))
		StrafeLeft(dt);
	if (cpuInput.IsKey('D'))
		StrafeRight(dt);

	if (cpuInput.IsKeyDown(VK_LCONTROL))
	{
		Crouch();
		mIsCrouched = true;
	}
	else
	{
		Uncrouch();
		mIsCrouched = false;
	}

	if (cpuInput.IsKeyDown(VK_LBUTTON))
	{
		Attack();
	}


	if (cpuInput.IsKey('F'))
		SwapWeapon();

	if (cpuInput.IsKey('E'))
		Inventory();

	if (cpuInput.IsKey('A'))
		UpgradesPage();
}

void Player::MouseInput()
{
}

void Player::MoveForward(float dt)
{
	float _speed = mSpeed;
	if (mIsCrouched == true)
		_speed *= .4f;
	newPos.y += _speed * dt;
}

void Player::MoveBackward(float dt)
{
	float _speed = mSpeed;
	if (mIsCrouched == true)
		_speed *= .4f;
	newPos.y -= _speed * dt;
}

void Player::StrafeLeft(float dt)
{
	float _speed = mSpeed;
	if (mIsCrouched == true)
		_speed *= .4f;
	newPos.x -= _speed * dt;
}

void Player::StrafeRight(float dt)
{
	float _speed = mSpeed;
	if (mIsCrouched == true)
		_speed *= .4f;
	newPos.x += _speed * dt;
}

void Player::Jump()
{
}

void Player::Crouch()
{

}
void Player::Uncrouch()
{

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