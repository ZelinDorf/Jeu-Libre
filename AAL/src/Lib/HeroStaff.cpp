#include "pch.h"
#include "HeroStaff.h"

void HeroStaff::Init()
{
	m_pEntity = cpuEngine.CreateEntity();
	m_meshStaff.CreateCylinder(mSize, mWidth, 5, true, true, CPU_BLUE);
	m_pEntity->pMesh = &m_meshStaff;
}

void HeroStaff::Update(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	XMFLOAT3 m_offset = XMFLOAT3(m_xDir * .5f, 0.f, m_zDir * .5f);
	mPosition = XMFLOAT3(mPosition.x + m_offset.x, mPosition.y + m_offset.y, mPosition.z + m_offset.z);
	m_pEntity->transform.pos = mPosition;
}

void HeroStaff::SetPosition(XMFLOAT3 _pos)
{
	mPosition = _pos;
}

XMFLOAT3 HeroStaff::GetPosition()
{
	return mPosition;
}

void HeroStaff::SetDirection(XMFLOAT3 _dir)
{
	m_pEntity->transform.dir = _dir;
}

int HeroStaff::GetWeaponTypeId()
{
	return mWeaponTypeId;
}

float HeroStaff::GetPulloutTime()
{
	return mPulloutTime;
}

float HeroStaff::GetProjectileDamages()
{
	return mProjectileDamages;
}

float HeroStaff::GetShootingTime()
{
	return mShootingTime;
}

float HeroStaff::GetPuddleDamages()
{
	return mPuddleDamages;
}

float HeroStaff::GetPuddleTime()
{
	return mPuddleTime;
}

float HeroStaff::GetPuddleCooldown()
{
	return mPuddleCooldown;
}

void HeroStaff::Shoot()
{

}

void HeroStaff::Puddle()
{

}

int HeroStaff::GetWeaponType()
{
	return mWeaponTypeId;
}