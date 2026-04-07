#pragma once
enum EntityType
{
	NO_ENTITY,

	PLAYER,
	ENEMY,
	PROJECTILE,

//	-[  U I  ]-   //

	TITLE,
	START, OPTION, QUIT,

	BASE_CARD, WEAPONS_CARD,
	WARRIOR_CARD, ROGUE_CARD, MAGE_CARD,

	SWORD_CARD, STAFF_CARD, BOW_CARD,

////////////////////
};

class AALentity
{
public:
	EntityType m_entityType;
	EntityType m_uiType;

	cpu_entity* m_pEntity;

public:
	AALentity() : m_entityType(NO_ENTITY), m_uiType(NO_ENTITY), m_pEntity(nullptr){}
	

	virtual void Update(float dt) = 0;

	void SetVisible(bool active);
};

