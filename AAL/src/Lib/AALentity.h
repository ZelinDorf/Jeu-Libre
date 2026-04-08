#pragma once

class Physics;

enum EntityType
{
	NO_ENTITY,

//  -[ ENTITIES ]-  //
	WORLD_OBJECT,
	PLAYER,
	ENEMY,
	PROJECTILE,

// 	-[  UI  ]-   //

	TITLE,
	START, OPTION, QUIT,

	BASE_CARD, WEAPONS_CARD,
	WARRIOR_CARD, ROGUE_CARD, MAGE_CARD,

	SWORD_CARD, STAFF_CARD, BOW_CARD,

////////////////////
};

inline static Map<EntityType, String> _mTypeString = {
	{TITLE, "Title"},
	{START, "Start"},
	{OPTION, "Option"},
	{QUIT, "Quit"},

	{BASE_CARD, "Base_Card"},
	{WEAPONS_CARD, "Weapon_Card"},
	{WARRIOR_CARD, "Warrior_Card"},
	{ROGUE_CARD, "Rogue_Card"},
	{MAGE_CARD, "Mage_Card"},

	{SWORD_CARD, "Sword_Card"},
	{STAFF_CARD, "Staff_Card"},
	{BOW_CARD, "Bow_Card"},
};

class AALentity
{
public:
	EntityType m_entityType;
	EntityType m_uiType;

	cpu_entity* m_pEntity;
	Physics* m_pPhysics;

public:
	AALentity() : m_entityType(NO_ENTITY), m_uiType(NO_ENTITY), m_pEntity(nullptr), m_pPhysics(nullptr) {}
	

	virtual void Update(float dt) = 0;

	void SetVisible(bool active);
};

