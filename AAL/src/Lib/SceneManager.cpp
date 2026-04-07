#include "pch.h"
#include "SceneManager.h"
#include "Sandbox/SceneJSON.h"

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
	/*Scene* scene = new SceneJSON();
	m_scenes.push_back(scene);*/

	Scene* sceneGameplay = new SceneGameplay();
	m_scenes.push_back(sceneGameplay);

	Scene* sceneMenu = new SceneMenu();
	m_scenes.push_back(sceneMenu);

	Scene* sceneGameMenu = new SceneGameMenu();
	m_scenes.push_back(sceneGameMenu);	
	
}

