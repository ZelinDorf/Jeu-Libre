#include "pch.h"
#include "Enemy.h"

Enemy::Enemy()
{
	m_pEntity = nullptr;
}

Enemy::~Enemy()
{
	Destroy();
}

void Enemy::Create(cpu_mesh* pMesh, cpu_material* pMaterial)
{
	m_pEntity = cpuEngine.CreateEntity();
	m_pEntity->pMesh = pMesh;
	m_pEntity->pMaterial = pMaterial;
}

void Enemy::Destroy()
{
	m_pEntity = cpuEngine.Release(m_pEntity);
}

void Enemy::Assemble(EnemiesList type, Enemy* enemy)
{

	int firstAvailableID = m_inGameIds.size();

	int col1 = rand() % (200 - 100 + 1) + 100;
	int col2 = rand() % (200 - 100 + 1) + 100;
	int col3 = rand() % (200 - 100 + 1) + 100;

	std::cout << m_inGameIds.size();

	for (size_t i = 0; i < m_inGameIds.size(); i++)
	{
		std::cout << "for i: " << i << std::endl;
		if (m_inGameIds[i] != i) {
			std::cout << i;
			firstAvailableID = i;
			break;
		}
	}

	switch (type)
	{
	case EnemiesList::SKELETAL_GRUNT:

		m_meshEnemy.CreateSpaceship();
		m_materialEnemy.color = cpu::ToColor(col1, col2, col3);
		enemy->Create(&m_meshEnemy, &m_materialEnemy);

		enemy->ChangeStats({ MAX_HEALTH, ARMOR, SPEED, DAMAGE, ATTACK_SPEED, XP_DROP, COST }, {10,1,1,1,1,1,1} );
		enemy->m_currentHealth = m_maxHealth;

		m_activeEnemies.push_back(enemy);
		m_inGameIds.push_back(firstAvailableID);

		break;
	case EnemiesList::SKELETAL_MAGE:
		m_meshEnemy.CreateCube(.5f);
		m_materialEnemy.color = cpu::ToColor(col1, col2, col3);
		enemy->Create(&m_meshEnemy, &m_materialEnemy);
		break;
	case EnemiesList::SKELETAL_ARCHER:
		break;
	default:
		break;
	}
}

void Enemy::Update() 
{
	float dt = cpuTime.delta;
	if (InputSystem::IsKeyDown(A))
	{
		m_currentHealth--;
	}
	//if (m_currentHealth <= 0) 
	
	XMFLOAT3 camPos = cpuEngine.GetCamera()->transform.pos;
	m_pEntity->transform.LookAt(camPos.x, camPos.y, camPos.z);
	//m_pEntity->transform.Move(dt);
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
		case StatsEnum::ATTACK_SPEED:
			m_atkSpeed = value[i];
			break;
		case StatsEnum::COST:
			m_xpDrop = value[i];
			break;
		default:
			break;
		}

	}
}