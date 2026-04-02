#pragma once
#include "pch.h"
#include "GenericWeapon.h"
#include "HeroWeapon.h"

class Weapon
{
private:
	XMFLOAT3 m_position;

	float m_pulloutTime;

	float m_basicAttackDamages;
	float m_specialAttackDamages;

	float m_basicAttackRefreshTime;
	float m_specialAttackRefreshTime;
	float m_specialAttackCooldown;

	int m_weaponType;
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

