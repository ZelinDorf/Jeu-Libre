#pragma once
#include "pch.h"
#include "PlayerWeapon.h"

class Player
{
private:

	XMFLOAT3 mPosition;

	float mPlayerSize = .5f;

	float mBaseSpeed = 15;
	float mSpeed;
	float mCrouchedSpeed = 5;

	float mAttackRefreshing = 0.f;
	float mAttackRefreshDuration;

	void MouseInput();

	void MoveForward(float dt);
	void MoveBackward(float dt);
	void StrafeLeft(float dt);
	void StrafeRight(float dt);

	void Jump();
	void Crouch();
	void Uncrouch();

	bool mIsJumping;
	bool mIsCrouched;

	cpu_mesh m_meshPlayer;

	void WeaponEquiped(float dt);

	bool mIsWeaponEquiped = true;
	float mWeaponEquipement = 0.0f;
	float mWeaponEquipementDuration;

	void Attack();
	void RefreshAttack(float dt);

	void SwapWeapon();

	bool mIsInventoryOpened;
	bool mIsUpgradePageOpened;

	void Inventory();
	void UpgradesPage();

	PlayerWeapon* mPlayerWeapon;

public:
	cpu_entity* m_pEntity;

	bool mIsActive = false;

	void Init();
	void Update(float dt);
	void HandleInput(float dt);

	void Destroy();

	PlayerWeapon* mEquipedWeapon = nullptr;
	PlayerWeapon* mAltWeapon = nullptr;

	void SetWeaponDirection();

	void SetPosition(XMFLOAT3 _position);
	XMFLOAT3 GetPosition();
};

