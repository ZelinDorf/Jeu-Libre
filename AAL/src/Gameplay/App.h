#pragma once
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

	float m_GroundSize = 18.75f;

private:
	inline static App* s_pApp = nullptr;

	cpu_entity* p_Ground = nullptr;
	cpu_mesh m_meshGround;

	Player* m_player = nullptr;

	void SpawnPlayer();
};
