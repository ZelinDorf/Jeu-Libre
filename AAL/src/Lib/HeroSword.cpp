#include "pch.h"
#include "HeroSword.h"

void HeroSword::Init()
{
	m_pEntity = cpuEngine.CreateEntity();
	m_meshSword.CreateCylinder(mSwordSize, mSwordWidth, 5, true, true, CPU_BLUE);
	m_pEntity->pMesh = &m_meshSword;
}

void HeroSword::Update(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	XMFLOAT3 m_offset = XMFLOAT3(m_xDir * .5f, 0.f, m_zDir * .5f);
	mPosition = XMFLOAT3(mPosition.x + m_offset.x, mPosition.y + m_offset.y, mPosition.z + m_offset.z);
	m_pEntity->transform.pos = mPosition;
}

void HeroSword::SetPosition(XMFLOAT3 _pos)
{
	mPosition = _pos;
}

XMFLOAT3 HeroSword::GetPosition()
{
	return mPosition;
}

void HeroSword::SetDirection(XMFLOAT3 _dir)
{
	m_pEntity->transform.dir = _dir;
}

int HeroSword::GetWeaponTypeId()
{
	return mWeaponTypeId;
}

float HeroSword::GetPulloutTime()
{
	return mPulloutTime;
}

float HeroSword::GetSwingDamages()
{
	return mSwingDamages;
}

float HeroSword::GetSwingTime()
{
	return mSwingTime;
}

void HeroSword::Swing()
{

}

void HeroSword::Pound()
{

}