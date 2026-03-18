#include "pch.h"
#include "EnemiesRegistery.h"
#include "EnemyFactory.h"
#include "AALentity.h"

void EnemiesRegistery::Create(EnemiesList enemyType)
{
	EnemyFactory* fact;
	AALentity* aal;
 	switch (enemyType)
	{
	case EnemiesRegistery::SKELETAL_GRUNT:
		fact->Assemble({ 10.0f, 10.0f, 10.0f, 1.0f, 10.0f, 10.0f, 1.0f }, 0, aal->m_pEntity, &aal->m_mesh, &aal->m_mat);
		break;
	case EnemiesRegistery::SKELETAL_MAGE:
		break;
	case EnemiesRegistery::SKELETAL_ARCHER:
		break;
	default:
		break;
	}

}
