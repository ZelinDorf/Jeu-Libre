#include "pch.h"
#include "GenericWeapon.h"

void GenericWeapon::Init(int _type)
{
	if (_type == 0)
	{
		m_WeaponType = _type;
		Sword->Init();
		m_PulloutTime = Sword->GetPulloutTime();
		m_BasicAttackDamages = Sword->GetSwingDamages();
		m_BasicAttackRefreshTime = Sword->GetSwingTime();
	}
	if (_type == 1)
	{
		m_WeaponType = _type;
		Bow->Init();
		m_PulloutTime = Bow->GetPulloutTime();
		m_BasicAttackDamages = Bow->GetProjectileDamages();
		m_BasicAttackRefreshTime = Bow->GetShootingTime();
	}
	if (_type == 2)
	{
		m_WeaponType = _type;
		Staff->Init();
		m_PulloutTime = Staff->GetPulloutTime();
		m_BasicAttackDamages = Staff->GetProjectileDamages();
		m_BasicAttackRefreshTime = Staff->GetShootingTime();
	}
}

void GenericWeapon::Update(float dt)
{
	if (m_WeaponType == 0)
	{
		Sword->Update(dt);
	}
	if (m_WeaponType == 1)
	{
		Bow->Update(dt);
	}
	if (m_WeaponType == 2)
	{
		Staff->Update(dt);
	}
}

void GenericWeapon::SetDirection(XMFLOAT3 _dir)
{
	if (m_WeaponType == 0)
	{
		Sword->SetDirection(_dir);
	}
	if (m_WeaponType == 1)
	{
		Bow->SetDirection(_dir);
	}
	if (m_WeaponType == 2)
	{
		Staff->SetDirection(_dir);
	}
}

void GenericWeapon::BasicAttack()
{
	if (m_WeaponType == 0)
	{
		Sword->Swing();
	}
	if (m_WeaponType == 1)
	{
		Bow->Shoot();
	}
	if (m_WeaponType == 2)
	{
		Staff->Shoot();
	}
}

void GenericWeapon::SpecialAttack()
{
	if (m_WeaponType == 0)
	{
		Sword->Pound();
	}
	if (m_WeaponType == 1)
	{
		Bow->Pierce();
	}
	if (m_WeaponType == 2)
	{
		Staff->Puddle();
	}
}

float GenericWeapon::GetPulloutTime()
{
	return m_PulloutTime;
}

float GenericWeapon::GetBasicAttackDamages()
{
	return m_BasicAttackDamages;
}

float GenericWeapon::GetSpecialAttackDamages()
{
	return m_SpecialAttackDamages;
}

float GenericWeapon::GetBasicAttackRefreshTime()
{
	return m_BasicAttackRefreshTime;
}

float GenericWeapon::GetSpecialAttackRefreshTime()
{
	return m_SpecialAttackRefreshTime;
}

float GenericWeapon::GetSpecialAttackCooldown()
{
	return m_SpecialAttackCooldown;
}

int GenericWeapon::GetWeaponType()
{
	return m_WeaponType;
}