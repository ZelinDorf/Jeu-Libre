#include "pch.h"
#include "RessourcesManager.h"

RessourcesManager::RessourcesManager()
{
	s_pInstance = this;
}

cpu_material* RessourcesManager::LoadTexture(String _name)
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

	String completePath;
	completePath.append(TEXTURE_PATH);
	completePath += _name;

	m_mMesh[_name] = m;

	return m_mMesh[_name];
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

	return s_pInstance->LoadTexture(_name);
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
