#pragma once
#include "pch.h"
#include "Weapon.h"

class Player : public AALentity
{
private:
	inline static Player* s_pInstance = nullptr;

	inline static XMFLOAT3 m_position = {80.0f,0.0f,80.0f};

	inline static float m_playerSize = 0.5f;

	inline static float m_baseSpeed = 15.0f;
	inline static float m_speed = 0.0f;
	inline static float m_crouchedSpeed = 5.0f;

	inline static float m_attackRefreshing = 0.0f;
	inline static float m_attackRefreshDuration = 0.0f;

	static void MouseInput();
	
	static void MoveForward(float dt);
	static void MoveBackward(float dt);
	static void StrafeLeft(float dt);
	static void StrafeRight(float dt);

	static void Jump();
	static void Crouch();
	static void Uncrouch();
	 
	inline static bool m_isJumping = false;
	inline static bool m_isCrouched = false;

	cpu_mesh m_meshPlayer;

	static void WeaponEquiped(float dt);

	inline static bool m_isWeaponEquiped = true;
	inline static float m_weaponEquipement = 0.0f;
	inline static float m_weaponEquipementDuration = 0.0f;

	static void Attack();
	static void RefreshAttack(float dt);

	static void SwapWeapon();

	inline static bool m_isInventoryOpened = false;
	inline static bool m_isUpgradePageOpened = false;

	static void Inventory();
	static void UpgradesPage();

	inline static int m_playerClass = 0;

	inline static Weapon* m_weapon1 = nullptr;
	inline static Weapon* m_weapon2 = nullptr;

public:

	inline static bool m_isActive = false;

	Player();
	~Player();
	static void Init(int _class);
	void Update(float dt) override;
	static void HandleInput(float dt);

	static void Destroy();

	inline static Weapon* m_currentWeapon = nullptr;

	static void SetWeaponDirection();

	static void SetPosition(XMFLOAT3 _position);
	static XMFLOAT3 GetPosition();
};

