#include "pch.h"
#include "HeroStaff.h"

void HeroStaff::Init()
{
	m_pEntity = cpuEngine.CreateEntity();
	m_meshStaff.CreateCylinder(m_size, m_Width, 5, true, true, CPU_BLUE);
	m_pEntity->pMesh = &m_meshStaff;
}

void HeroStaff::Update(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	XMFLOAT3 m_offset = XMFLOAT3(m_xDir * .5f, 0.f, m_zDir * .5f);
	m_position = XMFLOAT3(m_position.x + m_offset.x, m_position.y + m_offset.y, m_position.z + m_offset.z);
	m_pEntity->transform.pos = m_position;
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

}

void HeroStaff::Puddle()
{

}

int HeroStaff::GetWeaponType()
{
	return m_weaponTypeId;
}