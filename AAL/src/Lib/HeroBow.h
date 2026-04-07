#pragma once
class HeroBow
{
private:

	int mWeaponTypeId = 1;

	XMFLOAT3 mPosition = {0.0f,0.0f,0.0f};
	float mPulloutTime = 0.5f;

	float mShootingTime = 0.8f;
	float mProjectileDamages;
	float mPiercingTime = 2.0;
	float mPiercingDamages = 0.0f;
	float mPiercingCooldown = 0.0f;

	float mSize = .4f;
	float mWidth = .2f;
	cpu_mesh m_meshBow;
	cpu_mesh m_meshProjectile;

public:

	cpu_entity* m_pEntity = nullptr;;

	bool mIsEquiped = false;

	~HeroBow()
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

	float GetPiercingDamages();
	float GetPiercingTime();
	float GetPiercingCooldown();

	void Shoot();
	void Pierce();

	int GetWeaponType();
};

