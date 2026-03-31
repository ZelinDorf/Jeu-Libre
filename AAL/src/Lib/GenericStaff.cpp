#include "pch.h"
#include "GenericStaff.h"

void GenericStaff::Init()
{
	m_pEntity = cpuEngine.CreateEntity();
	m_meshStaff.CreateCylinder(mSize, mWidth, 5, true, true, CPU_BLUE);
	m_pEntity->pMesh = &m_meshStaff;
}

void GenericStaff::Update(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	XMFLOAT3 m_offset = XMFLOAT3(m_xDir * .5f, 0.f, m_zDir * .5f);
	mPosition = XMFLOAT3(mPosition.x + m_offset.x, mPosition.y + m_offset.y, mPosition.z + m_offset.z);
	m_pEntity->transform.pos = mPosition;
}

void GenericStaff::SetPosition(XMFLOAT3 _pos)
{
	mPosition = _pos;
}

XMFLOAT3 GenericStaff::GetPosition()
{
	return mPosition;
}

void GenericStaff::SetDirection(XMFLOAT3 _dir)
{
	m_pEntity->transform.dir = _dir;
}

int GenericStaff::GetWeaponTypeId()
{
	return mWeaponTypeId;
}

float GenericStaff::GetPulloutTime()
{
	return mPulloutTime;
}

float GenericStaff::GetProjectileDamages()
{
	return mProjectileDamages;
}

float GenericStaff::GetShootingTime()
{
	return mShootingTime;
}

float GenericStaff::GetPuddleDamages()
{
	return mPuddleDamages;
}

float GenericStaff::GetPuddleTime()
{
	return mPuddleTime;
}

float GenericStaff::GetPuddleCooldown()
{
	return mPuddleCooldown;
}

void GenericStaff::Shoot()
{

}

void GenericStaff::Puddle()
{

}

int GenericStaff::GetWeaponType()
{
	return mWeaponTypeId;
}