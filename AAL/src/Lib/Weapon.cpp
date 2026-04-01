#include "pch.h"
#include "Weapon.h"

void Weapon::Init(int _type, int _playerClass)
{
    if (_type == _playerClass)
    {
        m_HeroWeapon->Init(_type);
        m_IsHeroWeapon = true;

        m_PulloutTime = m_HeroWeapon->GetPulloutTime();
        m_BasicAttackRefreshTime = m_HeroWeapon->GetBasicAttackRefreshTime();
        m_SpecialAttackRefreshTime = m_HeroWeapon->GetSpecialAttackRefreshTime();
    }
    else
    {
        m_GenericWeapon->Init(_type);
        m_IsHeroWeapon = false;

        m_PulloutTime = m_GenericWeapon->GetPulloutTime();
        m_BasicAttackRefreshTime = m_GenericWeapon->GetBasicAttackRefreshTime();
        m_SpecialAttackRefreshTime = m_GenericWeapon->GetSpecialAttackRefreshTime();
    }

    m_WeaponType = _type;
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
    return m_PulloutTime;
}

float Weapon::GetBasicAttackDamages()
{
    return m_BasicAttackDamages;
}

float Weapon::GetSpecialAttackDamages()
{
    return m_SpecialAttackDamages;
}

float Weapon::GetBasicAttackRefreshTime()
{
    return m_BasicAttackRefreshTime;
}

float Weapon::GetSpecialAttackRefreshTime()
{
    return m_SpecialAttackRefreshTime;
}

float Weapon::GetSpecialAttackCooldown()
{
    return m_SpecialAttackCooldown;
}

int Weapon::GetWeaponType()
{
    return m_WeaponType;
}
