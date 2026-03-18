#pragma once


class EnemiesRegistery
{
public:
	enum EnemiesList {
		SKELETAL_GRUNT,
		SKELETAL_MAGE,
		SKELETAL_ARCHER,
	};

	void Create(EnemiesList enemyType);
};

