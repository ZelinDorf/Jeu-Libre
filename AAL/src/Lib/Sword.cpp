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
	float i = 0;
	for (Sword* sword : Player::m_vSwords)
	{
		float angle = XMConvertToRadians( (cpuTime.total * 10.0f) * 5.0f + (360 / Player::m_vSwords.size()) * i);

		sword->m_pEntity->transform.SetYPR(angle, XMConvertToRadians(-90.0f), XMConvertToRadians(90.0f));

		newPos = Player::GetPosition(); newPos.y = .5f;
		sword->m_pEntity->transform.OrbitAroundAxis(newPos, CPU_VEC3_UP, 2.f, angle);
		i++;
	}
}

