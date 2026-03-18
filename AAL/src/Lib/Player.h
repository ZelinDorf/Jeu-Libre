#pragma once
#include "pch.h"

class Player
{
private:

	XMFLOAT3 mPosition;

	float mPlayerSize;

	float mBaseSpeed;
	float mSpeed;
	float mCrouchedSpeed;

	float mAttackRefreshing = 0.f;
	float mAttackRefreshDuration = 0.85f;

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

	void Attack();
	void RefreshAttack(float dt);

	void SwapWeapon();

	bool mIsInventoryOpened;
	bool mIsUpgradePageOpened;

	void Inventory();
	void UpgradesPage();

public:
	cpu_entity* m_pEntity;

	bool mIsActive = false;

	void Init();
	void Update(float dt);
	void HandleInput(float dt);

	int mCurrentWeapon = 0;

	void SetPosition(XMFLOAT3 _position);
	XMFLOAT3 GetPosition();
};

