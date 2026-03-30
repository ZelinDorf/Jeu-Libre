#include "pch.h"
#include "GenericSword.h"

void GenericSword::Init()
{
	m_pEntity = cpuEngine.CreateEntity();
	m_meshSword.CreateCylinder(mSwordSize, mSwordWidth, 5, true, true, CPU_BLUE);
	m_pEntity->pMesh = &m_meshSword;
}

void GenericSword::Update(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	XMFLOAT3 m_offset = XMFLOAT3(m_xDir * .5f, 0.f, m_zDir * .5f);
	mPosition = XMFLOAT3(mPosition.x + m_offset.x, mPosition.y + m_offset.y, mPosition.z + m_offset.z);
	m_pEntity->transform.pos = mPosition;
}

void GenericSword::SetPosition(XMFLOAT3 _pos)
{
	mPosition = _pos;
}

XMFLOAT3 GenericSword::GetPosition()
{
	return mPosition;
}

void GenericSword::SetDirection(XMFLOAT3 _dir)
{
	m_pEntity->transform.dir = _dir;
}

int GenericSword::GetWeaponTypeId()
{
	return mWeaponTypeId;
}

float GenericSword::GetPulloutTime()
{
	return mPulloutTime;
}

float GenericSword::GetSwingDamages()
{
	return mSwingDamages;
}

float GenericSword::GetSwingTime()
{
	return mSwingTime;
}

void GenericSword::Swing()
{

}

void GenericSword::Pound()
{

}
