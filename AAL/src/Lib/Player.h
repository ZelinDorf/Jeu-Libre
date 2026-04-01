#pragma once
#include "pch.h"
#include "Weapon.h"

class Player : public AALentity
{
private:

	XMFLOAT3 m_position;

	float m_playerSize = .5f;

	float m_baseSpeed = 15;
	float m_speed;
	float m_crouchedSpeed = 5;

	float m_attackRefreshing = 0.f;
	float m_attackRefreshDuration;

	void MouseInput();

	void MoveForward(float dt);
	void MoveBackward(float dt);
	void StrafeLeft(float dt);
	void StrafeRight(float dt);

	void Jump();
	void Crouch();
	void Uncrouch();

	bool m_isJumping;
	bool m_isCrouched;

	cpu_mesh m_meshPlayer;

	void WeaponEquiped(float dt);

	bool m_isWeaponEquiped = true;
	float m_weaponEquipement = 0.0f;
	float m_weaponEquipementDuration;

	void Attack();
	void RefreshAttack(float dt);

	void SwapWeapon();

	bool m_isInventoryOpened;
	bool m_isUpgradePageOpened;

	void Inventory();
	void UpgradesPage();

	int m_playerClass;

	Weapon* m_weapon1 = nullptr;
	Weapon* m_weapon2 = nullptr;

public:

	bool m_isActive = false;

	void Init(int _class);
	void Update(float dt);
	void HandleInput(float dt);

	void Destroy();

	Weapon* m_currentWeapon;

	void SetWeaponDirection();

	void SetPosition(XMFLOAT3 _position);
	XMFLOAT3 GetPosition();
};

