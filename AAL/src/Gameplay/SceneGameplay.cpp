#include "pch.h"
#include "SceneGameplay.h"
#include "App.h"

SceneGameplay::SceneGameplay()
{
	chunkManager->InitMap(10.f);

	Vector<Chunk*> chunks = chunkManager->GetMap();
	
	for (size_t i = 0; i < chunks.size(); i++)
	{
		m_entities.push_back(chunks[i]);
	}

	Player* player = new Player();
	player->Init(0);
	m_pPlayer = player;

	m_entities.push_back(player);
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
	MoveEnemiesApart(dt);
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
	if (m_credits > 50 && m_entities.size() < 105) {
		// enough credits to spawn
		m_credits = 0.0f;
		Spawning(CINUT, RandPos());

	}
}

void SceneGameplay::MoveEnemiesApart(float dt)
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

				if (distance < 1.5f && distance > .01f) {
					other->m_pEntity->transform.Translate(vector,  (1 / distance) * dt);
					enemy->m_pEntity->transform.Translate(vector, -(1 / distance) * dt);
				}

				if (distance <= 0.01f ) { other->m_pEntity->transform.SetPosition(.0f, -100.f, .0f); };
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


	float x = m_pPlayer->GetPosition().x + random_integer * random_integer2;

	random_integer;
	lowest = 5, highest = 10;
	range = (highest - lowest) + 1;
	random_integer = lowest + int(range * rand() / (RAND_MAX + 1.0));

	random_integer2;
	lowest2 = -1, highest2 = 1;
	range2 = (highest2 - lowest2) + 1;
	random_integer2 = lowest2 + int(range2 * rand() / (RAND_MAX + 1.0));

	float z = m_pPlayer->GetPosition().z + random_integer * random_integer2;
	return {x, m_pPlayer->GetPosition().y , z};
}


