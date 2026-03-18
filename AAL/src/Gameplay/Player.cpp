#include "pch.h"
#include "Player.h"


void Player::Init()
{
}

void Player::Update(float dt)
{
	HandleInput(dt);
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

void Player::MoveForward(float dt)
{
	newPos.y += mSpeed * dt;
}

void Player::MoveBackward(float dt)
{
	newPos.y -= mSpeed * dt;
}

void Player::StrafeLeft(float dt)
{
	newPos.x -= mSpeed * dt;
}

void Player::StrafeRight(float dt)
{
	newPos.x += mSpeed * dt;
}

void Player::Jump()
{
}

void Player::Crouch()
{
}

void Player::Attack()
{
}

void Player::SwapWeapon()
{
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