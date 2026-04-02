#include "pch.h"
#include "InputSystem.h"

App::App()
{
	s_pApp = this;
	CPU_CALLBACK_START(OnStart);
	CPU_CALLBACK_UPDATE(OnUpdate);
	CPU_CALLBACK_EXIT(OnExit);
	CPU_CALLBACK_RENDER(OnRender);
}

App::~App()
{
	m_player = nullptr;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void App::OnStart()
{
	m_player = new Player();
	m_player->Init(0);

	m_meshGround.CreateCube(m_GroundSize, CPU_BLACK);
	p_Ground = cpuEngine.CreateEntity();
	p_Ground->pMesh = &m_meshGround;
	p_Ground->transform.pos = XMFLOAT3(0.f, -20.f, 0.f);
}

void App::OnUpdate()
{
	float dt = cpuTime.delta;
	float time = cpuTime.total;

	m_player->Update(dt);

	InputSystem::HandleInput();


	// Camera movement
	if (InputSystem::IsKeyDown(LEFT))
		cpuEngine.GetCamera()->transform.AddYPR(-1.5f * dt);
	if (InputSystem::IsKeyDown(RIGHT))
		cpuEngine.GetCamera()->transform.AddYPR(1.5f * dt);
	if (InputSystem::IsKeyDown(UP))
		cpuEngine.GetCamera()->transform.Move(10.0f * dt);
	if (InputSystem::IsKeyDown(DOWN))
		cpuEngine.GetCamera()->transform.Move(-10.0f * dt);

	if (InputSystem::IsKeyDown(SPACEBAR))
		cpuEngine.GetCamera()->transform.SetYPR(0.f, 1.570796f, 0.f);

	// Quit
	if (InputSystem::IsKeyPressed(ESCAPE))
	{
		cpuEngine.Quit();
	}
}

void App::OnExit()
{
	m_player->Destroy();
	delete m_player;
	p_Ground = cpuEngine.Release(p_Ground);
}

void App::OnRender(int pass)
{
}

void App::MyPixelShader(cpu_ps_io& io)
{
	io.color = io.p.color;
}



void App::SpawnPlayer()
{
}
