#pragma once
enum StatsEnum
{
	// Stats shared by player and enemies
	MAX_HEALTH,
	DAMAGE,
	ATTACK_SPEED,
	ARMOR,
	SPEED,

	// Stats specific to enemies & bosses
	COST,
	ID,
	MINMAP_ID,
	XP_DROP,

	// stats specific to the player
	JUMP_FORCE,
	JUMP_AMOUNT,
	ACCELERATION,
	GRAVITY_FACTOR,
	COOLDOWN,
};
