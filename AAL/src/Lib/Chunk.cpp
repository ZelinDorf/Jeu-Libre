#include "pch.h"
#include "Chunk.h"

void Chunk::Init()
{
	m_mesh.CreatePlane();
	m_mat.color = TO_COLOR(70, 190, 25);

	m_biome = PLAIN;

	m_pEntity = cpuEngine.CreateEntity();
	m_pEntity->pMaterial = &m_mat;
	m_pEntity->pMesh = &m_mesh;
	m_pEntity->transform.pos = { 0.0f, 0.0f, 0.0f };

	m_pEntity->transform.dir = CPU_VEC3_DIR;
	m_pEntity->transform.up = CPU_VEC3_UP;
	m_pEntity->transform.right = CPU_VEC3_RIGHT;

	float pitch = XMConvertToRadians(90.f);
	m_pEntity->transform.SetPitch(pitch);

	m_pEntity->transform.Scale(m_scale);
}

void Chunk::Init(Biomes _biome)
{
	Init();

	switch (_biome)
	{
	case PLAIN:
		m_mat.color = TO_COLOR(81, 104, 52);
		break;
	case SAVANNA:
		m_mat.color = TO_COLOR(109, 104, 49);
		break;
	case TAIGA:
		m_mat.color = TO_COLOR(70, 47, 25);
		break;
	case DESERT:
		m_mat.color = TO_COLOR(213, 199, 154);
		break;
	case SNOWY_PLAIN:
		m_mat.color = TO_COLOR(227, 232, 233);
		break;
	default:
		break;
	}

}

void Chunk::Delete()
{
	//CPU_RELEASE(m_pEntity);
}

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

void Chunk::SetBiome(Biomes _biome)
{
	switch (_biome)
	{
	case PLAIN:
		m_mat.color = TO_COLOR(81, 104, 52);
		break;
	case SAVANNA:
		m_mat.color = TO_COLOR(109, 104, 49);
		break;
	case TAIGA:
		m_mat.color = TO_COLOR(70, 47, 25);
		break;
	case DESERT:
		m_mat.color = TO_COLOR(213, 199, 154);
		break;
	case SNOWY_PLAIN:
		m_mat.color = TO_COLOR(227, 232, 233);
		break;
	default:
		break;
	}
}

void Chunk::SetPos(XMFLOAT3 _pos)
{
	m_pEntity->transform.pos = _pos;
}

void Chunk::OnUpdate(float _dt)
{

}