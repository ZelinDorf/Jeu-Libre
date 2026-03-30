#include "pch.h"
#include "SceneMenu.h"

SceneMenu::SceneMenu()
{
	//!\ ORDER FOR Z-INDEX /!\\
	
	// needs UIWrapper
	//AddUI(EntityType::ENGINE_POWER);

}

SceneMenu::~SceneMenu()
{

}

void SceneMenu::OnRender(int pass)
{

}

void SceneMenu::Update(float dt)
{
	Scene::Update(dt);
}
