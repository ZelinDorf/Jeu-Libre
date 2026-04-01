#pragma once
class PlayerStatsManager
{
private:
	float mBaseSpeed;
	float mSpeedMultiplier;
	float mFinalSpeed;

	float mBaseJumpForce;
	float mJumpForceMultiplier;
	float mFinalJumpForce;

	float mWeapon1BaseAttackDamage;
	float mWeapon1AdditionalAttackDamage;
	float mWeapon1AttackDamageMultiplier;
	float mWeapon1FinalAttackDamage;

	float mWeapon1BaseAttackRefreshingTime;
	float mWeapon1AttackRefreshingTimeMultiplier;
	float mWeapon1FinalAttackRefreshingtime;

	float mWeapon2BaseAttackDamage;
	float mWeapon2AdditionalAttackDamage;
	float mWeapon2AttackDamageMultiplier;
	float mWeapon2FinalAttackDamage;

	float mWeapon2BaseAttackRefreshingTime;
	float mWeapon2AttackRefreshingTimeMultiplier;
	float mWeapon2FinalAttackRefreshingtime;

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

