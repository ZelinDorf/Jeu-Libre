#pragma once
#include "Scene.h"
#include "Player.h"

class SceneGameplay : public Scene
{
public:
	SceneGameplay();
	~SceneGameplay();
	void OnRender(int pass) override;
	void Update(float dt) override;

private:
	Enemy* m_pEnemy;
	ChunkManager* m_pChunkManager;

	Player* mPlayer = nullptr;
};

