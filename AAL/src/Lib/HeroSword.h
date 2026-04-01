#pragma once
class HeroSword
{
private:

	int m_WeaponTypeId = 0;

	XMFLOAT3 m_Position;
	float m_PulloutTime = 0.3f;

	float m_SwingTime = 0.6f;
	float m_SwingDamages;
	float m_PoundTime = 1.0f;
	float m_PoundDamages;
	float m_PoundCooldown;


	float m_SwordSize = .5f;
	float m_SwordWidth = .1;
	cpu_mesh m_meshSword;

public:

	cpu_entity* m_pEntity;

	bool m_IsEquiped = false;

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

