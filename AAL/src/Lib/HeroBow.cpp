#include "pch.h"
#include "HeroBow.h"

void HeroBow::Init()
{
	m_pEntity = cpuEngine.CreateEntity();
	m_meshBow.CreateCylinder(mSize, mWidth, 5, true, true, CPU_BLUE);
	m_pEntity->pMesh = &m_meshBow;
}

void HeroBow::Update(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	XMFLOAT3 m_offset = XMFLOAT3(m_xDir * .5f, 0.f, m_zDir * .5f);
	mPosition = XMFLOAT3(mPosition.x + m_offset.x, mPosition.y + m_offset.y, mPosition.z + m_offset.z);
	m_pEntity->transform.pos = mPosition;
}

void HeroBow::SetPosition(XMFLOAT3 _pos)
{
	mPosition = _pos;
}

XMFLOAT3 HeroBow::GetPosition()
{
	return mPosition;
}

void HeroBow::SetDirection(XMFLOAT3 _dir)
{
	m_pEntity->transform.dir = _dir;
}

int HeroBow::GetWeaponTypeId()
{
	return mWeaponTypeId;
}

float HeroBow::GetPulloutTime()
{
	return mPulloutTime;
}

float HeroBow::GetProjectileDamages()
{
	return mProjectileDamages;
}

float HeroBow::GetShootingTime()
{
	return mShootingTime;
}

void HeroBow::Shoot()
{

}

void HeroBow::Pierce()
{

}