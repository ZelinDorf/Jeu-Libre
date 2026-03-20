#pragma once
enum EntityType
{
	PLAYER,
	ENEMY,
	PROJECTILE,
};

class AALentity
{
public:
	EntityType m_entityType;
public:
	virtual void Update(float dt) = 0;
};

