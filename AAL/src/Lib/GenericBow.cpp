#include "pch.h"
#include "GenericBow.h"
#include "HeroBow.h"

void GenericBow::Init()
{
	m_meshBow.CreateCylinder(m_size, m_width, 5, true, true, CPU_BLUE);
}

void GenericBow::Update(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	XMFLOAT3 m_offset = XMFLOAT3(m_xDir * .5f, 0.f, m_zDir * .5f);
	m_position = XMFLOAT3(m_position.x + m_offset.x, m_position.y + m_offset.y, m_position.z + m_offset.z);
	m_pEntity->transform.pos = m_position;
}

void GenericBow::Equip()
{
	m_pEntity = cpuEngine.CreateEntity();
	m_pEntity->pMesh = &m_meshBow;
}

void GenericBow::Unequip()
{
	m_pEntity = cpuEngine.Release(m_pEntity);
}

void GenericBow::SetPosition(XMFLOAT3 _pos)
{
	m_position = _pos;
}

XMFLOAT3 GenericBow::GetPosition()
{
	return m_position;
}

void GenericBow::SetDirection(XMFLOAT3 _dir)
{
	m_pEntity->transform.dir = _dir;
}

int GenericBow::GetWeaponTypeId()
{
	return m_weaponTypeId;
}

float GenericBow::GetPulloutTime()
{
	return m_pulloutTime;
}

float GenericBow::GetProjectileDamages()
{
	return m_projectileDamages;
}

float GenericBow::GetShootingTime()
{
	return m_shootingTime;
}

float GenericBow::GetPiercingDamages()
{
	return m_piercingDamages;
}

float GenericBow::GetPiercingTime()
{
	return m_piercingTime;
}

float GenericBow::GetPiercingCooldown()
{
	return m_piercingCooldown;
}

void GenericBow::Shoot()
{

}

void GenericBow::Pierce()
{

}

int GenericBow::GetWeaponType()
{
	return m_weaponTypeId;
}