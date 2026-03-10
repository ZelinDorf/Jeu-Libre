#pragma once

class Player;
class Enemy;

class App
{
	//entities
	Player* mp_player;
	Enemy* mp_Enemy;

public:
	App();
	virtual ~App();

	static App& GetInstance() { return *s_pApp; }

	//PROTO
	////////

	void SpawnMissile();

	//ENGINE
	/////////
	void OnStart();
	void OnUpdate();
	void OnExit();
	void OnRender(int pass);

	static void MyPixelShader(cpu_ps_io& io);

private:
	inline static App* s_pApp = nullptr;

	cpu_mesh m_meshMissile;

	cpu_material m_materialMissile;

	std::list<cpu_entity*> m_missiles;

	float m_speed = 10.0f;

};

class Player
{
public:
	Player();
	~Player() {}

	void Shoot();

	cpu_entity* GetEntity() { return mp_entity; }

	void OnUpdate(float _dt);

private:

	cpu_entity* mp_entity;
	cpu_mesh m_mesh;
	cpu_material m_material;
};

class Enemy
{
public:
	Enemy();
	~Enemy() {}

	void Hit();

	void OnUpdate(cpu_entity* player);

	void Despawn();

private:

	cpu_entity* mp_entity;
	cpu_mesh m_mesh;
	cpu_material m_material;

};