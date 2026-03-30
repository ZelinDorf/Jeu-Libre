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
	cpuEngine.Release(m_pEntity);
}

void Enemy::Assemble(EnemiesList type, Enemy* enemy)
{

	// random color for testing
	int col1 = rand() % (200 - 100 + 1) + 100;
	int col2 = rand() % (200 - 100 + 1) + 100;
	int col3 = rand() % (200 - 100 + 1) + 100;

	switch (type)
	{
	case EnemiesList::SKELETAL_GRUNT:

		m_meshEnemy.CreateSpaceship();
		m_materialEnemy.color = cpu::ToColor(col1, col2, col3);
		enemy->Create(&m_meshEnemy, &m_materialEnemy);

		// give entitytype for aalEntity logic later
		enemy->m_entityType = ENEMY;

		break;

	case EnemiesList::SKELETAL_MAGE:
		m_meshEnemy.CreateCube(.5f);
		m_materialEnemy.color = cpu::ToColor(col1, col2, col3);
		enemy->Create(&m_meshEnemy, &m_materialEnemy);

		enemy->GetEntity()->transform.SetPosition(2, 0, 0);
		break;

	case EnemiesList::SKELETAL_ARCHER:
		break;
	default:
		break;
	}
}

void Enemy::Update(float dt)
{
	XMFLOAT3 camPos = cpuEngine.GetCamera()->transform.pos;

	m_pEntity->transform.Move(dt);
	m_pEntity->transform.LookAt(camPos.x, camPos.y, camPos.z);
}

// fonctions tochange the statistic of the enemies
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