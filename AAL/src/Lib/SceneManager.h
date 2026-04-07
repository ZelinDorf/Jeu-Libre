#pragma once
#include "Scene.h"

#include "Gameplay/SceneGameplay.h"
#include "Gameplay/SceneMenu.h"
#include "Gameplay/SceneGameMenu.h"

#include "Sandbox/SceneJSON.h"

#include <vector>

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Update(float dt);
	void OnRender(int pass);

	void Reset();

	template<typename SceneType>
	Scene* GetScene()
	{
		for (size_t i = 0; i < m_scenes.size(); i++)
		{
			Scene* scene = m_scenes[i];
			if (dynamic_cast<SceneType*>(scene) != nullptr)
			{
				return scene;
			}
		}
	}

	void SetAllSceneInactive()
	{
		for (size_t i = 0; i < m_scenes.size(); i++)
		{
			Scene* scene = m_scenes[i];
			scene->SetActive(false);
		}
	}

	template<typename SceneType>
	void SetSceneActive(bool active)
	{
		SetAllSceneInactive();
		for (size_t i = 0; i < m_scenes.size(); i++)
		{
			Scene* scene = m_scenes[i];
			if (dynamic_cast<SceneType*>(scene) != nullptr)
			{
				scene->SetActive(active);
				return;
			}
		}
	}

	template<typename SceneType>
	void AddEntityToScene(AALentity* entity)
	{
		for (size_t i = 0; i < m_scenes.size(); i++)
		{
			Scene* scene = m_scenes[i];
			if (dynamic_cast<SceneType*>(scene) != nullptr)
			{
				scene->AddEntity(entity);
				return;
			}
		}
	}

private:
	void Destroy();
	void Init();

private:
	std::vector<Scene*> m_scenes;
};

