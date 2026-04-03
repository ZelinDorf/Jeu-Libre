#pragma once
#include "pch.h"
#include "GenericSword.h"
#include "GenericBow.h"
#include "GenericStaff.h"

class GenericWeapon
{
private:

	XMFLOAT3 m_position;

	bool m_isEquiped;

	float m_pulloutTime;

	float m_basicAttackDamages;
	float m_specialAttackDamages;

	float m_basicAttackRefreshTime;
	float m_specialAttackRefreshTime;
	float m_specialAttackCooldown;

	GenericSword* m_sword;
	GenericBow* m_bow;
	GenericStaff* m_staff;

	int m_weaponType;

public:

	void Init(int _type);
	void Update(float dt);

	void Equip();
	void Unequip();

	void SetPosition(XMFLOAT3 _pos);
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
