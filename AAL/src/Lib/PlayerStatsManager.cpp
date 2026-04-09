#include "pch.h"
#include "PlayerStatsManager.h"

void PlayerStatsManager::SetBaseSpeed(float _speed)
{
	m_baseSpeed = _speed;
}

void PlayerStatsManager::SetSpeedMultiplier(float _multiplier)
{
	m_speedMultiplier = _multiplier;
}

float PlayerStatsManager::GetBaseSpeed()
{
	return m_baseSpeed;
}

float PlayerStatsManager::GetSpeedMultiplier()
{
	return m_speedMultiplier;
}

float PlayerStatsManager::GetFinalSpeed()
{
	m_finalSpeed = m_baseSpeed * m_speedMultiplier;
	return m_finalSpeed;
}

void PlayerStatsManager::SetBaseJumpForce(float _jumpForce)
{
	m_baseJumpForce = _jumpForce;
}

void PlayerStatsManager::SetJumpForceMultiplier(float _multiplier)
{
	m_jumpForceMultiplier = _multiplier;
}

float PlayerStatsManager::GetBaseJumpForce()
{
	return m_baseJumpForce;
}

float PlayerStatsManager::GetJumpForceMultiplier()
{
	return m_jumpForceMultiplier;
}

float PlayerStatsManager::GetFinalJumpForce()
{
	m_finalJumpForce = m_baseJumpForce * m_jumpForceMultiplier;
	return m_finalJumpForce;
}

void PlayerStatsManager::SetBaseAttackDamage(int _weapon, float _dmg)
{
	if (_weapon == 1)
	{
		m_weapon1BaseAttackDamage = _dmg;
	}
	else if (_weapon == 2)
	{
		m_weapon2BaseAttackDamage = _dmg;
	}
}

void PlayerStatsManager::SetAdditionalAttackDamage(int _weapon, float _dmg)
{
	if (_weapon == 1)
	{
		m_weapon1AdditionalAttackDamage = _dmg;
	}
	else if (_weapon == 2)
	{
		m_weapon2AdditionalAttackDamage = _dmg;
	}
}

void PlayerStatsManager::SetAttackDamageMultiplier(int _weapon, float _multiplier)
{
	if (_weapon == 1)
	{
		m_weapon1AdditionalAttackDamage = _multiplier;
	}
	else if (_weapon == 2)
	{
		m_weapon2AttackDamageMultiplier = _multiplier;
	}
}

float PlayerStatsManager::GetBaseAttackDamage(int _weapon)
{
	if (_weapon == 1)
	{
		return m_weapon1BaseAttackDamage;
	}
	else if (_weapon == 2)
	{
		return m_weapon2BaseAttackDamage;
	}
}

float PlayerStatsManager::GetAdditionalAttackDamage(int _weapon)
{
	if (_weapon == 1)
	{
		return m_weapon1AdditionalAttackDamage;
	}
	else if (_weapon == 2)
	{
		return m_weapon2AdditionalAttackDamage;
	}
}

float PlayerStatsManager::GetAttackDamageMultiplier(int _weapon)
{
	if (_weapon == 1)
	{
		return m_weapon1AdditionalAttackDamage;
	}
	else if (_weapon == 2)
	{
		return m_weapon2AttackDamageMultiplier;
	}
}

float PlayerStatsManager::GetFinalAttackDamage(int _weapon)
{
	if (_weapon == 1)
	{
		m_weapon1FinalAttackDamage = m_weapon1BaseAttackDamage * m_weapon1AdditionalAttackDamage + m_weapon1AdditionalAttackDamage;
		return m_weapon1FinalAttackDamage;
	}
	else if (_weapon == 2)
	{
		m_weapon2FinalAttackDamage = m_weapon2BaseAttackDamage * m_weapon2AttackDamageMultiplier + m_weapon2AdditionalAttackDamage;
		return m_weapon2FinalAttackDamage;
	}
	
}

void PlayerStatsManager::SetBaseAttackRefreshingTime(int _weapon, float _time)
{
	if (_weapon == 1)
	{
		m_weapon1BaseAttackRefreshingTime = _time;
	}
	else if (_weapon == 2)
	{
		m_weapon2BaseAttackRefreshingTime = _time;
	}
}

void PlayerStatsManager::SetAttackRefreshingMultiplier(int _weapon, float _multiplier)
{
	if (_weapon == 1)
	{
		m_weapon1AttackRefreshingTimeMultiplier = _multiplier;
	}
	else if (_weapon == 2)
	{
		m_weapon2AttackRefreshingTimeMultiplier = _multiplier;
	}
}

float PlayerStatsManager::GetBaseAttackRefreshingTime(int _weapon)
{
	if (_weapon == 1)
	{
		return m_weapon1BaseAttackRefreshingTime;
	}
	else if (_weapon == 2)
	{
		return m_weapon2BaseAttackRefreshingTime;
	}
}

float PlayerStatsManager::GetAttackRefreshingMultiplier(int _weapon)
{
	if (_weapon == 1)
	{
		return m_weapon1AttackRefreshingTimeMultiplier;
	}
	else if (_weapon == 2)
	{
		return m_weapon2AttackRefreshingTimeMultiplier;
	}
}

float PlayerStatsManager::GetFinalAttackRefreshingTime(int _weapon)
{
	if (_weapon == 1)
	{
		m_weapon1FinalAttackRefreshingtime = m_weapon1BaseAttackRefreshingTime * m_weapon1AttackRefreshingTimeMultiplier;
		return m_weapon1FinalAttackRefreshingtime;
	}
	else if (_weapon == 2)
	{
		m_weapon2FinalAttackRefreshingtime = m_weapon2BaseAttackRefreshingTime * m_weapon2AttackRefreshingTimeMultiplier;
		return m_weapon2FinalAttackRefreshingtime;
	}
}
