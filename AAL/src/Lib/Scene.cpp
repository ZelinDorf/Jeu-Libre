#include "pch.h"
#include "Scene.h"
#include "Gameplay/UIWrapper.h"

Scene::Scene()
{
}

Scene::~Scene()
{
	for (size_t i = 0; i < m_entities.size(); i++)
	{
		CPU_DELPTR(m_entities[i]);
	}

	for (auto& it : m_mapUI) {
		CPU_DELPTR(it.second);
	}
}

bool Scene::IsActive()
{
	return m_active;
}

void Scene::SetActive(bool active)
{
	m_active = active;
	for (size_t i = 0; i < m_entities.size(); i++)
	{
		m_entities[i]->SetVisible(active);
	}

	for (auto& it : m_mapUI) {
		it.second->SetActive(active);
	}
}

void Scene::Update(float dt)
{
	for(auto entity : m_entities)
	{
		entity->Update(dt);
	}
}

void Scene::OnRender(int pass)
{

}

void Scene::Reset()
{

}

void Scene::AddEntity(AALentity* entity)
{
	
}

UIWrapper* Scene::AddUI(EntityType entityType)
{
	UIWrapper* ui = new UIWrapper(entityType);
	m_mapUI[entityType] = ui;
	return ui;
}

UIWrapper* Scene::GetUI(EntityType entityType)
{
	auto it = m_mapUI.find(entityType);
	if (it != m_mapUI.end())
		return it->second;

	return nullptr;
}