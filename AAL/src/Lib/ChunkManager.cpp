#include "pch.h"
#include "ChunkManager.h"

ChunkManager* ChunkManager::m_pInstance = nullptr;

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
		}
		mapW += sca;
		mapH = 0.f;
	}
}

void ChunkManager::OnUpdate(float _dt)
{

}
