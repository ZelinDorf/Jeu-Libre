#include "pch.h"
#include "GenericSword.h"

void GenericSword::Init()
{
	m_pEntity = cpuEngine.CreateEntity();
	m_meshSword.CreateCylinder(m_swordSize, m_swordWidth, 5, true, true, CPU_BLUE);
	m_pEntity->pMesh = &m_meshSword;
}

void GenericSword::Update(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	XMFLOAT3 m_offset = XMFLOAT3(m_xDir * .5f, 0.f, m_zDir * .5f);
	m_position = XMFLOAT3(m_position.x + m_offset.x, m_position.y + m_offset.y, m_position.z + m_offset.z);
	m_pEntity->transform.pos = m_position;
}

void GenericSword::SetPosition(XMFLOAT3 _pos)
{
	m_position = _pos;
}

XMFLOAT3 GenericSword::GetPosition()
{
	return m_position;
}

void GenericSword::SetDirection(XMFLOAT3 _dir)
{
	m_pEntity->transform.dir = _dir;
}

int GenericSword::GetWeaponTypeId()
{
	return m_weaponTypeId;
}

float GenericSword::GetPulloutTime()
{
	return m_pulloutTime;
}

float GenericSword::GetSwingDamages()
{
	return m_swingDamages;
}

float GenericSword::GetSwingTime()
{
	return m_swingTime;
}

float GenericSword::GetPoundDamages()
{
	return m_poundDamages;
}

float GenericSword::GetPoundTime()
{
	return m_poundTime;
}

float GenericSword::GetPoundCooldown()
{
	return m_poundCooldown;
}

void GenericSword::Swing()
{

}

void GenericSword::Pound()
{

}

int GenericSword::GetWeaponType()
{
	return m_weaponTypeId;
}