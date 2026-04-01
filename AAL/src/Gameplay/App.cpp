#include "pch.h"
#include "App.h"

#include <iostream>

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
	m_font.Create(20);

	m_sceneManager.SetSceneActive<SceneMenu>(true);

	//camera
	CAMERA->transform.pos.z = -2.0f;
	CAMERA->transform.pos.y = 1.0f;

	mPlayer = new Player();
	mPlayer->Init(0);

	m_meshGround.CreateCube(mGroundSize, CPU_BLACK);
	pGround = cpuEngine.CreateEntity();
	pGround->pMesh = &m_meshGround;
	pGround->transform.pos = XMFLOAT3(0.f, -20.f, 0.f);
}

void App::OnUpdate()
{
	float dt = cpuTime.delta;
	InputSystem::HandleInput();

	if (InputSystem::IsKeyPressed(InputKeyboard::NUMPAD1)) m_sceneManager.SetSceneActive<SceneGameplay>(true);
	if (InputSystem::IsKeyPressed(InputKeyboard::NUMPAD2)) m_sceneManager.SetSceneActive<SceneMenu>(true);

	m_sceneManager.Update(dt);

	float speed = 10.f;

	if (cpuInput.IsUp())
		CAMERA->transform.dir.z = speed;
	else if (cpuInput.IsDown())
		CAMERA->transform.dir.z = -speed;
	else
		CAMERA->transform.dir.z = 0.0f;
	if (cpuInput.IsRight())
		CAMERA->transform.dir.x = speed;
	else if (cpuInput.IsLeft())
		CAMERA->transform.dir.x = -speed;
	else
		CAMERA->transform.dir.x = 0.0f;

	CAMERA->transform.Move(1.0f * cpuTime.delta);

	float time = cpuTime.total;

	mPlayer->Update(dt);

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
	m_pEnemy->Destroy();
	mPlayer->Destroy();
	delete mPlayer;
	pGround = cpuEngine.Release(pGround);
}

void App::OnRender(int pass)
{
	m_sceneManager.OnRender(pass);

	// Debug
	cpu_stats& stats = *cpuEngine.GetStats();
	std::string info = CPU_STR(cpuTime.fps) + " fps, ";
	info += CPU_STR(stats.drawnTriangleCount) + " triangles, ";
	info += CPU_STR(stats.clipEntityCount) + " clipped entities\n";
	info += CPU_STR(cpuEngine.GetParticleData()->alive) + " particles, ";
	info += CPU_STR(stats.threadCount) + " threads, ";
	info += CPU_STR(stats.tileCount) + " tiles";

	XMFLOAT3 tint = { 1.0f, 1.0f, 0.8f };
	cpuDevice.DrawText(&m_font, info.c_str(), (int)(cpuDevice.GetWidth() * 0.5f), 10, CPU_TEXT_CENTER, &tint);
}

void App::MyPixelShader(cpu_ps_io& io)
{
	io.color = io.p.color;
}



void App::SpawnPlayer()
{
}
