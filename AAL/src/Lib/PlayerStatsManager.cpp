#include "pch.h"
#include "PlayerStatsManager.h"

void PlayerStatsManager::SetBaseSpeed(float _speed)
{
	m_BaseSpeed = _speed;
}

void PlayerStatsManager::SetSpeedMultiplier(float _multiplier)
{
	m_SpeedMultiplier = _multiplier;
}

float PlayerStatsManager::GetBaseSpeed()
{
	return m_BaseSpeed;
}

float PlayerStatsManager::GetSpeedMultiplier()
{
	return m_SpeedMultiplier;
}

float PlayerStatsManager::GetFinalSpeed()
{
	m_FinalSpeed = m_BaseSpeed * m_SpeedMultiplier;
	return m_FinalSpeed;
}

void PlayerStatsManager::SetBaseJumpForce(float _jumpForce)
{
	m_BaseJumpForce = _jumpForce;
}

void PlayerStatsManager::SetJumpForceMultiplier(float _multiplier)
{
	m_JumpForceMultiplier = _multiplier;
}

float PlayerStatsManager::GetBaseJumpForce()
{
	return m_BaseJumpForce;
}

float PlayerStatsManager::GetJumpForceMultiplier()
{
	return m_JumpForceMultiplier;
}

float PlayerStatsManager::GetFinalJumpForce()
{
	m_FinalJumpForce = m_BaseJumpForce * m_JumpForceMultiplier;
	return m_FinalJumpForce;
}

void PlayerStatsManager::SetBaseAttackDamage(int _weapon, float _dmg)
{
	if (_weapon == 1)
	{
		m_Weapon1BaseAttackDamage = _dmg;
	}
	else if (_weapon == 2)
	{
		m_Weapon2BaseAttackDamage = _dmg;
	}
}

void PlayerStatsManager::SetAdditionalAttackDamage(int _weapon, float _dmg)
{
	if (_weapon == 1)
	{
		m_Weapon1AdditionalAttackDamage = _dmg;
	}
	else if (_weapon == 2)
	{
		m_Weapon2AdditionalAttackDamage = _dmg;
	}
}

void PlayerStatsManager::SetAttackDamageMultiplier(int _weapon, float _multiplier)
{
	if (_weapon == 1)
	{
		m_Weapon1AdditionalAttackDamage = _multiplier;
	}
	else if (_weapon == 2)
	{
		m_Weapon2AttackDamageMultiplier = _multiplier;
	}
}

float PlayerStatsManager::GetBaseAttackDamage(int _weapon)
{
	if (_weapon == 1)
	{
		return m_Weapon1BaseAttackDamage;
	}
	else if (_weapon == 2)
	{
		return m_Weapon2BaseAttackDamage;
	}
}

float PlayerStatsManager::GetAdditionalAttackDamage(int _weapon)
{
	if (_weapon == 1)
	{
		return m_Weapon1AdditionalAttackDamage;
	}
	else if (_weapon == 2)
	{
		return m_Weapon2AdditionalAttackDamage;
	}
}

float PlayerStatsManager::GetAttackDamageMultiplier(int _weapon)
{
	if (_weapon == 1)
	{
		return m_Weapon1AdditionalAttackDamage;
	}
	else if (_weapon == 2)
	{
		return m_Weapon2AttackDamageMultiplier;
	}
}

float PlayerStatsManager::GetFinalAttackDamage(int _weapon)
{
	if (_weapon == 1)
	{
		m_Weapon1FinalAttackDamage = m_Weapon1BaseAttackDamage * m_Weapon1AdditionalAttackDamage + m_Weapon1AdditionalAttackDamage;
		return m_Weapon1FinalAttackDamage;
	}
	else if (_weapon == 2)
	{
		m_Weapon2FinalAttackDamage = m_Weapon2BaseAttackDamage * m_Weapon2AttackDamageMultiplier + m_Weapon2AdditionalAttackDamage;
		return m_Weapon2FinalAttackDamage;
	}
	
}

void PlayerStatsManager::SetBaseAttackRefreshingTime(int _weapon, float _time)
{
	if (_weapon == 1)
	{
		m_Weapon1BaseAttackRefreshingTime = _time;
	}
	else if (_weapon == 2)
	{
		m_Weapon2BaseAttackRefreshingTime = _time;
	}
}

void PlayerStatsManager::SetAttackRefreshingMultiplier(int _weapon, float _multiplier)
{
	if (_weapon == 1)
	{
		m_Weapon1AttackRefreshingTimeMultiplier = _multiplier;
	}
	else if (_weapon == 2)
	{
		m_Weapon2AttackRefreshingTimeMultiplier = _multiplier;
	}
}

float PlayerStatsManager::GetBaseAttackRefreshingTime(int _weapon)
{
	if (_weapon == 1)
	{
		return m_Weapon1BaseAttackRefreshingTime;
	}
	else if (_weapon == 2)
	{
		return m_Weapon2BaseAttackRefreshingTime;
	}
}

float PlayerStatsManager::GetAttackRefreshingMultiplier(int _weapon)
{
	if (_weapon == 1)
	{
		return m_Weapon1AttackRefreshingTimeMultiplier;
	}
	else if (_weapon == 2)
	{
		return m_Weapon2AttackRefreshingTimeMultiplier;
	}
}

float PlayerStatsManager::GetFinalAttackRefreshingTime(int _weapon)
{
	if (_weapon == 1)
	{
		m_Weapon1FinalAttackRefreshingtime = m_Weapon1BaseAttackRefreshingTime * m_Weapon1AttackRefreshingTimeMultiplier;
		return m_Weapon1FinalAttackRefreshingtime;
	}
	else if (_weapon == 2)
	{
		m_Weapon2FinalAttackRefreshingtime = m_Weapon2BaseAttackRefreshingTime * m_Weapon2AttackRefreshingTimeMultiplier;
		return m_Weapon2FinalAttackRefreshingtime;
	}
}
