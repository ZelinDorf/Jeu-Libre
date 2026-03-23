#pragma once
#include "pch.h"

enum Biomes
{
	PLAIN,
	SAVANNA,
	TAIGA,
	DESERT,
	SNOWY_PLAIN
};

class Chunk
{
public:

	virtual void Init();
	virtual void Init(Biomes _biome);

	virtual void Delete();

	XMFLOAT3 GetPos() { return m_pEntity->transform.pos; }
	void SetBiome(Biomes _biome);
	void SetPos(XMFLOAT3 _pos);

	virtual void OnUpdate(float _dt);


private:
	float m_scale = 16.0f;

	int m_biome = -1;

	cpu_entity* m_pEntity;//if more for none flat chunck --> add in child

	cpu_mesh m_mesh;
	cpu_material m_mat;
	//texture?
};
