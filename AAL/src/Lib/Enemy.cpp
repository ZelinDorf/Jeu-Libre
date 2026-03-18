#include "pch.h"
#include "Enemy.h"

void Enemy::Create(int id)
{
	
}

void Enemy::MultiplyStats(Vector<StatsEnum> e, Vector<float> value)
{
	if (e.size() != value.size()) return; // must be the same size !

	for (size_t i = 0; i < e.size(); i++)
	{
		switch (e[i])
		{
		case StatsEnum::MAX_HEALTH:
			m_maxHealth *= value[i];
			break;
		case StatsEnum::SPEED:
			m_speed *= value[i];
			break;
		case StatsEnum::DAMAGE:
			m_damage *= value[i];
			break;
		case StatsEnum::ARMOR:
			m_armor *= value[i];
			break;
		case StatsEnum::XP_DROP:
			m_xpDrop *= value[i];
			break;
		default:
			break;
		}
	}
}
void Enemy::AddStats(Vector<StatsEnum> e, Vector<float> value)
{
	if (e.size() != value.size()) return; // must be the same size !
	for (size_t i = 0; i < e.size(); i++)
	{
		switch (e[i])
		{
		case StatsEnum::MAX_HEALTH:
			m_maxHealth += value[i];
			break;
		case StatsEnum::SPEED:
			m_speed += value[i];
			break;
		case StatsEnum::DAMAGE:
			m_damage += value[i];
			break;
		case StatsEnum::ARMOR:
			m_armor += value[i];
			break;
		case StatsEnum::XP_DROP:
			m_xpDrop += value[i];
			break;
		default:
			break;
		}
	}
}
void Enemy::ChangeStats(Vector<StatsEnum> e, Vector<float> value)
{
	if (e.size() != value.size()) return; // must be the same size !

	for (size_t i = 0; i < e.size(); i++)
	{
		switch (e[i])
		{
		case StatsEnum::MAX_HEALTH:
			m_maxHealth = value[i];
			break;
		case StatsEnum::SPEED:
			m_speed = value[i];
			break;
		case StatsEnum::DAMAGE:
			m_damage = value[i];
			break;
		case StatsEnum::ARMOR:
			m_armor = value[i];
			break;
		case StatsEnum::XP_DROP:
			m_xpDrop = value[i];
			break;
		default:
			break;
		}

	}
}