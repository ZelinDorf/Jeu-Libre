#include "pch.h"
#include "Enemy.h"

void Enemy::Create(int id)
{
	// Spawn a monster based on is ID/ENUM
}

void Enemy::MultiplyStats(Vector<StatsEnum> e, Vector<float> value)
{
	if (e.size() != value.size()) return; // must be the same size !

	for (size_t i = 0; i < e.size(); i++)
	{
		if (e[i] == StatsEnum::MAX_HEALTH) {
			m_maxHealth *= value[i];
		}

		if (e[i] == StatsEnum::SPEED) {
			m_speed *= value[i];
		}

		if (e[i] == StatsEnum::DAMAGE) {
			m_damage *= value[i];
		}

		if (e[i] == StatsEnum::ARMOR) {
			m_armor *= value[i];
		}

		if (e[i] == StatsEnum::XP_DROP) {
			m_xpDrop *= value[i];
		}
	}
}

void Enemy::AddStats(Vector<StatsEnum> e, Vector<float> value)
{
	if (e.size() != value.size()) return; // must be the same size !

	for (size_t i = 0; i < e.size(); i++)
	{
		if (e[i] == StatsEnum::MAX_HEALTH) {
			m_maxHealth += value[i];
		}

		if (e[i] == StatsEnum::SPEED) {
			m_speed += value[i];
		}

		if (e[i] == StatsEnum::DAMAGE) {
			m_damage += value[i];
		}

		if (e[i] == StatsEnum::ARMOR) {
			m_armor += value[i];
		}

		if (e[i] == StatsEnum::XP_DROP) {
			m_xpDrop += value[i];
		}
	}
}

void Enemy::ChangeStats(Vector<StatsEnum> e, Vector<float> value ) // multiply base stats by a value -> for scaling via items
{
	if (e.size() != value.size()) return; // must be the same size !

	for (size_t i = 0; i < e.size(); i++)
	{
		if (e[i] == StatsEnum::MAX_HEALTH) {
			m_maxHealth = value[i];
		}

		if (e[i] == StatsEnum::SPEED) {
			m_speed = value[i];
		}

		if (e[i] == StatsEnum::DAMAGE) {
			m_damage = value[i];
		}

		if (e[i] == StatsEnum::ARMOR) {
			m_armor = value[i];
		}

		if (e[i] == StatsEnum::XP_DROP) {
			m_xpDrop = value[i];
		}
	}
}





