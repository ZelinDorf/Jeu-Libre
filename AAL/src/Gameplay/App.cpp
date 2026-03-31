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

}

void App::OnExit()
{
	m_pEnemy->Destroy();
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
	// YOUR CODE HERE
	io.color = io.p.color;
}
