#include "pch.h"
#include "Chunk.h"

void Chunk::Init()
{
	m_mesh.CreatePlane();
	m_mat.color = TO_COLOR(70, 150, 25);

	m_pEntity = cpuEngine.CreateEntity();
	m_pEntity->pMaterial = &m_mat;
	m_pEntity->pMesh = &m_mesh;

	float pitch = XMConvertToRadians(90.f);
	m_pEntity->transform.SetPitch(pitch);

	m_pEntity->transform.Scale(10.f);
}

void Chunk::Delete()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

void Chunk::ConnectFromTo(ConnectPoint _oldPoint, ConnectPoint _newPoint, Chunk* _pChunk)
{
	//TODO
	if (_pChunk == nullptr)
		return;
	if (_pChunk->IsConnected(_oldPoint))
		return;

	if (_newPoint == NORTH)
	{
		m_isNorthConnected = true;
		ConnectFromNorth(_newPoint, _pChunk);
	}
	if (_newPoint == SOUTH)
	{
		m_isSouthConnected = true;
		ConnectFromSouth(_newPoint, _pChunk);
	}
	if (_newPoint == EAST)
	{
		m_isEastConnected = true;
		ConnectFromEast(_newPoint, _pChunk);
	}
	if (_newPoint == WEST)
	{
		m_isWestConnected = true;
		ConnectFromWest(_newPoint, _pChunk);
	}
}

void Chunk::ConnectFromNorth(ConnectPoint _newPoint, Chunk* _pChunk)
{
	XMFLOAT3 newPos = _pChunk->GetNorth();

	if (_newPoint == NORTH)
	{
		//forward
	}
	if (_newPoint == SOUTH)
	{
		//-forward
	}
	if (_newPoint == EAST)
	{
		//right
	}
	if (_newPoint == WEST)
	{
		//-right
	}



	m_pEntity->transform.SetPosition(newPos);
}

void Chunk::ConnectFromSouth(ConnectPoint _newPoint, Chunk* _pChunk)
{
	XMFLOAT3 newPos = _pChunk->GetSouth();

	if (_newPoint == NORTH)
	{

	}
	if (_newPoint == SOUTH)
	{

	}
	if (_newPoint == EAST)
	{

	}
	if (_newPoint == WEST)
	{

	}

	m_pEntity->transform.SetPosition(newPos);
}

void Chunk::ConnectFromEast(ConnectPoint _newPoint, Chunk* _pChunk)
{
	XMFLOAT3 newPos = _pChunk->GetEast();

	if (_newPoint == NORTH)
	{

	}
	if (_newPoint == SOUTH)
	{

	}
	if (_newPoint == EAST)
	{

	}
	if (_newPoint == WEST)
	{

	}

	m_pEntity->transform.SetPosition(newPos);
}

void Chunk::ConnectFromWest(ConnectPoint _newPoint, Chunk* _pChunk)
{
	XMFLOAT3 newPos = _pChunk->GetWest();

	if (_newPoint == NORTH)
	{

	}
	if (_newPoint == SOUTH)
	{

	}
	if (_newPoint == EAST)
	{

	}
	if (_newPoint == WEST)
	{

	}

	m_pEntity->transform.SetPosition(newPos);
}

bool Chunk::IsConnected(ConnectPoint _point)
{
	switch (_point)
	{
	case NORTH:
		if (m_isNorthConnected)
			return true;
		break;
	case SOUTH:
		if (m_isSouthConnected)
			return true;
		break;
	case EAST:
		if (m_isEastConnected)
			return true;
		break;
	case WEST:
		if (m_isWestConnected)
			return true;
		break;
	}

	return false;
}

XMFLOAT3 Chunk::GetNorth()
{
	XMFLOAT3 north = m_pEntity->transform.pos;
	north.x += ConnectPositions::_northPos.x;	

	return north;
}

XMFLOAT3 Chunk::GetSouth()
{
	XMFLOAT3 south = m_pEntity->transform.pos;
	south.x += ConnectPositions::_southPos.x;

	return south;
}

XMFLOAT3 Chunk::GetEast()
{
	XMFLOAT3 east = m_pEntity->transform.pos;
	east.z += ConnectPositions::_eastPos.z;

	return east;
}

XMFLOAT3 Chunk::GetWest()
{
	XMFLOAT3 west = m_pEntity->transform.pos;
	west.z += ConnectPositions::_westPos.z;

	return west;
}

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

void Chunk::Update(float _dt)
{

}