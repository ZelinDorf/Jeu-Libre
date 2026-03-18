#pragma once
#include <vector>
#include <string>
#include "Lib/StatsEnum.h"

class Enemy
{
public: 
	// Enemy Base Stats
	float m_maxHealth = 0;
	float m_damage = 0;
	float m_armor = 0;
	float m_speed = 0;
	float m_cost = 0;

	//enemy id
	int m_id = 0;

	//Spawn Condition
	std::vector<int> m_canAppear_v = {};

private:

	void Create(float hp, float dmg, float arm, float spd, float cost, int id);
	void ChangeStats(Vector<StatsEnum> e, std::vector<float> value);
};

