#pragma once
class HeroStaff
{
private:

	int mWeaponTypeId = 2;

	XMFLOAT3 mPosition;
	float mPulloutTime = 0.4f;
	float mShootingTime = 1.0f;

	float mProjectileDamages;

	float mSize = .5f;
	float mWidth = .1;
	cpu_mesh m_meshStaff;
	cpu_mesh m_meshProjectile;

public:

	cpu_entity* m_pEntity;

	bool mIsEquiped = false;

	void Init();
	void Update(float dt);

	XMFLOAT3 GetPosition();
	void SetPosition(XMFLOAT3 _pos);

	void SetDirection(XMFLOAT3 _dir);

	int GetWeaponTypeId();

	float GetPulloutTime();
	float GetProjectileDamages();
	float GetShootingTime();

	void Shoot();
	void Puddle();
};

