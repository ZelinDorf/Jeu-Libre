#include "pch.h"

#include "TextureFactory.h"

cpu_texture* TextureFactory::Create(EntityType entityType)
{
	cpu_texture* texture = new cpu_texture();

	switch (entityType)
	{
	case EntityType::TITLE:
		texture->Load("../../res/UI/title.png");
		break;
	case EntityType::START:
	case EntityType::QUIT:
	case EntityType::OPTION:
		texture->Load("../../res/UI/button.png");
		break;

	case EntityType::BASE_CARD:
		texture->Load("../../res/UI/character/hero_card.png");
		break;
	case EntityType::WEAPONS_CARD:
		texture->Load("../../res/UI/character/weapons_card.png");
		break;

	case EntityType::MAGE_CARD:
		texture->Load("../../res/UI/character/mage.png");
		break;
	case EntityType::WARRIOR_CARD:
		texture->Load("../../res/UI/character/warrior.png");
		break;
	case EntityType::ROGUE_CARD:
		texture->Load("../../res/UI/character/rogue.png");
		break;

	case EntityType::SWORD_CARD:
		texture->Load("../../res/UI/character/sword.png");
		break;
	case EntityType::STAFF_CARD:
		texture->Load("../../res/UI/character/staff.png");
		break;
	case EntityType::BOW_CARD:
		texture->Load("../../res/UI/character/bow.png");
		break;
	}

	return texture;
}
