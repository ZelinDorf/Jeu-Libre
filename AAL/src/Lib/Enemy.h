#include "StatsEnum.h"
#include "EnemiesRegistery.h"

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

	//Spawn on Maps Condition
	Vector<int> m_canAppear_v = {};
protected:

	cpu_mesh m_meshEnemy;
	cpu_material m_materialEnemy;

public:
	cpu_entity* m_pEntity = nullptr;

	Enemy();
	~Enemy();

	void Create(cpu_mesh* pMesh, cpu_material* pMaterial);
	void Destroy();

	void Assemble(EnemiesList type, Enemy* enemy);
	void Update();

	cpu_entity* GetEntity() { return m_pEntity; }

	// Multiply enemy stats by a value
	void MultiplyStats(Vector<StatsEnum> e, Vector<float> value);

	// Adds enemy stats and a value
	void AddStats(Vector<StatsEnum> e, Vector<float> value);

	// Replaces enemy stats by a value	 
	void ChangeStats(Vector<StatsEnum> e, Vector<float> value);

private:
	Vector<Enemy*> m_activeEnemies;
	Vector<int> m_inGameIds;
};