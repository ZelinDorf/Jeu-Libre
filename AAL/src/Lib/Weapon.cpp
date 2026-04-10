#include "pch.h"
#include "Weapon.h"

void Weapon::Init(int _type, int _playerClass)
{
    if (_type == _playerClass)
    {
        m_heroWeapon = new HeroWeapon();
        m_heroWeapon->Init(_type);
        m_isHeroWeapon = true;

        m_pulloutTime = m_heroWeapon->GetPulloutTime();
        m_basicAttackRefreshTime = m_heroWeapon->GetBasicAttackRefreshTime();
        m_specialAttackRefreshTime = m_heroWeapon->GetSpecialAttackRefreshTime();
    }
    else
    {
        m_genericWeapon = new GenericWeapon();
        m_genericWeapon->Init(_type);
        m_isHeroWeapon = false;

        m_pulloutTime = m_genericWeapon->GetPulloutTime();
        m_basicAttackRefreshTime = m_genericWeapon->GetBasicAttackRefreshTime();
        m_specialAttackRefreshTime = m_genericWeapon->GetSpecialAttackRefreshTime();
    }

    m_weaponType = _type;
}

void Weapon::Update(float dt)
{
    if (m_isHeroWeapon == true)
    {
        m_heroWeapon->Update(dt);
    }
    else
    {
        m_genericWeapon->Update(dt);
    }
}

void Weapon::Equip()
{
    m_isEquiped = true;

    if (m_isHeroWeapon == true)
    {
        m_heroWeapon->Equip();
    }
    else
    {
        m_genericWeapon->Equip();
    }
}

void Weapon::Unequip()
{
    m_isEquiped = false;

    if (m_isHeroWeapon == true)
    {
        m_heroWeapon->Unequip();
    }
    else
    {
        m_genericWeapon->Unequip();
    }
}

void Weapon::SetPosition(XMFLOAT3 _pos)
{
    //if (m_isEquiped == true)
    {
        if (m_isHeroWeapon == true)
        {
            m_heroWeapon->SetPosition(_pos);
        }
        else
        {
            m_genericWeapon->SetPosition(_pos);
        }
    }
}

void Weapon::SetDirection(XMFLOAT3 _dir)
{
    if (m_isHeroWeapon == true)
    {
        m_heroWeapon->SetDirection(_dir);
    }
    else
    {
        m_genericWeapon->SetDirection(_dir);
    }
}

Vector<cpu_entity*> Weapon::GetProjectiles()
{
    if (m_isHeroWeapon == true)
    {
        return m_heroWeapon->GetProjectiles();
    }
    /*else
    {
        return;
    }*/
}

void Weapon::BasicAttack()
{
    if (m_isHeroWeapon == true)
    {
        m_heroWeapon->BasicAttack();
    }
    else
    {
        m_genericWeapon->BasicAttack();
    }
}

void Weapon::SpecialAttack()
{
    if (m_isHeroWeapon == true)
    {
        m_heroWeapon->SpecialAttack();
    }
    else
    {
        m_genericWeapon->SpecialAttack();
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
