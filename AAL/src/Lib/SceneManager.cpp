#include "pch.h"
#include "SceneManager.h"
#include "Gameplay/SceneGameplay.h"
#include "Gameplay/SceneJSON.h"

SceneManager::SceneManager()
{
	Init();//faire en template pour init plus simple depuis la scene direct???????
}

SceneManager::~SceneManager()
{
	Destroy();
}

void SceneManager::Update(float dt)
{
	for (size_t i = 0; i < m_scenes.size(); i++)
	{
		Scene* scene = m_scenes[i];
		if (scene->IsActive())
			scene->Update(dt);
	}
}

void SceneManager::OnRender(int pass)
{
	for (size_t i = 0; i < m_scenes.size(); i++)
	{
		Scene* scene = m_scenes[i];
		if (scene->IsActive())
			scene->OnRender(pass);
	}
}

void SceneManager::Reset()
{
	for (size_t i = 0; i < m_scenes.size(); i++)
	{
		Scene* scene = m_scenes[i];
		scene->Reset();
	}
}

void SceneManager::Destroy()
{
	for (size_t i = 0; i < m_scenes.size(); i++)
	{
		Scene* scene = m_scenes[i];
		CPU_DELPTR(scene);
	}

	m_scenes.clear();
}

void SceneManager::Init()
{ 
	Scene* sceneGameplay = new SceneGameplay();
	m_scenes.push_back(sceneGameplay);

	Scene* sceneJSON = new SceneJSON();
	m_scenes.push_back(sceneJSON);
}

