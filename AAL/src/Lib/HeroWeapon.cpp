#include "pch.h"
#include "HeroWeapon.h"

void HeroWeapon::Init(int _type)
{
	if (_type == 0)
	{
		m_WeaponType = _type;
		m_Sword->Init();
		m_PulloutTime = m_Sword->GetPulloutTime();
		m_BasicAttackDamages = m_Sword->GetSwingDamages();
		m_BasicAttackRefreshTime = m_Sword->GetSwingTime();
	}
	if (_type == 1)
	{
		m_WeaponType = _type;
		m_Bow->Init();
		m_PulloutTime = m_Bow->GetPulloutTime();
		m_BasicAttackDamages = m_Bow->GetProjectileDamages();
		m_BasicAttackRefreshTime = m_Bow->GetShootingTime();
	}
	if (_type == 2)
	{
		m_WeaponType = _type;
		m_Staff->Init();
		m_PulloutTime = m_Staff->GetPulloutTime();
		m_BasicAttackDamages = m_Staff->GetProjectileDamages();
		m_BasicAttackRefreshTime = m_Staff->GetShootingTime();
	}
}

void HeroWeapon::Update(float dt)
{
	if (m_WeaponType == 0)
	{
		m_Sword->Update(dt);
	}
	if (m_WeaponType == 1)
	{
		m_Bow->Update(dt);
	}
	if (m_WeaponType == 2)
	{
		m_Staff->Update(dt);
	}
}

void HeroWeapon::SetDirection(XMFLOAT3 _dir)
{
	if (m_WeaponType == 0)
	{
		m_Sword->SetDirection(_dir);
	}
	if (m_WeaponType == 1)
	{
		m_Bow->SetDirection(_dir);
	}
	if (m_WeaponType == 2)
	{
		m_Staff->SetDirection(_dir);
	}
}

void HeroWeapon::BasicAttack()
{
	if (m_WeaponType == 0)
	{
		m_Sword->Swing();
	}
	if (m_WeaponType == 1)
	{
		m_Bow->Shoot();
	}
	if (m_WeaponType == 2)
	{
		m_Staff->Shoot();
	}
}

void HeroWeapon::SpecialAttack()
{
	if (m_WeaponType == 0)
	{
		m_Sword->Pound();
	}
	if (m_WeaponType == 1)
	{
		m_Bow->Pierce();
	}
	if (m_WeaponType == 2)
	{
		m_Staff->Puddle();
	}
}

float HeroWeapon::GetPulloutTime()
{
	return m_PulloutTime;
}

float HeroWeapon::GetBasicAttackDamages()
{
	return m_BasicAttackDamages;
}

float HeroWeapon::GetSpecialAttackDamages()
{
	return m_SpecialAttackDamages;
}

float HeroWeapon::GetBasicAttackRefreshTime()
{
	return m_BasicAttackRefreshTime;
}

float HeroWeapon::GetSpecialAttackRefreshTime()
{
	return m_SpecialAttackRefreshTime;
}

float HeroWeapon::GetSpecialAttackCooldown()
{
	return m_SpecialAttackCooldown;
}

int HeroWeapon::GetWeaponType()
{
	return m_WeaponType;
}