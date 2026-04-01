#include "pch.h"
#include "RessourcesManager.h"

Map<String, cpu_material*> RessourcesManager::m_mMat;
S
cpu_material* RessourcesManager::AddMaterial(cpu_material* _mat, String _name)
{
	m_mMat[_name] = _mat;

	return m_mMat[_name];
}

cpu_material* RessourcesManager::LoadTexture(String _name)
{
	cpu_material* m = new cpu_material;

	m->pTexture->Load(_name.c_str());
	m_mMat[_name] = m;

	return m_mMat[_name];
}

cpu_material* RessourcesManager::GetMatWithName(String _name)
{
	auto it = RessourcesManager::GetMap().find(_name);

	if (it == RessourcesManager::GetMap().end())
		return RessourcesManager::LoadTexture(_name);

	return it->second;
}

Map<String, cpu_material*> RessourcesManager::GetMap()
{
	return m_mMat;
}
