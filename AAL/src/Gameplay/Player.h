#pragma once
class Player
{
private:

	float mSpeed;

	void MoveForward(float dt);
	void MoveBackward(float dt);
	void StrafeLeft(float dt);
	void StrafeRight(float dt);

	void Jump();
	void Crouch();

	void Attack();

	void SwapWeapon();

	bool IsInventoryOpened;
	bool IsUpgradePageOpened;

	void Inventory();
	void UpgradesPage();

public:
	bool mIsActive = false;

	void Init();
	void Update(float dt);
	void HandleInut(float dt);

	
};

