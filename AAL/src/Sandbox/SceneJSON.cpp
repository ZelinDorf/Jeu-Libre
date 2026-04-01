#include "pch.h"
#include "SceneJSON.h"

SceneJSON::SceneJSON()
{
	pEntity = JsonObj::JsonLoader("box", this);
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
}
