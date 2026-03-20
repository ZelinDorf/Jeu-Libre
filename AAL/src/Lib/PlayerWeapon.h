#pragma once
#include "pch.h"

class PlayerWeapon
{
private:

	XMFLOAT3 mPosition;

	float mAttackSize = .25f;

public:

	void BasicAttack();

	void SpecialAttack();

};
