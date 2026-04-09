#pragma once
#include "Scene.h"
#include "Player.h"
#include "ChunkManager.h"

class SceneGameplay : public Scene
{
public:
	SceneGameplay();
	~SceneGameplay();
	void OnRender(int pass) override;
	void Update(float dt) override;

	bool Spawning(EnemiesList type = SKELETAL_HEAD, XMFLOAT3 pos={0,0,0});
	void Creditcheck(float dt);

	void MoveEnemiesApart(float dt);
	void CollisionPlayerEnemy();

	XMFLOAT3 RandPos();
	int RandomInt(int min, int max);

	float m_credits = 0.0f;
	int m_score = 0;

private:
	Enemy* m_pEnemy = nullptr;
	ChunkManager* m_pChunkManager = nullptr;

	Player* m_pPlayer = nullptr;
};

