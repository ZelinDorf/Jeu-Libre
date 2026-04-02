#pragma once
class GenericStaff
{
private:

	int mWeaponTypeId = 2;

	XMFLOAT3 mPosition;
	float mPulloutTime = 0.4f;

	float mShootingTime = 1.0f;
	float mProjectileDamages;
	float mPuddleTime = 5.0f;
	float mPuddleDamages;
	float mPuddleCooldown;

	float mSize = .5f;
	float mWidth = .1f;
	cpu_mesh m_meshStaff;
	cpu_mesh m_meshProjectile;

public:

	cpu_entity* m_pEntity = nullptr;

	bool mIsEquiped = false;

	~GenericStaff()
	{
		CPU_DELPTR(m_pEntity);
	}

	void Init();
	void Update(float dt);

	XMFLOAT3 GetPosition();
	void SetPosition(XMFLOAT3 _pos);

	void SetDirection(XMFLOAT3 _dir);

	int GetWeaponTypeId();

	float GetPulloutTime();

	float GetProjectileDamages();
	float GetShootingTime();

	float GetPuddleDamages();
	float GetPuddleTime();
	float GetPuddleCooldown();

	void Shoot();
	void Puddle();

	int GetWeaponType();
};

