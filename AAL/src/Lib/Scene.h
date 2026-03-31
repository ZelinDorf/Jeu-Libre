#pragma once
#include <unordered_map>

class UIWrapper;
class Scene

{
public:
	Scene();
	~Scene();

	bool IsActive();
	void SetActive(bool active);

	virtual void Update(float dt);
	virtual void OnRender(int pass);

	void Reset();

	void AddEntity(AALentity* entity);

	UIWrapper* AddUI(EntityType entityType);
	UIWrapper* GetUI(EntityType entityType);

protected:
	bool m_active = false;
	
	Vector<AALentity*> m_entities;
	Vector<int> m_entitiesID;

	std::unordered_map<EntityType, UIWrapper*> m_mapUI;



};

