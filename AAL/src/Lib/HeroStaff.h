#pragma once
class HeroStaff : public AALentity
{
private:

	int m_weaponTypeId = 2;

	bool m_isEquiped;

	XMFLOAT3 m_position;
	float m_pulloutTime = 0.4f;

	float m_shootingTime = 1.0f;
	float m_projectileDamages;
	float m_puddleTime = 5.0f;
	float m_puddleDamages;
	float m_puddleCooldown;

	float m_size = .5f;
	float m_width = .1;
	cpu_mesh m_meshStaff;
	cpu_mesh m_meshProjectile;

public:

	bool mIsEquiped = false;

	~HeroStaff()
	{
		CPU_DELPTR(m_pEntity);
	}
	void Init();
	void Update(float dt);

	void Equip();
	void Unequip();

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

