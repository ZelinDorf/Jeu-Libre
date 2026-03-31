#pragma once
#include "pch.h"
#include "HeroSword.h"
#include "HeroBow.h"
#include "HeroStaff.h"

class HeroWeapon
{
private:

	XMFLOAT3 mPosition;

	float mPulloutTime;

	float mBasicAttackDamages;
	float mSpecialAttackDamages;

	float mBasicAttackRefreshTime;
	float mSpecialAttackRefreshTime;
	float mSpecialAttackCooldown;

	HeroSword* Sword;
	HeroBow* Bow;
	HeroStaff* Staff;

	int mWeaponType;

public:

	void Init(int _type);
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

