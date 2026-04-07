#include "pch.h"
#include "RessourcesManager.h"

RessourcesManager::RessourcesManager()
{
	s_pInstance = this;
}

cpu_material* RessourcesManager::CreateMaterial(String _name)
{
	cpu_material* m = new cpu_material;

	String completePath;
	completePath.append(TEXTURE_PATH);
	completePath += _name;

	cpu_texture* t = new cpu_texture;
	t->Load(completePath.c_str());

	m->pTexture = t;
	m_mMat[_name] = m;

	return m_mMat[_name];
}

cpu_mesh* RessourcesManager::CreateMesh(String _name)
{
	cpu_mesh* m = new cpu_mesh;

	m_mMesh[_name] = m;

	return m_mMesh[_name];
}

cpu_texture* RessourcesManager::LoadTexture(String _name)
{
	String completePath;
	completePath.append(TEXTURE_PATH);
	completePath += _name;

	cpu_texture* t = new cpu_texture;
	t->Load(completePath.c_str());

	m_mTexture[_name] = t;

	return m_mTexture[_name];
}

cpu_texture* RessourcesManager::LoadTexture(EntityType _type)
{
	cpu_texture* t = CreateUI(_type);

	String name;
	name.append(_mTypeString[_type]);

	m_mTexture[name] = t;

	return m_mTexture[name];
}

cpu_texture* RessourcesManager::CreateUI(EntityType ui)
{
	cpu_texture* pTexture = new cpu_texture();

	switch (ui)
	{
	case EntityType::TITLE:
		pTexture->Load(UI_PATH"title.png");
		break;
	case EntityType::START:
	case EntityType::QUIT:
	case EntityType::OPTION:
		pTexture->Load(UI_PATH"button.png");
		break;

	case EntityType::BASE_CARD:
		pTexture->Load(UI_PATH"character/hero_card.png");
		break;
	case EntityType::WEAPONS_CARD:
		pTexture->Load(UI_PATH"character/weapons_card.png");
		break;

	case EntityType::MAGE_CARD:
		pTexture->Load(UI_PATH"character/mage.png");
		break;
	case EntityType::WARRIOR_CARD:
		pTexture->Load(UI_PATH"character/warrior.png");
		break;
	case EntityType::ROGUE_CARD:
		pTexture->Load(UI_PATH"character/rogue.png");
		break;

	case EntityType::SWORD_CARD:
		pTexture->Load(UI_PATH"character/sword.png");
		break;
	case EntityType::STAFF_CARD:
		pTexture->Load(UI_PATH"character/staff.png");
		break;
	case EntityType::BOW_CARD:
		pTexture->Load(UI_PATH"character/bow.png");
		break;
	}

	return pTexture;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cpu_material* RessourcesManager::AddMaterial(cpu_material* _mat, String _name)
{
	m_mMat[_name] = _mat;

	return m_mMat[_name];
}

cpu_material* RessourcesManager::GetMatWithName(String _name)
{
	if (s_pInstance->m_mMat.contains(_name))
	{
		return s_pInstance->m_mMat[_name];
	}

	return s_pInstance->CreateMaterial(_name);
}

Map<String, cpu_material*> RessourcesManager::GetMatMap()
{
	return m_mMat;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cpu_mesh* RessourcesManager::AddMesh(cpu_mesh* _mesh, String _name)
{
	m_mMesh[_name] = _mesh;

	return m_mMesh[_name];
}

cpu_mesh* RessourcesManager::GetMeshWithName(String _name)
{
	if (s_pInstance->m_mMesh.contains(_name))
	{
		return s_pInstance->m_mMesh[_name];
	}

	return s_pInstance->CreateMesh(_name);
}

Map<String, cpu_mesh*> RessourcesManager::GetMeshMap()
{
	return m_mMesh;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

cpu_texture* RessourcesManager::AddTexture(cpu_texture* _texture, String _name)
{
	m_mTexture[_name] = _texture;

	return m_mTexture[_name];
}

cpu_texture* RessourcesManager::GetTextureWithName(String _name)
{
	if (s_pInstance->m_mTexture.contains(_name))
	{
		return s_pInstance->m_mTexture[_name];
	}

	return s_pInstance->LoadTexture(_name);
}

Map<String, cpu_texture*> RessourcesManager::GetTextureMap()
{
	return m_mTexture;
}
