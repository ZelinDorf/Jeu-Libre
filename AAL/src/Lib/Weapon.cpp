#include "pch.h"
#include "Weapon.h"

void Weapon::Init(int _type, int _playerClass)
{
    if (_type == _playerClass)
    {
        m_HeroWeapon->Init(_type);
        m_IsHeroWeapon = true;

        m_pulloutTime = m_HeroWeapon->GetPulloutTime();
        m_basicAttackRefreshTime = m_HeroWeapon->GetBasicAttackRefreshTime();
        m_specialAttackRefreshTime = m_HeroWeapon->GetSpecialAttackRefreshTime();
    }
    else
    {
        m_GenericWeapon->Init(_type);
        m_IsHeroWeapon = false;

        m_pulloutTime = m_GenericWeapon->GetPulloutTime();
        m_basicAttackRefreshTime = m_GenericWeapon->GetBasicAttackRefreshTime();
        m_specialAttackRefreshTime = m_GenericWeapon->GetSpecialAttackRefreshTime();
    }

    m_weaponType = _type;
}

void Weapon::Update(float dt)
{
    if (m_IsHeroWeapon == true)
    {
        m_HeroWeapon->Update(dt);
    }
    else
    {
        m_GenericWeapon->Update(dt);
    }
}

void Weapon::SetDirection(XMFLOAT3 _dir)
{
    if (m_IsHeroWeapon == true)
    {
        m_HeroWeapon->SetDirection(_dir);
    }
    else
    {
        m_GenericWeapon->SetDirection(_dir);
    }
}

void Weapon::BasicAttack()
{
    if (m_IsHeroWeapon == true)
    {
        m_HeroWeapon->BasicAttack();
    }
    else
    {
        m_GenericWeapon->BasicAttack();
    }
}

void Weapon::SpecialAttack()
{
    if (m_IsHeroWeapon == true)
    {
        m_HeroWeapon->SpecialAttack();
    }
    else
    {
        m_GenericWeapon->SpecialAttack();
    }
}

float Weapon::GetPulloutTime()
{
    return m_pulloutTime;
}

float Weapon::GetBasicAttackDamages()
{
    return m_basicAttackDamages;
}

float Weapon::GetSpecialAttackDamages()
{
    return m_specialAttackDamages;
}

float Weapon::GetBasicAttackRefreshTime()
{
    return m_basicAttackRefreshTime;
}

float Weapon::GetSpecialAttackRefreshTime()
{
    return m_specialAttackRefreshTime;
}

float Weapon::GetSpecialAttackCooldown()
{
    return m_specialAttackCooldown;
}

int Weapon::GetWeaponType()
{
    return m_weaponType;
}
