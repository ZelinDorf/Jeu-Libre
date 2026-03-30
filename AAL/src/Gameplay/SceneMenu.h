#pragma once
#include "Scene.h"

class SceneMenu : public Scene
{
	SceneMenu();
	~SceneMenu();
	void OnRender(int pass) override;
	void Update(float dt) override;
};

