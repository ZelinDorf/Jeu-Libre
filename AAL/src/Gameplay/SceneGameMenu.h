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
	float m_charSelected = 2;
	float m_weaponSelected = 2;
	String m_text = "[ ??? ]";
};

