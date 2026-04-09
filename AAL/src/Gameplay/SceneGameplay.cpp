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
	cpu_font* pFont = App::GetInstance().GetFont();
	String info = "Score : " + CPU_STR(m_score);
	cpuDevice.DrawText(pFont, info.c_str(), (int)(cpuDevice.GetWidth() * 0.8f), 10, CPU_TEXT_LEFT);
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
	if (m_credits > 100 && m_enemies.size() < 100) {
		// enough credits to spawn
		m_credits = 0.0f;


		Spawning(CINUT, RandPos());
		Spawning(CINUT, RandPos());
	}
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
				XMFLOAT3 vector = {(otherX - enemyX), (otherY - enemyY), (otherZ - enemyZ)};

				if (distance < 1.5f && distance > .01f) {
					other->m_pEntity->transform.Translate(vector,  (1 / distance) * dt);
					other->m_speed = 0.0f;
				}
				else {
					other->m_speed = 1.0f;
				}

				if (distance <= 0.01f ) {
					other->Destroy();
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
	int random_integer2 = RandomInt(0,1);
	if (random_integer2 == 0) random_integer2 = -1;
	float x = m_pPlayer->GetPosition().x + random_integer * random_integer2;
	
	random_integer = RandomInt(5, 10);
	random_integer2 = RandomInt(0, 1);
	if (random_integer2 == 0) random_integer2 = -1;
	float z = m_pPlayer->GetPosition().z + random_integer * random_integer2;

	return {x, m_pPlayer->GetPosition().y , z};
}

int SceneGameplay::RandomInt(int min, int max)
{
	int range = (max - min) + 1;
	return min + int(range * rand() / (RAND_MAX + 1.0));
}


