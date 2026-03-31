#pragma once
#include "pch.h"
#include "GenericWeapon.h"
#include "HeroWeapon.h"

class Weapon
{
private:
	XMFLOAT3 mPosition;

	float mPulloutTime;

	float mBasicAttackDamages;
	float mSpecialAttackDamages;

	float mBasicAttackRefreshTime;
	float mSpecialAttackRefreshTime;
	float mSpecialAttackCooldown;

	int mWeaponType;
	bool mIsHeroWeapon;

	HeroWeapon* mHeroWeapon = nullptr;

	GenericWeapon* mGenericWeapon = nullptr;


public:
	void Init(int _type, int _playerClass);
	void Update(float dt);

	void SetDirection(XMFLOAT3 _dir);

	void BasicAttack();

	void SpecialAttack();

	float GetPulloutTime();

	float GetBasicAttackDamages();
	float GetSpecialAttackDamages();

	float GetBasicAttackRefreshTime();
	float GetSpecialAttackRefreshTime();
	float GetSpecialAttackCooldown();

	int GetWeaponType();
};

