#include "pch.h"
#include "ChunkManager.h"

ChunkManager* ChunkManager::m_pInstance = nullptr;

ChunkManager::~ChunkManager()
{
	for (Chunk* chunk : m_vChunks)
	{
		CPU_DELPTR(chunk);
	}
	m_vChunks.clear();
}

ChunkManager* ChunkManager::GetInstance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new ChunkManager();
	}

	return m_pInstance;
}

void ChunkManager::InitMap(float _mapSize)
{
	float mapW = 0.f;
	float mapH = 0.f;

	float sca;

	for (size_t i = 0; i < _mapSize; i++)
	{
		for (size_t j = 0; j < _mapSize; j++)
		{
			XMFLOAT3 pos = { mapW, 0.f, mapH };

			Chunk* pNextChunk = new Chunk;
			sca = pNextChunk->GetSize();

			if (j % 2 == 0 && i % 2 == 0 )
				pNextChunk->Init(PLAIN);
			else
				pNextChunk->Init(DESERT);

			pNextChunk->SetPos(pos);

			mapH += sca;
			
			m_vChunks.push_back(pNextChunk);
		}
		mapW += sca;
		mapH = 0.f;
	}
}

void ChunkManager::Update(float _dt)
{

}
