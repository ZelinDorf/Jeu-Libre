#include "pch.h"
#include "GenericBow.h"
#include "HeroBow.h"

GenericBow::~GenericBow()
{
	CPU_DELPTR(m_pEntity);
}

void GenericBow::Init()
{
	m_pEntity = cpuEngine.CreateEntity();
	m_meshBow.CreateCylinder(mSize, mWidth, 5, true, true, CPU_BLUE);
	m_pEntity->pMesh = &m_meshBow;
}

void GenericBow::Update(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	XMFLOAT3 m_offset = XMFLOAT3(m_xDir * .5f, 0.f, m_zDir * .5f);
	mPosition = XMFLOAT3(mPosition.x + m_offset.x, mPosition.y + m_offset.y, mPosition.z + m_offset.z);
	m_pEntity->transform.pos = mPosition;
}

void GenericBow::SetPosition(XMFLOAT3 _pos)
{
	mPosition = _pos;
}

XMFLOAT3 GenericBow::GetPosition()
{
	return mPosition;
}

void GenericBow::SetDirection(XMFLOAT3 _dir)
{
	m_pEntity->transform.dir = _dir;
}

int GenericBow::GetWeaponTypeId()
{
	return mWeaponTypeId;
}

float GenericBow::GetPulloutTime()
{
	return mPulloutTime;
}

float GenericBow::GetProjectileDamages()
{
	return mProjectileDamages;
}

float GenericBow::GetShootingTime()
{
	return mShootingTime;
}

float GenericBow::GetPiercingDamages()
{
	return mPiercingDamages;
}

float GenericBow::GetPiercingTime()
{
	return mPiercingTime;
}

float GenericBow::GetPiercingCooldown()
{
	return mPiercingCooldown;
}

void GenericBow::Shoot()
{

}

void GenericBow::Pierce()
{

}

int GenericBow::GetWeaponType()
{
	return mWeaponTypeId;
}