#pragma once

enum EntityType;

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

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	static cpu_texture* AddTexture(cpu_texture* _texture, String _name);

	static cpu_texture* GetTextureWithName(String _name);
	static Map<String, cpu_texture*> GetTextureMap();

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	static cpu_texture* CreateUI(EntityType ui);

private:
	inline static RessourcesManager* s_pInstance = nullptr;

	static cpu_material* CreateMaterial(String _name);
	static cpu_mesh* CreateMesh(String _name);
	static cpu_texture* LoadTexture(String _name);
	static cpu_texture* LoadTexture(EntityType _type);

	inline static Map<String, cpu_material*> m_mMat;
	inline static Map<String, cpu_mesh*> m_mMesh;
	inline static Map<String, cpu_texture*> m_mTexture;

};

