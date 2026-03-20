#include "pch.h"
#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{

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
		//m_entities[i]->SetVisible();
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