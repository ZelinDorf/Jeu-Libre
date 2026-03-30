#pragma once
class HeroSword
{
private:

	int mWeaponTypeId = 0;

	XMFLOAT3 mPosition;
	float mPulloutTime = 0.3f;
	float mSwingTime = 0.6f;

	float mSwingDamages;

	float mSwordSize = .5f;
	float mSwordWidth = .1;
	cpu_mesh m_meshSword;

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
	float GetSwingDamages();
	float GetSwingTime();

	void Swing();
	void Pound();
};

