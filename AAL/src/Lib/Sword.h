#pragma once
#include "AALentity.h"

class Sword : public AALentity
{
public:	
	Sword();
	~Sword();

	void Update(float dt) override;
	
	XMFLOAT3 newPos = { 0.0f,0.0f,0.0f };
	
};

