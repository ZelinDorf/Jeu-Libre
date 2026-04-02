#pragma once
enum EntityType
{
	PLAYER,
	ENEMY,
	PROJECTILE,

//	-[  U I  ]-   //

	TITLE,
	START, OPTION, QUIT

////////////////////
};

class AALentity
{
public:
	EntityType m_entityType;
	EntityType m_uiType;

	cpu_entity* m_pEntity;

public:
	virtual void Update(float dt) = 0;

	void SetVisible(bool active);
};

