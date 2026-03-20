#pragma once
#include "pch.h"

class PlayerWeapon
{
private:

	XMFLOAT3 mPosition;

	float mAttackSize = .25f;

	float mPulloutTime;

	float mBasicAttackRefreshTime;
	float mSpecialAttackRefreshTime;

public:

	void BasicAttack();

	void SpecialAttack();

	float GetPulloutTime();

	float GetBasicAttackRefreshTime();
	float GetSpecialAttackRefreshTime();

};
