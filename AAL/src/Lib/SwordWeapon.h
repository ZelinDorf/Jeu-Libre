#pragma once
class SwordWeapon
{
private:

	int mWeaponTypeId = 0;

	XMFLOAT3 mPosition;
	float mPulloutTime = 0.5f;
	float mSwingTime = 0.85f;

	float mSwingDamages;

	float mSwordSize = .4f;
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

	float GetmPulloutTime();
	float GetSwingDamages();
	float GetSwingTime();

	void Swing();

};

