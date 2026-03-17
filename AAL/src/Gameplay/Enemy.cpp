#include "pch.h"
#include "Enemy.h"

void Enemy::CreateEnemy(float hp, float dmg, float arm, float spd, float cost, int id)
{
	m_health = hp;
	m_damage = dmg;
	m_armor = arm;
	m_speed = spd;
	m_cost = cost;
	m_id = id;
}
