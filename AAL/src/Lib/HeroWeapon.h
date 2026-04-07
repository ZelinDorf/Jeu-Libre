#pragma once
#include "pch.h"
#include "HeroSword.h"
#include "HeroBow.h"
#include "HeroStaff.h"

class HeroWeapon
{
private:

	XMFLOAT3 mPosition = {0.0f,0.0f,0.0f};

	float mPulloutTime = 0.0f;

	float mBasicAttackDamages = 0.0f;
	float mSpecialAttackDamages = 0.0f;

	float mBasicAttackRefreshTime = 0.0f;
	float mSpecialAttackRefreshTime = 0.0f;
	float mSpecialAttackCooldown = 0.0f;

	HeroSword* Sword = nullptr;
	HeroBow* Bow = nullptr;
	HeroStaff* Staff = nullptr;

	int mWeaponType=0;

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

