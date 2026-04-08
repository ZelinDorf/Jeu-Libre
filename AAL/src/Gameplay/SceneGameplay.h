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

	bool Spawning(EnemiesList type=SKELETAL_GRUNT, XMFLOAT3 pos={0,0,0});
	void Creditcheck(float dt);
	void MoveEnemiesApart(float dt);

	XMFLOAT3 RandPos();

	float m_credits = 0.0f;
private:
	Enemy* m_pEnemy = nullptr;
	ChunkManager* m_pChunkManager = nullptr;

	Player* m_pPlayer = nullptr;
};

