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

class Chunk : public AALentity
{
public:
	~Chunk();

	virtual void Init();
	virtual void Init(Biomes _biome);

	virtual void Delete();

	XMFLOAT3 GetPos() { return m_pEntity->transform.pos; }
	float GetSize() { return m_scale; }
	void SetBiome(Biomes _biome);
	void SetPos(XMFLOAT3 _pos);

	void Update(float _dt) override;

private:
	float m_scale = 16.0f;

	int m_biome = -1;

	cpu_mesh* m_mesh;
};
