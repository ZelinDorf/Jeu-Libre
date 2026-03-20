#pragma once
#include "pch.h"

//enum ConnectPoint
//{
//	NORTH,
//	SOUTH,
//	EAST,
//	WEST
//	//diagonal for hexa chunk?
//};

//struct ConnectPositions//not sure if usefull....
//{
//	static inline XMFLOAT3 _northPos = { 0.0f, 0.0f, +5.0f };
//	static inline XMFLOAT3 _southPos = { 0.0f, 0.0f, -5.0f };
//	static inline XMFLOAT3 _eastPos = { +5.0f, 0.0f, 0.0f };
//	static inline XMFLOAT3 _westPos = { -5.0f, 0.0f, 0.0f };
//};

class Chunk
{
public:

	virtual void Init();
	virtual void Delete();

	XMFLOAT3 GetPos() { return m_pEntity->transform.pos; }

	void OnUpdate(float _dt);


private:
	float m_scale = 16.0f;

	cpu_entity* m_pEntity;//if more for none flat chunck --> add in child

	cpu_mesh m_mesh;
	cpu_material m_mat;
	//texture?
};
