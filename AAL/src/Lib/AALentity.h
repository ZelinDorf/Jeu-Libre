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

enum UIType
{

};

class AALentity
{
public:
	EntityType m_entityType;
	UIType m_uiType;

public:
	virtual void Update(float dt) = 0;
};

