#pragma once
class HeroSword
{
private:

	int mWeaponTypeId = 0;

	XMFLOAT3 mPosition = {0.0f,0.0f,0.0f};
	float mPulloutTime = 0.3f;

	float mSwingTime = 0.6f;
	float mSwingDamages = 0.0f;
	float mPoundTime = 1.0f;
	float mPoundDamages = 0.0f;
	float mPoundCooldown = 0.0f;


	float mSwordSize = .5f;
	float mSwordWidth = .1f;
	cpu_mesh m_meshSword;

public:

	cpu_entity* m_pEntity = nullptr;

	bool mIsEquiped = false;

	~HeroSword()
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

	float GetSwingDamages();
	float GetSwingTime();

	float GetPoundDamages();
	float GetPoundTime();
	float GetPoundCooldown();

	void Swing();
	void Pound();

	int GetWeaponType();
};

