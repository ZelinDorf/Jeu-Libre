#pragma once

class SceneGameMenu : public Scene
{
public:
	SceneGameMenu();
	~SceneGameMenu();
	void OnRender(int pass) override;
	void Update(float dt) override;

private:
	cpu_font m_font;
};

