#pragma once
#include "StatsEnum.h"
#include "AALentity.h"
#include "EnemiesRegistery.h"

class Enemy : public AALentity
{
public:
	// Enemy Base Stats
	float m_maxHealth = 10.f;
	float m_damage = 1.f;
	float m_armor = 0.f;
	float m_speed = 1.f;
	float m_cost = 10.f;
	float m_atkSpeed = 1.f;
	float m_xpDrop = 1.0f;

	float m_currentHealth = 10.0f;

	//enemy id
	int m_id = -1;

	Enemy* m_pEnemy = nullptr;
	cpu_material* m_pColorDmg = nullptr;
	float m_dmgTimer = .5f;

protected:
	/*
	cpu_mesh m_meshEnemy;
	cpu_material m_materialEnemy;
	*/

public:

	Enemy();
	~Enemy();

	//void Create(cpu_mesh* pMesh, cpu_material* pMaterial);
	void Destroy();

	void Assemble(EnemiesList type, Enemy* enemy);
	void Update(float dt);

	cpu_entity* GetEntity() { return m_pEntity; }

	// Multiply enemy stats by a value
	void MultiplyStats(Vector<StatsEnum> e, Vector<float> value);

	// Adds enemy stats and a value
	void AddStats(Vector<StatsEnum> e, Vector<float> value);

	// Replaces enemy stats by a value	 
	void ChangeStats(Vector<StatsEnum> e, Vector<float> value);

	void DamageTaken();
	bool Death();
};