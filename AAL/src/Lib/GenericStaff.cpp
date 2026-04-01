#include "pch.h"
#include "GenericStaff.h"

void GenericStaff::Init()
{
	m_pEntity = cpuEngine.CreateEntity();
	m_meshStaff.CreateCylinder(m_Size, m_Width, 5, true, true, CPU_BLUE);
	m_pEntity->pMesh = &m_meshStaff;
}

void GenericStaff::Update(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	XMFLOAT3 m_offset = XMFLOAT3(m_xDir * .5f, 0.f, m_zDir * .5f);
	m_Position = XMFLOAT3(m_Position.x + m_offset.x, m_Position.y + m_offset.y, m_Position.z + m_offset.z);
	m_pEntity->transform.pos = m_Position;
}

void GenericStaff::SetPosition(XMFLOAT3 _pos)
{
	m_Position = _pos;
}

XMFLOAT3 GenericStaff::GetPosition()
{
	return m_Position;
}

void GenericStaff::SetDirection(XMFLOAT3 _dir)
{
	m_pEntity->transform.dir = _dir;
}

int GenericStaff::GetWeaponTypeId()
{
	return m_WeaponTypeId;
}

float GenericStaff::GetPulloutTime()
{
	return m_PulloutTime;
}

float GenericStaff::GetProjectileDamages()
{
	return m_ProjectileDamages;
}

float GenericStaff::GetShootingTime()
{
	return m_ShootingTime;
}

float GenericStaff::GetPuddleDamages()
{
	return m_PuddleDamages;
}

float GenericStaff::GetPuddleTime()
{
	return m_PuddleTime;
}

float GenericStaff::GetPuddleCooldown()
{
	return m_PuddleCooldown;
}

void GenericStaff::Shoot()
{

}

void GenericStaff::Puddle()
{

}

int GenericStaff::GetWeaponType()
{
	return m_WeaponTypeId;
}