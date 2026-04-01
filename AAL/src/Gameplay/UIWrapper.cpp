#include "pch.h"

#include "UIWrapper.h"
#include "App.h"
#include <iostream>
#include "AALEntity.h"
#include "TextureRegister.h"
#include "Scene.h"


std::unordered_map<cpu_texture*, uint16_t> UIWrapper::m_mapTextureUsage;


UIWrapper::UIWrapper(EntityType ui)
{
	m_pTexture = TextureRegister::GetTexture(ui);

	m_pSprite = cpuEngine.CreateSprite();
	m_pSprite->pTexture = m_pTexture;
	m_pSprite->CenterAnchor();

	auto it = m_mapTextureUsage.find(m_pTexture);
	if (it == m_mapTextureUsage.end())
		m_mapTextureUsage[m_pTexture] = 1;
	else
		it->second++;

	switch (ui) {
	case EntityType::TITLE:
		UIposition(0.25f, 0.5f);
		break;

	case EntityType::START:
		UIposition(0.5f, 0.5f);
		break;

	case EntityType::BASE_CARD:
		UIposition(0.5f, 0.5f);
		break;
	case EntityType::MAGE_CARD:
		UIposition(0.5f, 0.5f);
		break;
	}
}

UIWrapper::~UIWrapper()
{
	auto it = m_mapTextureUsage.find(m_pTexture);
	it->second--;

	if (it->second == 0)
	{
		m_mapTextureUsage.erase(m_pTexture);
		CPU_DELPTR(m_pTexture);
	}
}

void UIWrapper::UIposition(float h, float w)
{
	m_pSprite->x = cpuDevice.GetWidth() * w;
	m_pSprite->y = cpuDevice.GetHeight() * h;
}

void UIWrapper::UIpositionPixels(float h, float w)
{
	m_pSprite->x = w;
	m_pSprite->y = h;
}

void UIWrapper::SetHeight(UIWrapper* ui, float h) {
	if (m_mapTextureUsage.size() > 0) {
		ui->m_pSprite->pTexture->height = h;
	}
}

void UIWrapper::SetActive(bool active)
{
	m_pSprite->visible = active;
}