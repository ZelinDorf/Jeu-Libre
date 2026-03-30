#include "pch.h"
#include "SceneGameplay.h"
#include "App.h"


SceneGameplay::SceneGameplay()
{
	//!\ ORDER FOR Z-INDEX /!\\
	
	// needs UIWrapper
	//AddUI(EntityType::ENGINE_POWER);

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
