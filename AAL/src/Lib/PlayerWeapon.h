#pragma once
#include "pch.h"

class Player
{
private:

	XMFLOAT3 mPosition;

	float mAttackSize = .25f;

public:

	void BasicAttack();

	void SpecialAttack();

};
