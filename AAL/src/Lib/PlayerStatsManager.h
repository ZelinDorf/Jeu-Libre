#pragma once
class PlayerStatsManager
{
private:
	float m_BaseSpeed;
	float m_SpeedMultiplier;
	float m_FinalSpeed;

	float m_BaseJumpForce;
	float m_JumpForceMultiplier;
	float m_FinalJumpForce;

	float m_Weapon1BaseAttackDamage;
	float m_Weapon1AdditionalAttackDamage;
	float m_Weapon1AttackDamageMultiplier;
	float m_Weapon1FinalAttackDamage;

	float m_Weapon1BaseAttackRefreshingTime;
	float m_Weapon1AttackRefreshingTimeMultiplier;
	float m_Weapon1FinalAttackRefreshingtime;

	float m_Weapon2BaseAttackDamage;
	float m_Weapon2AdditionalAttackDamage;
	float m_Weapon2AttackDamageMultiplier;
	float m_Weapon2FinalAttackDamage;

	float m_Weapon2BaseAttackRefreshingTime;
	float m_Weapon2AttackRefreshingTimeMultiplier;
	float m_Weapon2FinalAttackRefreshingtime;

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

