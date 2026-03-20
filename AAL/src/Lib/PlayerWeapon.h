#pragma once
#include "pch.h"
#include "SwordWeapon.h"

class PlayerWeapon
{
private:

	XMFLOAT3 mPosition;

	float mPulloutTime;

	float mBasicAttackDamages;
	float mSpecialAttackDamages;

	float mBasicAttackRefreshTime;
	float mSpecialAttackRefreshTime;

	SwordWeapon* Sword;

	int mWeaponType;

public:

	void Init(int _type);
	void Update(float dt);

	void SetDirection(XMFLOAT3 _dir);

	void BasicAttack();

	void SpecialAttack();

	float GetPulloutTime();

	float GetBasicAttackRefreshTime();
	float GetSpecialAttackRefreshTime();

};
