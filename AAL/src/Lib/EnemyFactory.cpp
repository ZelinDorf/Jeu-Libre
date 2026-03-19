#include "pch.h"
#include "Lib/EnemyFactory.h"

void EnemyFactory::Assemble(Vector<float> stats, int id, cpu_entity* entity, cpu_mesh* mesh, cpu_material* mat)
{
	if (stats.size() != 7) return;

	Enemy::m_maxHealth = stats[0];
	Enemy::m_damage = stats[1];
	Enemy::m_speed = stats[2];
	Enemy::m_atkSpeed = stats[3];
	Enemy::m_armor = stats[4];
	Enemy::m_xpDrop = stats[5];
	Enemy::m_cost = stats[6];

	Enemy::m_id = id;

	// + setup the meshes of the monster her

	entity = cpuEngine.CreateEntity();
	entity->pMesh = mesh;
	entity->pMaterial = mat;
}
