#pragma once

#include <unordered_map>
#include "TextureFactory.h"

class TextureRegister
{
public:
    static bool HasTexture(EntityType entityType);
    static cpu_texture* GetTexture(EntityType entityType);

private:
    static cpu_texture* RegisterTexture(EntityType entityType);
    static std::unordered_map<EntityType, cpu_texture*> m_mapTexture;
};