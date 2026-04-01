#include "pch.h"
#include "GenericBow.h"
#include "HeroBow.h"

void GenericBow::Init()
{
	m_pEntity = cpuEngine.CreateEntity();
	m_meshBow.CreateCylinder(m_Size, m_Width, 5, true, true, CPU_BLUE);
	m_pEntity->pMesh = &m_meshBow;
}

void GenericBow::Update(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	XMFLOAT3 m_offset = XMFLOAT3(m_xDir * .5f, 0.f, m_zDir * .5f);
	m_Position = XMFLOAT3(m_Position.x + m_offset.x, m_Position.y + m_offset.y, m_Position.z + m_offset.z);
	m_pEntity->transform.pos = m_Position;
}

void GenericBow::SetPosition(XMFLOAT3 _pos)
{
	m_Position = _pos;
}

XMFLOAT3 GenericBow::GetPosition()
{
	return m_Position;
}

void GenericBow::SetDirection(XMFLOAT3 _dir)
{
	m_pEntity->transform.dir = _dir;
}

int GenericBow::GetWeaponTypeId()
{
	return m_WeaponTypeId;
}

float GenericBow::GetPulloutTime()
{
	return m_PulloutTime;
}

float GenericBow::GetProjectileDamages()
{
	return m_ProjectileDamages;
}

float GenericBow::GetShootingTime()
{
	return m_ShootingTime;
}

float GenericBow::GetPiercingDamages()
{
	return m_PiercingDamages;
}

float GenericBow::GetPiercingTime()
{
	return m_PiercingTime;
}

float GenericBow::GetPiercingCooldown()
{
	return m_PiercingCooldown;
}

void GenericBow::Shoot()
{

}

void GenericBow::Pierce()
{

}

int GenericBow::GetWeaponType()
{
	return m_WeaponTypeId;
}