#include "pch.h"
#include "Chunk.h"

void Chunk::Init()
{
	m_mesh.CreatePlane();
	m_mat.color = TO_COLOR(70, 150, 25);

	m_pEntity = cpuEngine.CreateEntity();
	m_pEntity->pMaterial = &m_mat;
	m_pEntity->pMesh = &m_mesh;
	m_pEntity->transform.pos = { 0.0f, 0.0f, 0.0f };

	m_pEntity->transform.dir = CPU_VEC3_DIR;
	m_pEntity->transform.up = CPU_VEC3_UP;
	m_pEntity->transform.right = CPU_VEC3_RIGHT;

	float pitch = XMConvertToRadians(90.f);
	m_pEntity->transform.SetPitch(pitch);

	m_pEntity->transform.Scale(16.f);
}

void Chunk::Delete()
{
	//CPU_RELEASE(m_pEntity);
}

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

void Chunk::OnUpdate(float _dt)
{

}