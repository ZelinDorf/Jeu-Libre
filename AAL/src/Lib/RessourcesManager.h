#pragma once

class RessourcesManager
{
public:
	RessourcesManager();

	static cpu_material* AddMaterial(cpu_material* _mat, String _name);

	static cpu_material* GetMatWithName(String _name);
	static Map<String, cpu_material*> GetMatMap();

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	static cpu_mesh* AddMesh(cpu_mesh* _mesh, String _name);

	static cpu_mesh* GetMeshWithName(String _name);
	static Map<String, cpu_mesh*> GetMeshMap();


private:
	inline static RessourcesManager* s_pInstance = nullptr;

	static cpu_material* LoadTexture(String _name);
	static cpu_mesh* CreateMesh(String _name);

	inline static Map<String, cpu_material*> m_mMat;
	inline static Map<String, cpu_mesh*> m_mMesh;

};

