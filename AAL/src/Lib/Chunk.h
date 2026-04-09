#pragma once
#include "pch.h"

#define ChunkSize 16.f

enum Biomes
{
	DIRT,
	ROCKY,
	PLAIN,

	BIOME_COUNT
};

class Chunk : public AALentity
{
public:
	~Chunk();

	virtual void Init(Biomes _biome = DIRT);

	virtual void Delete();

	XMFLOAT3 GetPos() { return m_pEntity->transform.pos; }
	float GetSize() { return m_scale; }
	void SetBiome(Biomes _biome);
	void SetPos(XMFLOAT3 _pos);

	void Update(float _dt) override;

private:
	float m_scale = ChunkSize;

	int m_biome = -1;
};
