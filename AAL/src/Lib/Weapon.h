#pragma once
#include "pch.h"
#include "GenericWeapon.h"
#include "HeroWeapon.h"

class Weapon
{
private:
	XMFLOAT3 m_Position;

	float m_PulloutTime;

	float m_BasicAttackDamages;
	float m_SpecialAttackDamages;

	float m_BasicAttackRefreshTime;
	float m_SpecialAttackRefreshTime;
	float m_SpecialAttackCooldown;

	int m_WeaponType;
	bool m_IsHeroWeapon;

	HeroWeapon* m_HeroWeapon = nullptr;

	GenericWeapon* m_GenericWeapon = nullptr;


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

