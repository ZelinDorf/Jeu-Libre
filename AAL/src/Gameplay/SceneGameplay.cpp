#include "pch.h"
#include "SceneGameplay.h"
#include "App.h"
#include "Sword.h"

SceneGameplay::SceneGameplay()
{
	//!\ ORDER FOR Z-INDEX /!\\
	// needs UIWrapper

	chunkManager->InitMap(10.f);
	Vector<Chunk*> chunks = chunkManager->GetMap();

	for (size_t i = 0; i < chunks.size(); i++)
	{
		m_entities.push_back(chunks[i]);
	}

	Player* player = new Player();
	m_pPlayer = player;
	player->Init(0, 0, 1);
	m_pPlayer->SetPosition({ 80.0f,-.5f,80.0f });
	m_entities.push_back(player);

}

SceneGameplay::~SceneGameplay()
{

}

void SceneGameplay::OnRender(int pass)
{
	cpu_font* pFont = App::GetInstance().GetFont();
	String info = "Score : " + CPU_STR(m_score);
	cpuDevice.DrawText(pFont, info.c_str(), (int)(cpuDevice.GetWidth() * 0.5f), 10, CPU_TEXT_LEFT);
}

void SceneGameplay::Update(float dt)
{
	Scene::Update(dt);
	Creditcheck(dt);
	Collisions(dt);

	if ((m_score) % 10 == 0)
	{
		if (m_canSpawnSword) {
			m_canSpawnSword = false;

			Sword* sword = new Sword;
			m_pPlayer->m_vSwords.push_back(sword);
			m_entities.push_back(sword);
		}
	}
	else
	{
		m_canSpawnSword = true;
	}
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
	m_credits += (m_score / 10); // increase credits gain as score increases

	if (m_credits > 75 && m_enemies.size() < 100 + m_score) {
		// enough credits to spawn
		m_credits = 0.0f;

		if (RandomInt(0, 1) == 0)
			Spawning(CINUT, RandPos());
		else
			Spawning(SKELETAL_HEAD, RandPos());
	}
}

void SceneGameplay::Collisions(float dt) {
	MoveEnemiesApart(dt);
	CollisionPlayerEnemy(dt);
	CollisionSwordEnemy();
}

void SceneGameplay::MoveEnemiesApart(float dt)
{
	for (Enemy* enemy : m_enemies)
	{
		int i = 0;
		for (Enemy* other : m_enemies)
		{
			if (other != enemy) {

				float otherX = other->m_pEntity->transform.pos.x;
				float otherY = other->m_pEntity->transform.pos.y;
				float otherZ = other->m_pEntity->transform.pos.z;

				float enemyX = enemy->m_pEntity->transform.pos.x;
				float enemyY = enemy->m_pEntity->transform.pos.y;
				float enemyZ = enemy->m_pEntity->transform.pos.z;

				float distance = sqrt(pow((otherX - enemyX), 2) + pow((otherY - enemyY), 2) + pow((otherZ - enemyZ), 2));
				XMFLOAT3 vector = { (otherX - enemyX), (otherY - enemyY), (otherZ - enemyZ) };

				if (distance < 1.5f && distance > .01f) {
					other->m_pEntity->transform.Translate(vector, (1 / distance) * dt);
					other->m_speed = 0.0f;
				}
				else {
					other->m_speed = 1.0f;
				}

				if (distance <= 0.01f) {

					other->DamageTaken();
					other->m_currentHealth--;

					if (other->Death())
					{
						m_enemies.erase(m_enemies.begin() + i);
						m_score++;
						i--;
					}
				}
				i++;
			}
		}
	}
}
void SceneGameplay::CollisionPlayerEnemy(float dt)
{
	int i = 0;
	for (Enemy* enemy : m_enemies)
	{
		XMFLOAT3 playerPos = m_pPlayer->GetPosition();
		XMFLOAT3 enemyPos = enemy->m_pEntity->transform.pos;

		float distance = sqrt(pow((playerPos.x - enemyPos.x), 2) + pow((playerPos.y - enemyPos.y), 2) + pow((playerPos.z - enemyPos.z), 2));
		XMFLOAT3 vector = { (playerPos.x - enemyPos.x), (playerPos.y - enemyPos.y), (playerPos.z - enemyPos.z) };

		if (distance < 1.5f && distance > .01f) {
			enemy->m_pEntity->transform.Translate(vector, (1 / distance) * dt);
			enemy->m_speed = 0.0f;
		}
		else {
			enemy->m_speed = 1.0f;
		}
		i++;
	}	

}

void SceneGameplay::CollisionSwordEnemy()
{
	for (Sword* sword : Player::m_vSwords)
	{
		int i = 0;
		for (Enemy* enemy : m_enemies)
		{
			XMFLOAT3 swordPos = sword->m_pEntity->transform.pos;
			XMFLOAT3 enemyPos = enemy->m_pEntity->transform.pos;

			float distance = sqrt(pow((swordPos.x - enemyPos.x), 2) + pow((swordPos.y - enemyPos.y), 2) + pow((swordPos.z - enemyPos.z), 2));

			if (distance <= 1.f) //contact
			{
				enemy->DamageTaken();
				if (enemy->Death()) {
					m_enemies.erase(m_enemies.begin() + i);
					m_score++;
					i--;
				};
			}
			i++;
		}

	}
}

XMFLOAT3 SceneGameplay::RandPos()
{
	int random_integer = RandomInt(5, 10);
	int random_integer2 = RandomInt(0, 1);
	if (random_integer2 == 0) random_integer2 = -1;
	float x = m_pPlayer->GetPosition().x + random_integer * random_integer2;

	random_integer = RandomInt(5, 10);
	random_integer2 = RandomInt(0, 1);
	if (random_integer2 == 0) random_integer2 = -1;
	float z = m_pPlayer->GetPosition().z + random_integer * random_integer2;

	return { x, m_pPlayer->GetPosition().y , z };
}

int SceneGameplay::RandomInt(int min, int max)
{
	int range = (max - min) + 1;
	return min + int(range * rand() / (RAND_MAX + 1.0));
}


