#include "pch.h"
#include "SceneGameplay.h"

SceneGameplay::SceneGameplay()
{
	//!\ ORDER FOR Z-INDEX /!\\
	// needs UIWrapper

	chunkManager->InitMap(3.f);

	Vector<Chunk*> chunks = chunkManager->GetMap();
	
	for (size_t i = 0; i < chunks.size(); i++)
	{
		m_entities.push_back(chunks[i]);
	}

	m_pEnemy = new Enemy;
	m_pEnemy->Assemble(SKELETAL_GRUNT, m_pEnemy);

	m_entities.push_back(m_pEnemy);
}

SceneGameplay::~SceneGameplay()
{

}

void SceneGameplay::OnRender(int pass)
{

}

void SceneGameplay::Update(float dt)
{
	Scene::Update(dt);
}
