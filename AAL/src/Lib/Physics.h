#pragma once
#include "AALentity.h"

class Physics : public AALentity
{
public:
	Physics();

	bool start = false;

	float m_YpositionLastFrame = 0.0f;
	float m_Yposition = 0.0f;

	float m_fallSpeed = 0.0f;

	float m_gravityForce = 10.0f;

	void Gravity(float dt);

private:


};

