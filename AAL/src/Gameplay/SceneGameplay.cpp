#include "pch.h"
#include "SceneGameplay.h"
#include "App.h"

SceneGameplay::SceneGameplay()
{
	//!\ ORDER FOR Z-INDEX /!\\
	// needs UIWrapper

	chunkManager->InitMap(3.f);

	Vector<Chunk*> chunks = chunkManager->GetMap();
	
	for (size_t i = 0; i < chunks.size(); i++)
	{
		m_entities.push_back(chunks[i]);
	}

	mPlayer = new Player();
	mPlayer->Init(0);

	m_entities.push_back(mPlayer);
}

SceneGameplay::~SceneGameplay()
{

}

void SceneGameplay::OnRender(int pass)
{


}

void SceneGameplay::Update(float dt)
{
	Scene::Update(dt);
	Creditcheck(dt);
	MoveEnemiesApart();
}

bool SceneGameplay::Spawning(EnemiesList type, XMFLOAT3 pos)
{
	m_pEnemy = new Enemy;
	m_pEnemy->Assemble(type, m_pEnemy);
	m_pEnemy->GetEntity()->transform.SetPosition(pos);
	m_entities.push_back(m_pEnemy);
	m_enemies.push_back(m_pEnemy);

	return true;
}

void SceneGameplay::Creditcheck(float dt)
{
	m_credits++;
	if (m_credits > 10) {
		// enough credits to spawn
		m_credits = 0.0f;
		Spawning(SKELETAL_GRUNT, RandPos());
	}

}

void SceneGameplay::MoveEnemiesApart()
{
	for (auto enemy : m_enemies)
	{
		for (auto other : m_enemies)
		{
			if (other != enemy) {

				float otherX = other->m_pEntity->transform.pos.x;
				float otherY = other->m_pEntity->transform.pos.y;
				float otherZ = other->m_pEntity->transform.pos.z;

				float enemyX = enemy->m_pEntity->transform.pos.x;
				float enemyY = enemy->m_pEntity->transform.pos.y;
				float enemyZ = enemy->m_pEntity->transform.pos.z;

				float distance = sqrt(pow((otherX - enemyX), 2) + pow((otherY - enemyY), 2) + pow((otherZ - enemyZ), 2));
				XMFLOAT3 vector = {(otherX - enemyX), (otherY - enemyY), (otherZ - enemyZ)};

				if (distance < 1) other->m_pEntity->transform.SetPosition(0.0f, 0.0f, 0.0f);

			}
		}
	}
}

XMFLOAT3 SceneGameplay::RandPos()
{
	int random_integer;
	int lowest = 5, highest = 10;
	int range = (highest - lowest) + 1;
	random_integer = lowest + int(range * rand() / (RAND_MAX + 1.0));

	int random_integer2;
	int lowest2 = -1, highest2 = 1;
	int range2 = (highest2 - lowest2) + 1;
	random_integer2 = lowest2 + int(range2 * rand() / (RAND_MAX + 1.0));


	float x = mPlayer->GetPosition().x + random_integer * random_integer2;

	random_integer;
	lowest = 5, highest = 10;
	range = (highest - lowest) + 1;
	random_integer = lowest + int(range * rand() / (RAND_MAX + 1.0));

	random_integer2;
	lowest2 = -1, highest2 = 1;
	range2 = (highest2 - lowest2) + 1;
	random_integer2 = lowest2 + int(range2 * rand() / (RAND_MAX + 1.0));

	float z = mPlayer->GetPosition().z + random_integer * random_integer2;

	return {x, mPlayer->GetPosition().y + 2, z};
}


