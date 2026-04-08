#include "pch.h"
#include "ChunkManager.h"

ChunkManager* ChunkManager::m_pInstance = nullptr;

ChunkManager::~ChunkManager()
{
	for (Chunk* chunk : m_vChunks)
	{
		delete chunk;
		chunk = nullptr;
	}
	m_vChunks.clear();

	delete m_pInstance;
	m_pInstance = nullptr;

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

	int r = RandomInt(BIOME_COUNT - 1);

	for (size_t i = 0; i < _mapSize; i++)
	{
		for (size_t j = 0; j < _mapSize; j++)
		{
			r = RandomInt(BIOME_COUNT - 1);

			XMFLOAT3 pos = { mapW, 0.f, mapH };

			Chunk* pNextChunk = new Chunk;
			sca = pNextChunk->GetSize();

			switch (r)
			{
			case DIRT:
				pNextChunk->Init(DIRT);
				break;
			case ROCKY:
				pNextChunk->Init(ROCKY);
				break;
			case PLAIN:
				pNextChunk->Init(PLAIN);
				break;
			default:
				break;
			}

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
