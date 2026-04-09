#include "pch.h"
#include "Sword.h"


Sword::Sword()
{
	newPos = Player::GetPosition();
	

	JSON_OBJ(JSON_PATH"sword.json", nullptr, m_pEntity);

}

Sword::~Sword()
{
}

void Sword::Update(float dt) 
{
	m_pEntity->transform.SetYPR(cpuTime.total * 2.0f, XMConvertToRadians(-90.0f), XMConvertToRadians(90.0f));
	m_pEntity->transform.AddRoll(XMConvertToRadians(-90.0f));


	newPos = Player::GetPosition();
	m_pEntity->transform.OrbitAroundAxis(newPos, CPU_VEC3_UP, 1.75f, cpuTime.total * 2.0f);
}

