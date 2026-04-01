#pragma once
#include "pch.h"
#include "GenericSword.h"
#include "GenericBow.h"
#include "GenericStaff.h"

class GenericWeapon
{
private:

	XMFLOAT3 mPosition;

	float mPulloutTime;

	float mBasicAttackDamages;
	float mSpecialAttackDamages;

	float mBasicAttackRefreshTime;
	float mSpecialAttackRefreshTime;
	float mSpecialAttackCooldown;

	GenericSword* Sword;
	GenericBow* Bow;
	GenericStaff* Staff;

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
