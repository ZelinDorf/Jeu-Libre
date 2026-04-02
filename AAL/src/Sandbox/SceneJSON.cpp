#include "pch.h"
#include "SceneJSON.h"

SceneJSON::SceneJSON()
{
	JsonObj::JsonLoader(JSON_PATH"fox.json", this, pEntity);
	//m.CreateCube();
	//pEntity->pMesh = &m;
	//pEntity->transform.SetScaling(1);
	//AddEntity(pEntity);
}

SceneJSON::~SceneJSON()
{
}

void SceneJSON::OnRender(int pass)
{

}

void SceneJSON::Update(float dt)
{
	Scene::Update(dt);

	float speed = 10.f;

	if (cpuInput.IsUp())
		pEntity->transform.dir.z = speed;
	else if (cpuInput.IsDown())
		pEntity->transform.dir.z = -speed;
	else
		pEntity->transform.dir.z = 0.0f;
	if (cpuInput.IsRight())
		pEntity->transform.dir.x = speed;
	else if (cpuInput.IsLeft())
		pEntity->transform.dir.x = -speed;
	else
		pEntity->transform.dir.x = 0.0f;

	//pEntity->transform.Move(1.0f * cpuTime.delta);
}
