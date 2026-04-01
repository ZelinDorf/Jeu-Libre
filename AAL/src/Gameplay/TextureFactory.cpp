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
		texture->Load("../../res/UI/character/base_card.png");
		break;
	case EntityType::MAGE_CARD:
		texture->Load("../../res/UI/character/mage.png");
		break;
	}

	return texture;
}
