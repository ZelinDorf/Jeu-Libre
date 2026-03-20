#include "pch.h"
#include "SwordWeapon.h"

void SwordWeapon::Init()
{
	m_pEntity = cpuEngine.CreateEntity();
	m_meshSword.CreateCylinder(mSwordSize, mSwordWidth, 5, true, true, CPU_BLUE);
	m_pEntity->pMesh = &m_meshSword;
}

void SwordWeapon::Update(float dt)
{
	float m_xDir = m_pEntity->transform.dir.x;
	float m_zDir = m_pEntity->transform.dir.z;

	XMFLOAT3 m_offset = XMFLOAT3(m_xDir * .5f, 0.f, m_zDir * .5f);
	mPosition = XMFLOAT3(mPosition.x + m_offset.x, mPosition.y + m_offset.y, mPosition.z + m_offset.z);
	m_pEntity->transform.pos = mPosition;
}

void SwordWeapon::SetPosition(XMFLOAT3 _pos)
{
	mPosition = _pos;
}

XMFLOAT3 SwordWeapon::GetPosition()
{
	return mPosition;
}

void SwordWeapon::SetDirection(XMFLOAT3 _dir)
{
	m_pEntity->transform.dir = _dir;
}

int SwordWeapon::GetWeaponTypeId()
{
	return mWeaponTypeId;
}

float SwordWeapon::GetmPulloutTime()
{
	return mPulloutTime;
}

float SwordWeapon::GetSwingDamages()
{
	return mSwingDamages;
}

float SwordWeapon::GetSwingTime()
{
	return mSwingTime;
}

void SwordWeapon::Swing()
{

}
