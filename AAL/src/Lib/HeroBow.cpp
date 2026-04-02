#include "pch.h"
#include "HeroBow.h"

void HeroBow::Init()
{
	m_pEntity = cpuEngine.CreateEntity();
	m_meshBow.CreateCylinder(m_size, m_Width, 5, true, true, CPU_BLUE);
	m_pEntity->pMesh = &m_meshBow;
}

void HeroBow::Update(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	XMFLOAT3 m_offset = XMFLOAT3(m_xDir * .5f, 0.f, m_zDir * .5f);
	m_position = XMFLOAT3(m_position.x + m_offset.x, m_position.y + m_offset.y, m_position.z + m_offset.z);
	m_pEntity->transform.pos = m_position;
}

void HeroBow::SetPosition(XMFLOAT3 _pos)
{
	m_position = _pos;
}

XMFLOAT3 HeroBow::GetPosition()
{
	return m_position;
}

void HeroBow::SetDirection(XMFLOAT3 _dir)
{
	m_pEntity->transform.dir = _dir;
}

int HeroBow::GetWeaponTypeId()
{
	return m_weaponTypeId;
}

float HeroBow::GetPulloutTime()
{
	return m_pulloutTime;
}

float HeroBow::GetProjectileDamages()
{
	return m_projectileDamages;
}

float HeroBow::GetShootingTime()
{
	return m_shootingTime;
}

float HeroBow::GetPiercingDamages()
{
	return m_piercingDamages;
}

float HeroBow::GetPiercingTime()
{
	return m_piercingTime;
}

float HeroBow::GetPiercingCooldown()
{
	return m_piercingCooldown;
}

void HeroBow::Shoot()
{

}

void HeroBow::Pierce()
{

}

int HeroBow::GetWeaponType()
{
	return m_weaponTypeId;
}