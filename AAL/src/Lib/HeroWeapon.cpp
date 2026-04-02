#include "pch.h"
#include "HeroWeapon.h"

void HeroWeapon::Init(int _type)
{
	if (_type == 0)
	{
		m_weaponType = _type;
		m_sword->Init();
		m_pulloutTime = m_sword->GetPulloutTime();
		m_basicAttackDamages = m_sword->GetSwingDamages();
		m_basicAttackRefreshTime = m_sword->GetSwingTime();
	}
	if (_type == 1)
	{
		m_weaponType = _type;
		m_bow->Init();
		m_pulloutTime = m_bow->GetPulloutTime();
		m_basicAttackDamages = m_bow->GetProjectileDamages();
		m_basicAttackRefreshTime = m_bow->GetShootingTime();
	}
	if (_type == 2)
	{
		m_weaponType = _type;
		m_staff->Init();
		m_pulloutTime = m_staff->GetPulloutTime();
		m_basicAttackDamages = m_staff->GetProjectileDamages();
		m_basicAttackRefreshTime = m_staff->GetShootingTime();
	}
}

void HeroWeapon::Update(float dt)
{
	if (m_weaponType == 0)
	{
		m_sword->Update(dt);
	}
	if (m_weaponType == 1)
	{
		m_bow->Update(dt);
	}
	if (m_weaponType == 2)
	{
		m_staff->Update(dt);
	}
}

void HeroWeapon::SetDirection(XMFLOAT3 _dir)
{
	if (m_weaponType == 0)
	{
		m_sword->SetDirection(_dir);
	}
	if (m_weaponType == 1)
	{
		m_bow->SetDirection(_dir);
	}
	if (m_weaponType == 2)
	{
		m_staff->SetDirection(_dir);
	}
}

void HeroWeapon::BasicAttack()
{
	if (m_weaponType == 0)
	{
		m_sword->Swing();
	}
	if (m_weaponType == 1)
	{
		m_bow->Shoot();
	}
	if (m_weaponType == 2)
	{
		m_staff->Shoot();
	}
}

void HeroWeapon::SpecialAttack()
{
	if (m_weaponType == 0)
	{
		m_sword->Pound();
	}
	if (m_weaponType == 1)
	{
		m_bow->Pierce();
	}
	if (m_weaponType == 2)
	{
		m_staff->Puddle();
	}
}

float HeroWeapon::GetPulloutTime()
{
	return m_pulloutTime;
}

float HeroWeapon::GetBasicAttackDamages()
{
	return m_basicAttackDamages;
}

float HeroWeapon::GetSpecialAttackDamages()
{
	return m_specialAttackDamages;
}

float HeroWeapon::GetBasicAttackRefreshTime()
{
	return m_basicAttackRefreshTime;
}

float HeroWeapon::GetSpecialAttackRefreshTime()
{
	return m_specialAttackRefreshTime;
}

float HeroWeapon::GetSpecialAttackCooldown()
{
	return m_specialAttackCooldown;
}

int HeroWeapon::GetWeaponType()
{
	return m_weaponType;
}