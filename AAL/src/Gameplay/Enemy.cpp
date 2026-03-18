#include "pch.h"
#include "Enemy.h"

void Enemy::Create(float hp, float dmg, float arm, float spd, float cost, int id)
{
	// Determinate stats & cost
	m_maxHealth = hp;	m_speed = spd;
	m_id = id;		m_cost = cost;
	m_armor = arm;	m_damage = dmg;
	
	// Determinate When can spawn

	m_canAppear_v = { 0,1,3 }; // ex: map 0, 1 & 3

	// 

}

void Enemy::ChangeStats(std::string stat, float value)
{
	if (stat == "maxHealth") {
		m_maxHealth = value;
	};
	if (stat == "speed") {
		m_speed = value;
	};
	if (stat == "armor") {
		m_armor = value;
	};
	if (stat == "damage") {
		m_damage = value;
	};
}


