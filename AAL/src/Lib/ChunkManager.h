#pragma once

class Chunk;

class ChunkManager
{
public:
	static ChunkManager* GetInstance();

	//init a square map with "_mapSize" chunk per side
	void InitMap(float _mapSize);

	void OnUpdate(float _dt);	

private:
	static ChunkManager* m_pInstance;

	Vector<Chunk*> m_vChunks;
};

