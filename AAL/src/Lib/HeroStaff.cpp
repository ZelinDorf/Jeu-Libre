#include "pch.h"
#include "HeroStaff.h"

void HeroStaff::Init()
{
	m_meshStaff.CreateCylinder(m_size, m_width, 5, true, true, CPU_MAGENTA);
	m_meshProjectile.CreateSphere(m_projectileSize, 3, 3, CPU_MAGENTA);
	for (int i = 0; i < 10; i++)
	{
		//m_pProjectiles[i] = nullptr;
	}
}

void HeroStaff::Update(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	/*XMFLOAT3 m_offset = XMFLOAT3(m_xDir * .5f, 0.f, m_zDir * .5f);*/
	m_position = XMFLOAT3(m_position.x + 2.f, m_position.y, m_position.z + 2.f);
	m_pEntity->transform.pos = m_position;

	/*for (int i = 0; i < 10; i++)
	{
		if (m_pProjectiles[i] != nullptr)
		{
			m_pProjectiles[i]->transform.Move(.1f);
		}
	}*/
	if (m_pProjectile != nullptr)
	{
		//m_pProjectile->transform.Move(.1f);
	}
}

void HeroStaff::Equip()
{
	m_pEntity = cpuEngine.CreateEntity();
	m_pEntity->pMesh = &m_meshStaff;
}

void HeroStaff::Unequip()
{
	m_pEntity = cpuEngine.Release(m_pEntity);
}

void HeroStaff::SetPosition(XMFLOAT3 _pos)
{
	m_position = _pos;
}

XMFLOAT3 HeroStaff::GetPosition()
{
	return m_position;
}

void HeroStaff::SetDirection(XMFLOAT3 _dir)
{
	m_pEntity->transform.dir = _dir;
}

Vector<cpu_entity*> HeroStaff::GetProjectiles()
{
	return m_pProjectiles;
}

int HeroStaff::GetWeaponTypeId()
{
	return m_weaponTypeId;
}

float HeroStaff::GetPulloutTime()
{
	return m_pulloutTime;
}

float HeroStaff::GetProjectileDamages()
{
	return m_projectileDamages;
}

float HeroStaff::GetShootingTime()
{
	return m_shootingTime;
}

float HeroStaff::GetPuddleDamages()
{
	return m_puddleDamages;
}

float HeroStaff::GetPuddleTime()
{
	return m_puddleTime;
}

float HeroStaff::GetPuddleCooldown()
{
	return m_puddleCooldown;
}

void HeroStaff::Shoot()
{
	for (int i = 0; i < 10; i++)
	{
		/*if (m_pProjectiles[i] == nullptr)
		{
			cpu_entity* projectile = cpuEngine.CreateEntity();
			projectile->pMesh = &m_meshProjectile;
			projectile->transform.dir = cpuEngine.GetCamera()->transform.dir;
			m_pProjectiles[i] = projectile;
			break;
		}*/
	}

	if (m_pProjectile == nullptr)
	{
		cpu_entity* projectile = cpuEngine.CreateEntity();
		projectile->pMesh = &m_meshProjectile;
		projectile->transform.pos = m_position;
		projectile->transform.dir = cpuEngine.GetCamera()->transform.dir;
		m_pProjectile = projectile;
	}

}

void HeroStaff::Puddle()
{

}

int HeroStaff::GetWeaponType()
{
	return m_weaponTypeId;
}