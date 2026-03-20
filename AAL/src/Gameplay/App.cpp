#include "pch.h"
#include "App.h"
#include <iostream>
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
	mPlayer = nullptr;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void App::OnStart()
{
	m_pEnemy = new Enemy;
	m_pEnemy->Assemble(SKELETAL_GRUNT, m_pEnemy);

	cpuEngine.GetCamera()->transform.pos.z = -5.0f;


	

	mPlayer = new Player();
	mPlayer->Init();

	m_meshGround.CreateCube(mGroundSize, CPU_BLACK);
	cpu_entity* pGround = cpuEngine.CreateEntity();
	pGround->pMesh = &m_meshGround;
	pGround->transform.pos = XMFLOAT3(0.f, -20.f, 0.f);
}

void App::OnUpdate()
{
	m_pEnemy->Update();
	input.HandleInput();

	if (input.IsKeyDown(DELETE_)) m_pEnemy->~Enemy();

	if (input.IsKeyDown(DOWN_ARROW)) { m_pEnemy->GetEntity()->transform.Move(-10); }

	if (input.IsKeyDown(UP_ARROW)) {
		m_pEnemy = new Enemy;
		m_pEnemy->Assemble(SKELETAL_GRUNT, m_pEnemy);
		float dt = cpuTime.delta;
		float time = cpuTime.total;

		mPlayer->Update(dt);

		if (InputSystem::IsKeyDown(SPACEBAR))
			cpuEngine.GetCamera()->transform.SetYPR(0.f, 1.570796f, 0.f);

		// Quit
		if (InputSystem::IsKeyPressed(ESCAPE))
		{
			cpuEngine.Quit();
		}
	}
}

void App::OnExit()
{
	m_pEnemy->Destroy();
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
