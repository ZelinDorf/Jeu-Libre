#pragma once
#include "AALEntity.h"


class TextureFactory
{
public:
	~TextureFactory();

	static cpu_texture* Create(EntityType entityType);
};

