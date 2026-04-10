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

void Enemy::Destroy()
{
	cpuEngine.Release(m_pEntity);
}

void Enemy::Assemble(EnemiesList _type, Enemy* enemy)
{
	m_type = _type;

	switch (_type)
	{
	case EnemiesList::SKELETAL_HEAD:
		JSON_OBJ(JSON_PATH"skeleton_head.json", nullptr, m_pEntity);
		break;

	case EnemiesList::SKELETAL_MAGE:
		//TODO
		break;

	case EnemiesList::SKELETAL_ARCHER:
		//TODO
		break;

	case EnemiesList::CINUT:
		JSON_OBJ(JSON_PATH"invertFox.json", nullptr, m_pEntity);
		break;
	default:
		break;
	}
}

void Enemy::Update(float dt)
{
	XMFLOAT3 playerPos = Player::GetPosition();

	if (m_dmgTimer <= 0.0f)
	{
		m_dmgTimer == .5f;

		switch (m_type)
		{
		case EnemiesList::SKELETAL_HEAD:
			m_pEntity->pMaterial = RessourcesManager::GetMatWithName("skeleton_head.png");//probleme sur l'update des enemy dead
			break;
		case EnemiesList::SKELETAL_MAGE:
			//TODO
			break;
		case EnemiesList::SKELETAL_ARCHER:
			//TODO
			break;
		case EnemiesList::CINUT:
			m_pEntity->pMaterial = RessourcesManager::GetMatWithName("inverted_fox.png");
			break;
		default:
			break;
		}
		//m_pEntity->pMaterial = RessourcesManager::GetMatWithName("inverted_fox.png");
	}
	else if(m_pEntity->pMaterial == m_pColorDmg)
	{
		m_dmgTimer -= dt;
	}

	m_pEntity->transform.Move(m_speed * dt);
	m_pEntity->transform.LookAt(playerPos.x, playerPos.y, playerPos.z);
}

// fonctions to change the statistic of the enemies
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

void Enemy::DamageTaken()
{

	m_currentHealth--;
	if (m_pColorDmg == nullptr) 
	{
		m_pColorDmg = new cpu_material(); // change color of the enemy when damaged
	}

	m_pColorDmg->color = CPU_RED;
	m_pEntity->pMaterial = m_pColorDmg;
}

bool Enemy::Death()
{
	if (m_currentHealth <= 0)
	{
		Destroy();
		return true;
	}
	return false;
}

