#include "pch.h"
#include "Physics.h"

Physics::Physics()
{

}

void Physics::Gravity(float dt)
{
	if (start) {
		m_Yposition = m_pEntity->transform.pos.y;
		m_fallSpeed = m_Yposition - m_YpositionLastFrame;

		if (m_fallSpeed < 0.0f) {  // going up

		} 
		if (m_fallSpeed > 0.0f) {  // falling

		} 
		float downForce = m_gravityForce + m_fallSpeed;

		m_pEntity->transform.pos.y -= downForce * dt;
	}

	m_YpositionLastFrame = m_pEntity->transform.pos.y;

	std::cout << "fall speed : " << m_fallSpeed << std::endl;
	std::cout << "postion y : " << m_Yposition << std::endl;
 
}
