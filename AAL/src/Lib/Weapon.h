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

	int mWeaponType;

public:
	void Init(int _type, int _playerClass);
	void Update(float dt);

	void SetDirection(XMFLOAT3 _dir);

	void BasicAttack();

	void SpecialAttack();

	float GetPulloutTime();

	float GetBasicAttackRefreshTime();
	float GetSpecialAttackRefreshTime();

	int GetWeaponType();
};

