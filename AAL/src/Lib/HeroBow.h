#pragma once
class HeroBow
{
private:

	int m_weaponTypeId = 1;

	bool m_isEquiped;

	XMFLOAT3 m_position;
	float m_pulloutTime = 0.5f;

	float m_shootingTime = 0.8f;
	float m_projectileDamages;
	float m_piercingTime = 2.0;
	float m_piercingDamages;
	float m_piercingCooldown;

	float m_size = .4f;
	float m_width = .2;
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

	void Equip();
	void Unequip();

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

