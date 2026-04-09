#include "pch.h"
#include "GenericWeapon.h"

void GenericWeapon::Init(int _type)
{
	if (_type == 0)
	{
		m_sword = new GenericSword();
		m_sword->Init();
		m_weaponType = _type;

		m_pulloutTime = m_sword->GetPulloutTime();
		m_basicAttackDamages = m_sword->GetSwingDamages();
		m_basicAttackRefreshTime = m_sword->GetSwingTime();
	}
	if (_type == 1)
	{
		m_bow = new GenericBow();
		m_bow->Init();
		m_weaponType = _type;
		
		m_pulloutTime = m_bow->GetPulloutTime();
		m_basicAttackDamages = m_bow->GetProjectileDamages();
		m_basicAttackRefreshTime = m_bow->GetShootingTime();
	}
	if (_type == 2)
	{
		m_staff = new GenericStaff();
		m_staff->Init();
		m_weaponType = _type;
		
		m_pulloutTime = m_staff->GetPulloutTime();
		m_basicAttackDamages = m_staff->GetProjectileDamages();
		m_basicAttackRefreshTime = m_staff->GetShootingTime();
	}
}

void GenericWeapon::Update(float dt)
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

void GenericWeapon::Equip()
{
	m_isEquiped = true;

	if (m_weaponType == 0)
	{
		m_sword->Equip();
	}
	if (m_weaponType == 1)
	{
		m_bow->Equip();
	}
	if (m_weaponType == 2)
	{
		m_staff->Equip();
	}
}

void GenericWeapon::Unequip()
{
	m_isEquiped = false;

	if (m_weaponType == 0)
	{
		m_sword->Unequip();
	}
	if (m_weaponType == 1)
	{
		m_bow->Unequip();
	}
	if (m_weaponType == 2)
	{
		m_staff->Unequip();
	}
}

void GenericWeapon::SetPosition(XMFLOAT3 _pos)
{
	if (m_weaponType == 0)
	{
		m_sword->SetPosition(_pos);
	}
	if (m_weaponType == 1)
	{
		m_bow->SetPosition(_pos);
	}
	if (m_weaponType == 2)
	{
		m_staff->SetPosition(_pos);
	}
}

void GenericWeapon::SetDirection(XMFLOAT3 _dir)
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

void GenericWeapon::BasicAttack()
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

void GenericWeapon::SpecialAttack()
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

float GenericWeapon::GetPulloutTime()
{
	return m_pulloutTime;
}

float GenericWeapon::GetBasicAttackDamages()
{
	return m_basicAttackDamages;
}

float GenericWeapon::GetSpecialAttackDamages()
{
	return m_specialAttackDamages;
}

float GenericWeapon::GetBasicAttackRefreshTime()
{
	return m_basicAttackRefreshTime;
}

float GenericWeapon::GetSpecialAttackRefreshTime()
{
	return m_specialAttackRefreshTime;
}

float GenericWeapon::GetSpecialAttackCooldown()
{
	return m_specialAttackCooldown;
}

int GenericWeapon::GetWeaponType()
{
	return m_weaponType;
}