#pragma once
#include "CollisionType.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>

class AALentity; // forward declaration

class ColliderManager
{
	ColliderManager();
	~ColliderManager();

	void CheckCollision(std::unordered_map<EntityType, std::unordered_set<AALentity*>>& entities);

	void CheckCollisionBetweenTypes(std::unordered_set<AALentity*>& entities1, std::unordered_set<AALentity*>& entities2);

	std::vector<std::pair<EntityType, EntityType>> m_collisionsToCheck;
	std::unordered_map<AALentity*, std::unordered_set<AALentity*>> m_collisionsOccurred;

};

