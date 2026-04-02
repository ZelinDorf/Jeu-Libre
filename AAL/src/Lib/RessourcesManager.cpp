#include "pch.h"
#include "RessourcesManager.h"

Map<String, cpu_material*> RessourcesManager::m_mMat;

RessourcesManager::RessourcesManager()
{
	s_pInstance = this;
}

cpu_material* RessourcesManager::AddMaterial(cpu_material* _mat, String _name)
{
	m_mMat[_name] = _mat;

	return m_mMat[_name];
}

cpu_material* RessourcesManager::LoadTexture(String _name)
{
	cpu_material* m = new cpu_material;

	cpu_texture* t = new cpu_texture;
	t->Load(_name.c_str());

	m->pTexture = t;
	m_mMat[_name] = m;

	return m_mMat[_name];
}

cpu_material* RessourcesManager::GetMatWithName(String _name)
{
	/*auto it = RessourcesManager::GetMap().find(_name);

	if (it == RessourcesManager::GetMap().end())
		return RessourcesManager::LoadTexture(_name);

	return it->second;*/

	if (s_pInstance->m_mMat.contains(_name))
	{
		return s_pInstance->m_mMat[_name];
	}

	return s_pInstance->LoadTexture(_name);
}

Map<String, cpu_material*> RessourcesManager::GetMap()
{
	return m_mMat;
}
