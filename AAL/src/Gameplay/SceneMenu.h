#pragma once
#include "Scene.h"

class SceneMenu : public Scene
{
public:
	SceneMenu();
	~SceneMenu();
	void OnRender(int pass) override;
	void Update(float dt) override;

private:
	cpu_font m_font;

};

