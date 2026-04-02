#include "pch.h"
#include "SceneJSON.h"

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
	// YOUR CODE HERE
	RessourcesManager rm;

	m_sceneManager.SetSceneActive<SceneJSON>(true);

	cpuEngine.GetCamera()->transform.pos.z = -5.0f;
}

void App::OnUpdate()
{
	// YOUR CODE HERE
	float dt = cpuTime.delta;

	m_sceneManager.Update(dt); 
	
	float speed = 10.f;

	/*if (cpuInput.IsUp())
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
		CAMERA->transform.dir.x = 0.0f;*/

	CAMERA->transform.Move(1.0f * cpuTime.delta);

	//std::cout << CAMERA->transform.pos.x << "CAMERA" << CAMERA->transform.pos.z << std::endl;
}

void App::OnExit()
{
	// YOUR CODE HERE
}

void App::OnRender(int pass)
{
	// YOUR CODE HERE
	m_sceneManager.OnRender(pass);
}

void App::MyPixelShader(cpu_ps_io& io)
{
	// YOUR CODE HERE
	io.color = io.p.color;
}
