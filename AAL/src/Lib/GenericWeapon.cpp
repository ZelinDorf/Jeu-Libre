#include "pch.h"
#include "GenericWeapon.h"

void GenericWeapon::Init(int _type)
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

void GenericWeapon::Update(float dt)
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

void GenericWeapon::SetDirection(XMFLOAT3 _dir)
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

void GenericWeapon::BasicAttack()
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

void GenericWeapon::SpecialAttack()
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

float GenericWeapon::GetPulloutTime()
{
	return mPulloutTime;
}

float GenericWeapon::GetBasicAttackRefreshTime()
{
	return mBasicAttackRefreshTime;
}

float GenericWeapon::GetSpecialAttackRefreshTime()
{
	return mSpecialAttackRefreshTime;
}
