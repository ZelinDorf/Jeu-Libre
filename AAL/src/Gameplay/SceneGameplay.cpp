#include "pch.h"
#include "SceneGameplay.h"
#include "App.h"

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

	m_player = new Player();
	m_player->Init(0, 2, 1);

	m_entities.push_back(m_player);

	//m_entities.push_back(m_player->GetWeapon(1));
	//m_entities.push_back(m_player->GetWeapon(2));

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
