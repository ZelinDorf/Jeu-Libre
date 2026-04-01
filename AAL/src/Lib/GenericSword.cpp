#include "pch.h"
#include "GenericSword.h"

void GenericSword::Init()
{
	m_pEntity = cpuEngine.CreateEntity();
	m_meshSword.CreateCylinder(m_SwordSize, m_SwordWidth, 5, true, true, CPU_BLUE);
	m_pEntity->pMesh = &m_meshSword;
}

void GenericSword::Update(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	XMFLOAT3 m_offset = XMFLOAT3(m_xDir * .5f, 0.f, m_zDir * .5f);
	m_Position = XMFLOAT3(m_Position.x + m_offset.x, m_Position.y + m_offset.y, m_Position.z + m_offset.z);
	m_pEntity->transform.pos = m_Position;
}

void GenericSword::SetPosition(XMFLOAT3 _pos)
{
	m_Position = _pos;
}

XMFLOAT3 GenericSword::GetPosition()
{
	return m_Position;
}

void GenericSword::SetDirection(XMFLOAT3 _dir)
{
	m_pEntity->transform.dir = _dir;
}

int GenericSword::GetWeaponTypeId()
{
	return m_WeaponTypeId;
}

float GenericSword::GetPulloutTime()
{
	return m_PulloutTime;
}

float GenericSword::GetSwingDamages()
{
	return m_SwingDamages;
}

float GenericSword::GetSwingTime()
{
	return m_SwingTime;
}

float GenericSword::GetPoundDamages()
{
	return m_PoundDamages;
}

float GenericSword::GetPoundTime()
{
	return m_PoundTime;
}

float GenericSword::GetPoundCooldown()
{
	return m_PoundCooldown;
}

void GenericSword::Swing()
{

}

void GenericSword::Pound()
{

}

int GenericSword::GetWeaponType()
{
	return m_WeaponTypeId;
}