#pragma once
class Player
{
private:

	float mBaseSpeed;
	float mSpeed;

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

	bool mIsCrouched;

	void Attack();
	void RefreshAttack(float dt);

	void SwapWeapon();

	bool mIsInventoryOpened;
	bool mIsUpgradePageOpened;

	void Inventory();
	void UpgradesPage();

public:
	bool mIsActive = false;

	void Init();
	void Update(float dt);
	void HandleInput(float dt);

	int mCurrentWeapon = 0;
};

