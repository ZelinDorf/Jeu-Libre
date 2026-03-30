#pragma once
#include "SceneGameplay.h"
#include "SceneMenu.h"
#include <vector>
#include <string>

class App
{
public:
	App();
	virtual ~App();

	static App& GetInstance() { return *s_pApp; }

	void OnStart();
	void OnUpdate();
	void OnExit();
	void OnRender(int pass);

	static void MyPixelShader(cpu_ps_io& io);

private:
	cpu_font m_font;
	inline static App* s_pApp = nullptr;
	Enemy* m_pEnemy;
	SceneManager m_sceneManager;
};

