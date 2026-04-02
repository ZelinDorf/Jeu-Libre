#include "pch.h"
#include "SceneJSON.h"
#include "App.h"

SceneJSON::SceneJSON()
{
	JsonObj::JsonLoader(JSON_PATH"box.json", this, pEntity);
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
}
