#include "pch.h"
#include "SceneMenu.h"
#include <iostream>

SceneMenu::SceneMenu()
{
	//!\ ORDER FOR Z-INDEX /!\\
	
	AddUI(EntityType::TITLE);
	//AddUI(EntityType::START);
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
