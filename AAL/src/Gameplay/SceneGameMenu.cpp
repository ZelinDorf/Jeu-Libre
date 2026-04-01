#include "pch.h"
#include "SceneGameMenu.h"

SceneGameMenu::SceneGameMenu()
{
	//!\ ORDER FOR Z-INDEX /!\\
	//! 
	AddUI(EntityType::BASE_CARD);
	AddUI(EntityType::MAGE_CARD);

	m_font.Create(30);
}

SceneGameMenu::~SceneGameMenu()
{

}

void SceneGameMenu::OnRender(int pass)
{
	XMFLOAT3 texttint = { 1.0f, 1.0f, 1.0f };
	//cpuDevice.DrawText(&m_font, text.c_str(), (int)(cpuDevice.GetWidth() * 0.5f), (int)(cpuDevice.GetHeight() * 0.8f), CPU_TEXT_CENTER, &texttint);
}

void SceneGameMenu::Update(float dt)
{
	Scene::Update(dt);

	if (InputSystem::IsKeyPressed(InputKeyboard::LEFT))
	{

	}
}
