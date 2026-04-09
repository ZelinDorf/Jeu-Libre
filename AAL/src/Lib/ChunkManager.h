#pragma once

class Chunk;

class ChunkManager
{
public:
	~ChunkManager();

	static ChunkManager* GetInstance();

	//init a square map with "_mapSize" chunk per side
	void InitMap(float _mapSize = 5.f);

	void Update(float _dt);	

	Vector<Chunk*> GetMap() { return m_vChunks; }


private:
	static ChunkManager* m_pInstance;

	//int size?

	Vector<Chunk*> m_vChunks;
};

