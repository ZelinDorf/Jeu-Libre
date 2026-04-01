#include "pch.h"
#include "PlayerStatsManager.h"

void PlayerStatsManager::SetBaseSpeed(float _speed)
{
	mBaseSpeed = _speed;
}

void PlayerStatsManager::SetSpeedMultiplier(float _multiplier)
{
	mSpeedMultiplier = _multiplier;
}

float PlayerStatsManager::GetBaseSpeed()
{
	return mBaseSpeed;
}

float PlayerStatsManager::GetSpeedMultiplier()
{
	return mSpeedMultiplier;
}

float PlayerStatsManager::GetFinalSpeed()
{
	mFinalSpeed = mBaseSpeed * mSpeedMultiplier;
	return mFinalSpeed;
}

void PlayerStatsManager::SetBaseJumpForce(float _jumpForce)
{
	mBaseJumpForce = _jumpForce;
}

void PlayerStatsManager::SetJumpForceMultiplier(float _multiplier)
{
	mJumpForceMultiplier = _multiplier;
}

float PlayerStatsManager::GetBaseJumpForce()
{
	return mBaseJumpForce;
}

float PlayerStatsManager::GetJumpForceMultiplier()
{
	return mJumpForceMultiplier;
}

float PlayerStatsManager::GetFinalJumpForce()
{
	mFinalJumpForce = mBaseJumpForce * mJumpForceMultiplier;
	return mFinalJumpForce;
}

void PlayerStatsManager::SetBaseAttackDamage(int _weapon, float _dmg)
{
	if (_weapon == 1)
	{
		mWeapon1BaseAttackDamage = _dmg;
	}
	else if (_weapon == 2)
	{
		mWeapon2BaseAttackDamage = _dmg;
	}
}

void PlayerStatsManager::SetAdditionalAttackDamage(int _weapon, float _dmg)
{
	if (_weapon == 1)
	{
		mWeapon1AdditionalAttackDamage = _dmg;
	}
	else if (_weapon == 2)
	{
		mWeapon2AdditionalAttackDamage = _dmg;
	}
}

void PlayerStatsManager::SetAttackDamageMultiplier(int _weapon, float _multiplier)
{
	if (_weapon == 1)
	{
		mWeapon1AttackDamageMultiplier = _multiplier;
	}
	else if (_weapon == 2)
	{
		mWeapon2AttackDamageMultiplier = _multiplier;
	}
}

float PlayerStatsManager::GetBaseAttackDamage(int _weapon)
{
	if (_weapon == 1)
	{
		return mWeapon1BaseAttackDamage;
	}
	else if (_weapon == 2)
	{
		return mWeapon2BaseAttackDamage;
	}
}

float PlayerStatsManager::GetAdditionalAttackDamage(int _weapon)
{
	if (_weapon == 1)
	{
		return mWeapon1AdditionalAttackDamage;
	}
	else if (_weapon == 2)
	{
		return mWeapon2AdditionalAttackDamage;
	}
}

float PlayerStatsManager::GetAttackDamageMultiplier(int _weapon)
{
	if (_weapon == 1)
	{
		return mWeapon1AttackDamageMultiplier;
	}
	else if (_weapon == 2)
	{
		return mWeapon2AttackDamageMultiplier;
	}
}

float PlayerStatsManager::GetFinalAttackDamage(int _weapon)
{
	if (_weapon == 1)
	{
		mWeapon1FinalAttackDamage = mWeapon1BaseAttackDamage * mWeapon1AttackDamageMultiplier + mWeapon1AdditionalAttackDamage;
		return mWeapon1FinalAttackDamage;
	}
	else if (_weapon == 2)
	{
		mWeapon2FinalAttackDamage = mWeapon2BaseAttackDamage * mWeapon2AttackDamageMultiplier + mWeapon2AdditionalAttackDamage;
		return mWeapon2FinalAttackDamage;
	}
	
}

void PlayerStatsManager::SetBaseAttackRefreshingTime(int _weapon, float _time)
{
	if (_weapon == 1)
	{
		mWeapon1BaseAttackRefreshingTime = _time;
	}
	else if (_weapon == 2)
	{
		mWeapon2BaseAttackRefreshingTime = _time;
	}
}

void PlayerStatsManager::SetAttackRefreshingMultiplier(int _weapon, float _multiplier)
{
	if (_weapon == 1)
	{
		mWeapon1AttackRefreshingTimeMultiplier = _multiplier;
	}
	else if (_weapon == 2)
	{
		mWeapon2AttackRefreshingTimeMultiplier = _multiplier;
	}
}

float PlayerStatsManager::GetBaseAttackRefreshingTime(int _weapon)
{
	if (_weapon == 1)
	{
		return mWeapon1BaseAttackRefreshingTime;
	}
	else if (_weapon == 2)
	{
		return mWeapon2BaseAttackRefreshingTime;
	}
}

float PlayerStatsManager::GetAttackRefreshingMultiplier(int _weapon)
{
	if (_weapon == 1)
	{
		return mWeapon1AttackRefreshingTimeMultiplier;
	}
	else if (_weapon == 2)
	{
		return mWeapon2AttackRefreshingTimeMultiplier;
	}
}

float PlayerStatsManager::GetFinalAttackRefreshingTime(int _weapon)
{
	if (_weapon == 1)
	{
		mWeapon1FinalAttackRefreshingtime = mWeapon1BaseAttackRefreshingTime * mWeapon1AttackRefreshingTimeMultiplier;
		return mWeapon1FinalAttackRefreshingtime;
	}
	else if (_weapon == 2)
	{
		mWeapon2FinalAttackRefreshingtime = mWeapon2BaseAttackRefreshingTime * mWeapon2AttackRefreshingTimeMultiplier;
		return mWeapon2FinalAttackRefreshingtime;
	}
}
