#pragma once

enum ConnectPoint
{
	NORTH,
	SOUTH,
	EAST,
	WEST
	//diagonal for hexa chunk?
};

struct ConnectPositions
{
	static XMFLOAT3 _northPos { +5.0f, 0.0f, 0.0f };
	static XMFLOAT3 _southPos { -5.0f, 0.0f, 0.0f };
	static XMFLOAT3 _eastPos { 0.0f, 0.0f, +5.0f };
	static XMFLOAT3 _westPos { 0.0f, 0.0f, -5.0f };
};

class Chunk
{
public:

	virtual void Init();
	virtual void Delete();

	//Select from which point you connect the chunk and which point is connected to it
	void ConnectFromTo(ConnectPoint _oldPoint, ConnectPoint _newPoint, Chunk* _pChunk);

private:

	//connection from the old chunk's point
	void ConnectFromNorth(ConnectPoint _newPoint, Chunk* _pChunk);
	//connection from the old chunk's point
	void ConnectFromSouth(ConnectPoint _newPoint, Chunk* _pChunk);
	//connection from the old chunk's point
	void ConnectFromEast(ConnectPoint _newPoint, Chunk* _pChunk);
	//connection from the old chunk's point
	void ConnectFromWest(ConnectPoint _newPoint, Chunk* _pChunk);

public:

	bool IsConnected(ConnectPoint _point);

	XMFLOAT3 GetNorth();
	XMFLOAT3 GetSouth();
	XMFLOAT3 GetEast();
	XMFLOAT3 GetWest();

	XMFLOAT3 GetPos() { return m_pEntity->transform.pos; }

	void Update(float _dt);


private:
	Vector<XMFLOAT3> m_vExitPoints;

	bool m_isNorthConnected = false;
	bool m_isSouthConnected = false;
	bool m_isEastConnected = false;
	bool m_isWestConnected = false;

	cpu_entity* m_pEntity;//if more for none flat chunck --> add in child

	cpu_mesh m_mesh;
	cpu_material m_mat;
	//texture?
};

