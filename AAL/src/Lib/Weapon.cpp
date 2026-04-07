#include "pch.h"
#include "Weapon.h"

void Weapon::Init(int _type, int _playerClass)
{
    if (_type == _playerClass)
    {
        mHeroWeapon->Init(_type);
        mIsHeroWeapon = true;

        mPulloutTime = mHeroWeapon->GetPulloutTime();
        mBasicAttackRefreshTime = mHeroWeapon->GetBasicAttackRefreshTime();
        mSpecialAttackRefreshTime = mHeroWeapon->GetSpecialAttackRefreshTime();
    }
    else
    {
        mGenericWeapon->Init(_type);
        mIsHeroWeapon = false;

        mPulloutTime = mGenericWeapon->GetPulloutTime();
        mBasicAttackRefreshTime = mGenericWeapon->GetBasicAttackRefreshTime();
        mSpecialAttackRefreshTime = mGenericWeapon->GetSpecialAttackRefreshTime();
    }

    mWeaponType = _type;
}

void Weapon::Update(float dt)
{
    if (mIsHeroWeapon == true)
    {
        mHeroWeapon->Update(dt);
    }
    else
    {
        mGenericWeapon->Update(dt);
    }
}

void Weapon::SetDirection(XMFLOAT3 _dir)
{
    if (mIsHeroWeapon == true)
    {
        mHeroWeapon->SetDirection(_dir);
    }
    else
    {
        mGenericWeapon->SetDirection(_dir);
    }
}

void Weapon::BasicAttack()
{
    if (mIsHeroWeapon == true)
    {
        mHeroWeapon->BasicAttack();
    }
    else
    {
        mGenericWeapon->BasicAttack();
    }
}

void Weapon::SpecialAttack()
{
    if (mIsHeroWeapon == true)
    {
        mHeroWeapon->SpecialAttack();
    }
    else
    {
        mGenericWeapon->SpecialAttack();
    }
}

float Weapon::GetPulloutTime()
{
    return mPulloutTime;
}

float Weapon::GetBasicAttackDamages()
{
    return mBasicAttackDamages;
}

float Weapon::GetSpecialAttackDamages()
{
    return mSpecialAttackDamages;
}

float Weapon::GetBasicAttackRefreshTime()
{
    return mBasicAttackRefreshTime;
}

float Weapon::GetSpecialAttackRefreshTime()
{
    return mSpecialAttackRefreshTime;
}

float Weapon::GetSpecialAttackCooldown()
{
    return mSpecialAttackCooldown;
}

int Weapon::GetWeaponType()
{
    return mWeaponType;
}
