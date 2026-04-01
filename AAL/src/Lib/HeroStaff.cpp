#include "pch.h"
#include "HeroStaff.h"

void HeroStaff::Init()
{
	m_pEntity = cpuEngine.CreateEntity();
	m_meshStaff.CreateCylinder(m_Size, m_Width, 5, true, true, CPU_BLUE);
	m_pEntity->pMesh = &m_meshStaff;
}

void HeroStaff::Update(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	XMFLOAT3 m_offset = XMFLOAT3(m_xDir * .5f, 0.f, m_zDir * .5f);
	m_Position = XMFLOAT3(m_Position.x + m_offset.x, m_Position.y + m_offset.y, m_Position.z + m_offset.z);
	m_pEntity->transform.pos = m_Position;
}

void HeroStaff::SetPosition(XMFLOAT3 _pos)
{
	m_Position = _pos;
}

XMFLOAT3 HeroStaff::GetPosition()
{
	return m_Position;
}

void HeroStaff::SetDirection(XMFLOAT3 _dir)
{
	m_pEntity->transform.dir = _dir;
}

int HeroStaff::GetWeaponTypeId()
{
	return m_WeaponTypeId;
}

float HeroStaff::GetPulloutTime()
{
	return m_PulloutTime;
}

float HeroStaff::GetProjectileDamages()
{
	return m_ProjectileDamages;
}

float HeroStaff::GetShootingTime()
{
	return m_ShootingTime;
}

float HeroStaff::GetPuddleDamages()
{
	return m_PuddleDamages;
}

float HeroStaff::GetPuddleTime()
{
	return m_PuddleTime;
}

float HeroStaff::GetPuddleCooldown()
{
	return m_PuddleCooldown;
}

void HeroStaff::Shoot()
{

}

void HeroStaff::Puddle()
{

}

int HeroStaff::GetWeaponType()
{
	return m_WeaponTypeId;
}