#include "pch.h"
#include "HeroSword.h"

void HeroSword::Init()
{
	m_meshSword.CreateCylinder(m_swordSize, m_swordWidth, 5, true, true, CPU_BLUE);
}

void HeroSword::Update(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	XMFLOAT3 m_offset = XMFLOAT3(m_xDir * .5f, 0.f, m_zDir * .5f);
	m_position = XMFLOAT3(m_position.x + m_offset.x, m_position.y + m_offset.y, m_position.z + m_offset.z);
	m_pEntity->transform.pos = m_position;
}

void HeroSword::Equip() 
{
	m_pEntity = cpuEngine.CreateEntity();
	m_pEntity->pMesh = &m_meshSword;
}

void HeroSword::Unequip()
{
	m_pEntity = cpuEngine.Release(m_pEntity);
}

void HeroSword::SetPosition(XMFLOAT3 _pos)
{
	m_position = _pos;
}

XMFLOAT3 HeroSword::GetPosition()
{
	return m_position;
}

void HeroSword::SetDirection(XMFLOAT3 _dir)
{
	m_pEntity->transform.dir = _dir;
}

int HeroSword::GetWeaponTypeId()
{
	return m_weaponTypeId;
}

float HeroSword::GetPulloutTime()
{
	return m_pulloutTime;
}

float HeroSword::GetSwingDamages()
{
	return m_swingDamages;
}

float HeroSword::GetSwingTime()
{
	return m_swingTime;
}

float HeroSword::GetPoundDamages()
{
	return m_poundDamages;
}

float HeroSword::GetPoundTime()
{
	return m_poundTime;
}

float HeroSword::GetPoundCooldown()
{
	return m_poundCooldown;
}

void HeroSword::Swing()
{

}

void HeroSword::Pound()
{

}

int HeroSword::GetWeaponType()
{
	return m_weaponTypeId;
}