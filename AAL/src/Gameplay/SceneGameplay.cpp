#include "pch.h"
#include "SceneGameplay.h"
#include "App.h"

SceneGameplay::SceneGameplay()
{
	//!\ ORDER FOR Z-INDEX /!\\
	// needs UIWrapper

	chunkManager->InitMap(2.f);

	Vector<Chunk*> chunks = chunkManager->GetMap();
	
	for (size_t i = 0; i < chunks.size(); i++)
	{
		m_entities.push_back(chunks[i]);
	}


	m_pEnemy = new Enemy;
	m_pEnemy->Assemble(SKELETAL_HEAD, m_pEnemy);
	m_entities.push_back(m_pEnemy);

	mPlayer = new Player();
	mPlayer->Init(0);

	m_entities.push_back(mPlayer);
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
