#include "pch.h"
#include "GenericStaff.h"

void GenericStaff::Init()
{
	m_pEntity = cpuEngine.CreateEntity();
	m_meshStaff.CreateCylinder(m_size, m_Width, 5, true, true, CPU_BLUE);
	m_pEntity->pMesh = &m_meshStaff;
}

void GenericStaff::Update(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	XMFLOAT3 m_offset = XMFLOAT3(m_xDir * .5f, 0.f, m_zDir * .5f);
	m_position = XMFLOAT3(m_position.x + m_offset.x, m_position.y + m_offset.y, m_position.z + m_offset.z);
	m_pEntity->transform.pos = m_position;
}

void GenericStaff::SetPosition(XMFLOAT3 _pos)
{
	m_position = _pos;
}

XMFLOAT3 GenericStaff::GetPosition()
{
	return m_position;
}

void GenericStaff::SetDirection(XMFLOAT3 _dir)
{
	m_pEntity->transform.dir = _dir;
}

int GenericStaff::GetWeaponTypeId()
{
	return m_weaponTypeId;
}

float GenericStaff::GetPulloutTime()
{
	return m_pulloutTime;
}

float GenericStaff::GetProjectileDamages()
{
	return m_projectileDamages;
}

float GenericStaff::GetShootingTime()
{
	return m_shootingTime;
}

float GenericStaff::GetPuddleDamages()
{
	return m_puddleDamages;
}

float GenericStaff::GetPuddleTime()
{
	return m_puddleTime;
}

float GenericStaff::GetPuddleCooldown()
{
	return m_puddleCooldown;
}

void GenericStaff::Shoot()
{

}

void GenericStaff::Puddle()
{

}

int GenericStaff::GetWeaponType()
{
	return m_weaponTypeId;
}