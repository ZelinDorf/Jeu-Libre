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

private:
	Enemy* m_pEnemy = nullptr;
	ChunkManager* m_pChunkManager = nullptr;

	Player* mPlayer = nullptr;
};

