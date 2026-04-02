#pragma once
#include "pch.h"
#include "GenericWeapon.h"
#include "HeroWeapon.h"

class Weapon
{
private:
	XMFLOAT3 mPosition = {0.0f,0.0f,0.0f};

	float mPulloutTime = 0.0f;

	float mBasicAttackDamages = 0.0f;
	float mSpecialAttackDamages = 0.0f;

	float mBasicAttackRefreshTime = 0.0f;
	float mSpecialAttackRefreshTime = 0.0f;
	float mSpecialAttackCooldown = 0.0f;

	int mWeaponType = 0;
	bool mIsHeroWeapon = false;

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

