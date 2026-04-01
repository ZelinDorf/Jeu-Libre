#include "pch.h"
#include "HeroSword.h"

void HeroSword::Init()
{
	m_pEntity = cpuEngine.CreateEntity();
	m_meshSword.CreateCylinder(m_SwordSize, m_SwordWidth, 5, true, true, CPU_BLUE);
	m_pEntity->pMesh = &m_meshSword;
}

void HeroSword::Update(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	XMFLOAT3 m_offset = XMFLOAT3(m_xDir * .5f, 0.f, m_zDir * .5f);
	m_Position = XMFLOAT3(m_Position.x + m_offset.x, m_Position.y + m_offset.y, m_Position.z + m_offset.z);
	m_pEntity->transform.pos = m_Position;
}

void HeroSword::SetPosition(XMFLOAT3 _pos)
{
	m_Position = _pos;
}

XMFLOAT3 HeroSword::GetPosition()
{
	return m_Position;
}

void HeroSword::SetDirection(XMFLOAT3 _dir)
{
	m_pEntity->transform.dir = _dir;
}

int HeroSword::GetWeaponTypeId()
{
	return m_WeaponTypeId;
}

float HeroSword::GetPulloutTime()
{
	return m_PulloutTime;
}

float HeroSword::GetSwingDamages()
{
	return m_SwingDamages;
}

float HeroSword::GetSwingTime()
{
	return m_SwingTime;
}

float HeroSword::GetPoundDamages()
{
	return m_PoundDamages;
}

float HeroSword::GetPoundTime()
{
	return m_PoundTime;
}

float HeroSword::GetPoundCooldown()
{
	return m_PoundCooldown;
}

void HeroSword::Swing()
{

}

void HeroSword::Pound()
{

}

int HeroSword::GetWeaponType()
{
	return m_WeaponTypeId;
}