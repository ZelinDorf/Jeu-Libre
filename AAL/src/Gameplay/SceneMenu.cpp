#include "pch.h"
#include "SceneMenu.h"
#include <iostream>

SceneMenu::SceneMenu()
{
	//!\ ORDER FOR Z-INDEX /!\\
	
	AddUI(EntityType::TITLE);
	//AddUI(EntityType::START);

	m_font.Create(30);
}

SceneMenu::~SceneMenu()
{

}

void SceneMenu::OnRender(int pass)
{
	std::string text = "[ PRESS SPACEBAR TO START ]";

	XMFLOAT3 texttint = { 1.0f, 1.0f, 1.0f };
	cpuDevice.DrawText(&m_font, text.c_str(), (int)(cpuDevice.GetWidth() * 0.5f), (int)(cpuDevice.GetHeight() * 0.8f), CPU_TEXT_CENTER, &texttint);
}

void SceneMenu::Update(float dt)
{
	Scene::Update(dt);
}
