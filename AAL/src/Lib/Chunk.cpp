#include "pch.h"
#include "Chunk.h"

Chunk::~Chunk()
{
	//CPU_DELPTR(m_pEntity);
}

void Chunk::Init()
{
	m_biome = PLAIN;
	m_entityType = WORLD_OBJECT;

	JsonObj::JsonLoader(JSON_PATH"rockyGround.json", nullptr, m_pEntity);

	//m_pEntity->transform.SetPitch(XMConvertToRadians(90.f));

	//m_pEntity->transform.SetScaling(m_scale);
	m_pEntity->transform.Scale(m_scale);

	/*std::cout << m_pEntity->transform.sca.x << "||" << m_pEntity->transform.sca.z << "||" << m_biome << std::endl;
	std::cout << m_pEntity->transform.pos.x << "||" << m_pEntity->transform.pos.z << "||" << m_biome << std::endl;*/
}

void Chunk::Init(Biomes _biome)
{
	Init();

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