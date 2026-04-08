#include "pch.h"
#include "Chunk.h"

Chunk::~Chunk()
{
	CPU_DELPTR(m_pEntity);
}

void Chunk::Init(Biomes _biome)
{
	m_biome = _biome;

	switch (_biome)
	{
	case DIRT:
		JsonObj::JsonLoader(JSON_PATH"dirtyGround.json", nullptr, m_pEntity);
		break;
	case ROCKY:
		JsonObj::JsonLoader(JSON_PATH"rockyGround.json", nullptr, m_pEntity);
		break;
	case PLAIN:
		JsonObj::JsonLoader(JSON_PATH"plainGround.json", nullptr, m_pEntity);
		break;
	default:
		break;
	}

	int r = RandomInt(4);

	float d = (90.f * r) * 0.0174533f;//rad convert

	m_pEntity->transform.SetYaw(d);

	m_pEntity->transform.SetScaling(m_scale);

}

void Chunk::Delete()
{
	
}

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

void Chunk::SetBiome(Biomes _biome)
{
	/*switch (_biome)
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
	}*/
}

void Chunk::SetPos(XMFLOAT3 _pos)
{
	m_pEntity->transform.pos = _pos;

	//std::cout << m_pEntity->transform.pos.x << "||" << m_pEntity->transform.pos.z << "||" << m_biome << std::endl;
}

void Chunk::Update(float _dt)
{

}