#include "pch.h"
#include "SceneJSON.h"

SceneJSON::SceneJSON()
{
	JsonObj::JsonLoader(JSON_PATH"fox.json", this, pEntity);
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
