#pragma once
#include "pch.h"
#include "Weapon.h"
#include "PlayerStatsManager.h"

class Player
{
private:

	XMFLOAT3 m_Position;

	float m_PlayerSize = .5f;

	float m_BaseSpeed = 15;
	float m_Speed;
	float m_CrouchedSpeed = 5;

	float m_AttackRefreshing = 0.f;
	float m_AttackRefreshDuration;

	void MouseInput();

	void MoveForward(float dt);
	void MoveBackward(float dt);
	void StrafeLeft(float dt);
	void StrafeRight(float dt);

	void Jump();
	void Crouch();
	void Uncrouch();

	bool m_IsJumping;
	bool m_IsCrouched;

	cpu_mesh m_meshPlayer;

	void WeaponEquiped(float dt);

	bool m_IsWeaponEquiped = true;
	float m_WeaponEquipement = 0.0f;
	float m_WeaponEquipementDuration;

	void Attack();
	void RefreshAttack(float dt);

	void SwapWeapon();

	bool m_IsInventoryOpened;
	bool m_IsUpgradePageOpened;

	void Inventory();
	void UpgradesPage();

	int m_PlayerClass;

	Weapon* m_Weapon1 = nullptr;
	Weapon* m_Weapon2 = nullptr;

	PlayerStatsManager m_Stats;

public:
	cpu_entity* m_pEntity;

	bool m_IsActive = false;

	void Init(int _class);
	void Update(float dt);
	void HandleInput(float dt);

	void Destroy();

	Weapon* m_CurrentWeapon;

	void SetWeaponDirection();

	void SetPosition(XMFLOAT3 _position);
	XMFLOAT3 GetPosition();
};

