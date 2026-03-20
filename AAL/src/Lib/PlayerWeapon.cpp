#include "pch.h"
#include "PlayerWeapon.h"

void PlayerWeapon::BasicAttack()
{
}

void PlayerWeapon::SpecialAttack()
{
}

float PlayerWeapon::GetPulloutTime()
{
	return mPulloutTime;
}

float PlayerWeapon::GetBasicAttackRefreshTime()
{
	return mBasicAttackRefreshTime;
}

float PlayerWeapon::GetSpecialAttackRefreshTime()
{
	return mSpecialAttackRefreshTime;
}
