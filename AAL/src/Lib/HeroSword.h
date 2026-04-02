#pragma once
class HeroSword
{
private:

	int m_weaponTypeId = 0;

	XMFLOAT3 m_position;
	float m_pulloutTime = 0.3f;

	float m_swingTime = 0.6f;
	float m_swingDamages;
	float m_poundTime = 1.0f;
	float m_poundDamages;
	float m_poundCooldown;


	float m_swordSize = .5f;
	float m_swordWidth = .1;
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

