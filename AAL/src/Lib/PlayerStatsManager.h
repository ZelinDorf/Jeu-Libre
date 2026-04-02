#pragma once
class PlayerStatsManager
{
private:
	float m_baseSpeed;
	float m_speedMultiplier;
	float m_finalSpeed;

	float m_baseJumpForce;
	float m_jumpForceMultiplier;
	float m_finalJumpForce;

	float m_weapon1BaseAttackDamage;
	float m_weapon1AdditionalAttackDamage;
	float m_weapon1AttackDamageMultiplier;
	float m_weapon1FinalAttackDamage;

	float m_weapon1BaseAttackRefreshingTime;
	float m_weapon1AttackRefreshingTimeMultiplier;
	float m_weapon1FinalAttackRefreshingtime;

	float m_weapon2BaseAttackDamage;
	float m_weapon2AdditionalAttackDamage;
	float m_weapon2AttackDamageMultiplier;
	float m_weapon2FinalAttackDamage;

	float m_weapon2BaseAttackRefreshingTime;
	float m_weapon2AttackRefreshingTimeMultiplier;
	float m_weapon2FinalAttackRefreshingtime;

public:

	void SetBaseSpeed(float _speed);
	void SetSpeedMultiplier(float _multiplier);
	
	float GetBaseSpeed();
	float GetSpeedMultiplier();
	float GetFinalSpeed();


	void SetBaseJumpForce(float _jumpForce);
	void SetJumpForceMultiplier(float _multiplier);

	float GetBaseJumpForce();
	float GetJumpForceMultiplier();
	float GetFinalJumpForce();


	void SetBaseAttackDamage(int _weapon, float _dmg);
	void SetAdditionalAttackDamage(int _weapon, float _dmg);
	void SetAttackDamageMultiplier(int _weapon, float _multiplier);

	float GetBaseAttackDamage(int _weapon);
	float GetAdditionalAttackDamage(int _weapon);
	float GetAttackDamageMultiplier(int _weapon);
	float GetFinalAttackDamage(int _weapon);

	void SetBaseAttackRefreshingTime(int _weapon, float _time);
	void SetAttackRefreshingMultiplier(int _weapon, float _multiplier);

	float GetBaseAttackRefreshingTime(int _weapon);
	float GetAttackRefreshingMultiplier(int _weapon);
	float GetFinalAttackRefreshingTime(int _weapon);
};

