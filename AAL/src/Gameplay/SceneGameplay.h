#pragma once
#include "Scene.h"

class SceneGameplay : public Scene
{
public:
	SceneGameplay();
	~SceneGameplay();
	void OnRender(int pass) override;
	void Update(float dt) override;

private:
	Enemy* m_pEnemy;
};

