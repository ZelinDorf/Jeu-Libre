#pragma once
#include "Lib/Enemy.h"
#include <vector>
#include <string>
#include "../Lib/Player.h"

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

	InputSystem input;
private:
	inline static App* s_pApp = nullptr;
	Enemy* m_pEnemy;
	float mGroundSize = 18.75f;

	cpu_mesh m_meshGround;

	Player* mPlayer = nullptr;

	void SpawnPlayer();
};

