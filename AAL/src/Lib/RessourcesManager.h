#pragma once

class RessourcesManager
{
public:
	RessourcesManager();

	static cpu_material* AddMaterial(cpu_material* _mat, String _name);

	static cpu_material* GetMatWithName(String _name);
	static Map<String, cpu_material*> GetMap();

private:
	inline static RessourcesManager* s_pInstance = nullptr;

	static cpu_material* LoadTexture(String _name);

	static Map<String, cpu_material*> m_mMat;

};

