#pragma once
#include <vector>
#include <string>
#include "Lib/StatsEnum.h"

class Enemy
{
public: 

	// Enemy Base Stats
	float m_maxHealth = 0.f;
	float m_damage = 0.f;
	float m_armor = 0.f;
	float m_speed = 0.f;
	float m_cost = 0.f;
	float m_atkSpeed = 0.f;
	float m_xpDrop = 0.0f;

	float m_currentHealth = 1.0f;

	//enemy id
	int m_id = -1;

	//

	//Spawn on Maps Condition
	Vector<int> m_canAppear_v = {};

public:

	// Makes an enemy based on his id
	void Create(int id); 

	// Multiply enemy stats by a value
	void MultiplyStats(Vector<StatsEnum> e, Vector<float> value);

	// Adds enemy stats and a value
	void AddStats(Vector<StatsEnum> e, Vector<float> value);

	// Replaces enemy stats by a value	 
	void ChangeStats(Vector<StatsEnum> e, Vector<float> value);  

};

