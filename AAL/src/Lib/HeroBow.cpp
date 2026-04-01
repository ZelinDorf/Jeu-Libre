#include "pch.h"
#include "HeroBow.h"

void HeroBow::Init()
{
	m_pEntity = cpuEngine.CreateEntity();
	m_meshBow.CreateCylinder(m_Size, m_Width, 5, true, true, CPU_BLUE);
	m_pEntity->pMesh = &m_meshBow;
}

void HeroBow::Update(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	XMFLOAT3 m_offset = XMFLOAT3(m_xDir * .5f, 0.f, m_zDir * .5f);
	m_Position = XMFLOAT3(m_Position.x + m_offset.x, m_Position.y + m_offset.y, m_Position.z + m_offset.z);
	m_pEntity->transform.pos = m_Position;
}

void HeroBow::SetPosition(XMFLOAT3 _pos)
{
	m_Position = _pos;
}

XMFLOAT3 HeroBow::GetPosition()
{
	return m_Position;
}

void HeroBow::SetDirection(XMFLOAT3 _dir)
{
	m_pEntity->transform.dir = _dir;
}

int HeroBow::GetWeaponTypeId()
{
	return m_WeaponTypeId;
}

float HeroBow::GetPulloutTime()
{
	return m_PulloutTime;
}

float HeroBow::GetProjectileDamages()
{
	return m_ProjectileDamages;
}

float HeroBow::GetShootingTime()
{
	return m_ShootingTime;
}

float HeroBow::GetPiercingDamages()
{
	return m_PiercingDamages;
}

float HeroBow::GetPiercingTime()
{
	return m_PiercingTime;
}

float HeroBow::GetPiercingCooldown()
{
	return m_PiercingCooldown;
}

void HeroBow::Shoot()
{

}

void HeroBow::Pierce()
{

}

int HeroBow::GetWeaponType()
{
	return m_WeaponTypeId;
}