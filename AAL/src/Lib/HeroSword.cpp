#include "pch.h"
#include "HeroSword.h"
#include "Player.h"

void HeroSword::Init()
{
	m_meshSword.CreateCylinder(m_swordSize, m_swordWidth, 5, true, true, CPU_ORANGE);
}

void HeroSword::Update(float dt)
{

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

void HeroSword::SetPosition(XMFLOAT3 &_pos)
{
	XMFLOAT3 pos = { 80,0,80 };
	m_pEntity->transform.SetPosition(_pos);

	//m_pEntity->transform.OrbitAroundAxis(_pos, CPU_VEC3_UP, 2.f, /*cpuTime.delta * */ 5.0f);
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