#pragma once
#include "Scene.h"

class SceneJSON : public Scene
{
	SceneJSON();
	~SceneJSON();
	void OnRender(int pass) override;
	void Update(float dt) override;
};

