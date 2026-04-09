#pragma once
#include "Scene.h"

class SceneJSON : public Scene
{
public:
	SceneJSON();
	~SceneJSON();
	void OnRender(int pass) override;
	void Update(float dt) override;

private:
	cpu_entity* pEntity;
	cpu_mesh m;
};