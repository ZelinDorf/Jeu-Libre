#pragma once
class Player
{
private:

	float mSpeed;

	void MouseInput();

	void MoveForward(float dt);
	void MoveBackward(float dt);
	void StrafeLeft(float dt);
	void StrafeRight(float dt);

	void Jump();
	void Crouch();

	void Attack();

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

