#include "pch.h"
#include "SceneGameMenu.h"
#include "UIWrapper.h"

SceneGameMenu::SceneGameMenu()
{
	//!\ ORDER FOR Z-INDEX /!\\
	//! 
	AddUI(EntityType::BASE_CARD);

	AddUI(EntityType::MAGE_CARD);
	AddUI(EntityType::WARRIOR_CARD);
	AddUI(EntityType::ROGUE_CARD);

	AddUI(EntityType::WEAPONS_CARD);

	AddUI(EntityType::SWORD_CARD);
	AddUI(EntityType::STAFF_CARD);
	AddUI(EntityType::BOW_CARD);

	m_font.Create(20);
}

SceneGameMenu::~SceneGameMenu()
{

}

void SceneGameMenu::OnRender(int pass)
{
	XMFLOAT3 texttint = { 1.0f, 1.0f, 1.0f };
	cpuDevice.DrawText(&m_font, m_text.c_str(), (int)(cpuDevice.GetWidth() * 0.495f), (int)(cpuDevice.GetHeight() * 0.3f), CPU_TEXT_CENTER, &texttint);
}

void SceneGameMenu::Update(float dt)
{
	UIWrapper* pMageCard = GetUI(EntityType::MAGE_CARD);
	UIWrapper* pWarriorCard = GetUI(EntityType::WARRIOR_CARD);
	UIWrapper* pRogueCard = GetUI(EntityType::ROGUE_CARD);

	UIWrapper* pStaffCard = GetUI(EntityType::STAFF_CARD);
	UIWrapper* pSwordCard = GetUI(EntityType::SWORD_CARD);
	UIWrapper* pBowCard = GetUI(EntityType::BOW_CARD);

	Scene::Update(dt);

	if (InputSystem::IsKeyDown(InputKeyboard::LEFT))
	{
		m_charSelected--;
		if (m_charSelected <= 0) m_charSelected = 3;
	}

	if (InputSystem::IsKeyDown(InputKeyboard::RIGHT))
	{
		m_charSelected++;
		if (m_charSelected > 3) m_charSelected = 1;
	}

	if (m_charSelected == 1) {
		pWarriorCard->SetActive(true);
		pMageCard->SetActive(false);
		pRogueCard->SetActive(false);

		pSwordCard->SetActive(true);
		pStaffCard->SetActive(false);
		pBowCard->SetActive(false);

		m_text = "[ WARRIOR ]";

	}

	if (m_charSelected == 2) {
		pWarriorCard->SetActive(false);
		pMageCard->SetActive(true);
		pRogueCard->SetActive(false);

		pSwordCard->SetActive(false);
		pStaffCard->SetActive(true);
		pBowCard->SetActive(false);

		m_text = "[ MAGE ]";

	}

	if (m_charSelected == 3) {
		pWarriorCard->SetActive(false);
		pMageCard->SetActive(false);
		pRogueCard->SetActive(true);

		pSwordCard->SetActive(false);
		pStaffCard->SetActive(false);
		pBowCard->SetActive(true);

		m_text = "[ ROGUE ]";

	}
}
