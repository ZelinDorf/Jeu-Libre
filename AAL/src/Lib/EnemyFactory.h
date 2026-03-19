#pragma once
#include "Lib/Enemy.h"
#include "Lib/AALentity.h"

class EnemyFactory : Enemy
{
public:
	// vector stats must be {maxHP, dmg, spd, atkSpd, armor, xp, cost}
	void Assemble(Vector<float> stats, int id, cpu_entity* entity, cpu_mesh* mesh, cpu_material* mat);
};

