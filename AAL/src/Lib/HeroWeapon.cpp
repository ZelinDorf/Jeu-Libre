#include "pch.h"
#include "HeroWeapon.h"

void HeroWeapon::Init(int _type)
{
	if (_type == 0)
	{
		mWeaponType = _type;
		Sword->Init();
		mPulloutTime = Sword->GetPulloutTime();
		mBasicAttackDamages = Sword->GetSwingDamages();
		mBasicAttackRefreshTime = Sword->GetSwingTime();
	}
	if (_type == 1)
	{
		mWeaponType = _type;
		Bow->Init();
		mPulloutTime = Bow->GetPulloutTime();
		mBasicAttackDamages = Bow->GetProjectileDamages();
		mBasicAttackRefreshTime = Bow->GetShootingTime();
	}
	if (_type == 2)
	{
		mWeaponType = _type;
		Staff->Init();
		mPulloutTime = Staff->GetPulloutTime();
		mBasicAttackDamages = Staff->GetProjectileDamages();
		mBasicAttackRefreshTime = Staff->GetShootingTime();
	}
}

void HeroWeapon::Update(float dt)
{
	if (mWeaponType == 0)
	{
		Sword->Update(dt);
	}
	if (mWeaponType == 1)
	{
		Bow->Update(dt);
	}
	if (mWeaponType == 2)
	{
		Staff->Update(dt);
	}
}

void HeroWeapon::SetDirection(XMFLOAT3 _dir)
{
	if (mWeaponType == 0)
	{
		Sword->SetDirection(_dir);
	}
	if (mWeaponType == 1)
	{
		Bow->SetDirection(_dir);
	}
	if (mWeaponType == 2)
	{
		Staff->SetDirection(_dir);
	}
}

void HeroWeapon::BasicAttack()
{
	if (mWeaponType == 0)
	{
		Sword->Swing();
	}
	if (mWeaponType == 1)
	{
		Bow->Shoot();
	}
	if (mWeaponType == 2)
	{
		Staff->Shoot();
	}
}

void HeroWeapon::SpecialAttack()
{
	if (mWeaponType == 0)
	{
		Sword->Pound();
	}
	if (mWeaponType == 1)
	{
		Bow->Pierce();
	}
	if (mWeaponType == 2)
	{
		Staff->Puddle();
	}
}

float HeroWeapon::GetPulloutTime()
{
	return mPulloutTime;
}

float HeroWeapon::GetBasicAttackRefreshTime()
{
	return mBasicAttackRefreshTime;
}

float HeroWeapon::GetSpecialAttackRefreshTime()
{
	return mSpecialAttackRefreshTime;
}