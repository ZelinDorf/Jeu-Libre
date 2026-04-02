#pragma once
#include "pch.h"
#include "HeroSword.h"
#include "HeroBow.h"
#include "HeroStaff.h"

class HeroWeapon
{
private:

	XMFLOAT3 m_Position;

	float m_PulloutTime;

	float m_BasicAttackDamages;
	float m_SpecialAttackDamages;

	float m_BasicAttackRefreshTime;
	float m_SpecialAttackRefreshTime;
	float m_SpecialAttackCooldown;

	HeroSword* m_Sword;
	HeroBow* m_Bow;
	HeroStaff* m_Staff;

	int m_WeaponType;

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

