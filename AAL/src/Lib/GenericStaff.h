#pragma once
class GenericStaff
{
private:

	int m_WeaponTypeId = 2;

	XMFLOAT3 m_Position;
	float m_PulloutTime = 0.4f;

	float m_ShootingTime = 1.0f;
	float m_ProjectileDamages;
	float m_PuddleTime = 5.0f;
	float m_PuddleDamages;
	float m_PuddleCooldown;

	float m_Size = .5f;
	float m_Width = .1;
	cpu_mesh m_meshStaff;
	cpu_mesh m_meshProjectile;

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

	float GetProjectileDamages();
	float GetShootingTime();

	float GetPuddleDamages();
	float GetPuddleTime();
	float GetPuddleCooldown();

	void Shoot();
	void Puddle();

	int GetWeaponType();
};

