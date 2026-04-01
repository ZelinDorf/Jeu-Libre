#pragma once
class GenericBow
{
private:

	int m_WeaponTypeId = 1;

	XMFLOAT3 m_Position;
	float m_PulloutTime = 0.5f;

	float m_ShootingTime = 0.8f;
	float m_ProjectileDamages;
	float m_PiercingTime = 2.0;
	float m_PiercingDamages;
	float m_PiercingCooldown;

	float m_Size = .4f;
	float m_Width = .2;
	cpu_mesh m_meshBow;
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

	float GetPiercingDamages();
	float GetPiercingTime();
	float GetPiercingCooldown();

	void Shoot();
	void Pierce();

	int GetWeaponType();

};

