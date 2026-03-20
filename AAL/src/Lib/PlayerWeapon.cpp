#include "pch.h"
#include "PlayerWeapon.h"

void PlayerWeapon::Init(int _type)
{
	if (_type == 0)
	{
		mWeaponType = _type;
		Sword->Init();
		mPulloutTime = Sword->GetmPulloutTime();
		mBasicAttackDamages = Sword->GetSwingDamages();
		mBasicAttackRefreshTime = Sword->GetSwingTime();
	}
}

void PlayerWeapon::Update(float dt)
{
	if (mWeaponType == 0)
	{
		Sword->Update(dt);
	}
}

void PlayerWeapon::SetDirection(XMFLOAT3 _dir)
{
	if (mWeaponType == 0)
	{
		Sword->SetDirection(_dir);
	}
}

void PlayerWeapon::BasicAttack()
{
	if (mWeaponType == 0)
	{
		Sword->Swing();
	}
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
