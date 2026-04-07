#pragma once
#include "pch.h"
#include "Weapon.h"

class Player : public AALentity
{
private:

	XMFLOAT3 m_position = {0.0f,0.0f,0.0f};

	float m_playerSize = 0.5f;

	float m_baseSpeed = 15.0f;
	float m_speed = 0.0f;
	float m_crouchedSpeed = 5.0f;

	float m_attackRefreshing = 0.0f;
	float m_attackRefreshDuration = 0.0f;

	void MouseInput();

	void MoveForward(float dt);
	void MoveBackward(float dt);
	void StrafeLeft(float dt);
	void StrafeRight(float dt);

	void Jump();
	void Crouch();
	void Uncrouch();

	bool m_isJumping = false;
	bool m_isCrouched = false;

	cpu_mesh m_meshPlayer;

	void WeaponEquiped(float dt);

	bool m_isWeaponEquiped = true;
	float m_weaponEquipement = 0.0f;
	float m_weaponEquipementDuration = 0.0f;

	void Attack();
	void RefreshAttack(float dt);

	void SwapWeapon();

	bool m_isInventoryOpened = false;
	bool m_isUpgradePageOpened = false;

	void Inventory();
	void UpgradesPage();

	int m_playerClass = 0;

	Weapon* m_weapon1 = nullptr;
	Weapon* m_weapon2 = nullptr;

public:

	bool m_isActive = false;

	~Player();
	void Init(int _class);
	void Update(float dt);
	void HandleInput(float dt);

	void Destroy();

	Weapon* m_currentWeapon = nullptr;

	void SetWeaponDirection();

	void SetPosition(XMFLOAT3 _position);
	XMFLOAT3 GetPosition();
};

