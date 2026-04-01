#pragma once

class RessourcesManager
{
public:
	static cpu_material* AddMaterial(cpu_material* _mat, String _name);

	static cpu_material* GetMatWithName(String _name);
	static Map<String, cpu_material*> GetMap();

private:
	static cpu_material* LoadTexture(String _name);

	static Map<String, cpu_material*> m_mMat;

};

