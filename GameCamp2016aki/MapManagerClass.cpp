#include "MapManagerClass.h"
#include "common.h"

#include <fstream>
#include <sstream>

#include "system.h"

//コンストラクタ
MapManagerClass::MapManagerClass(void)
{
}

//デストラクタ
MapManagerClass::~MapManagerClass(void)
{
}

//////////////////////////////////////////////////////////////////////////////
//private関数
//////////////////////////////////////////////////////////////////////////////

bool MapManagerClass::LoadMapData(std::string file_name)
{
	std::ifstream ifs(file_name);
	if(ifs.fail()) return false;

	std::vector<double> TempVector;

	std::string MapData;
	std::getline(ifs , MapData);
	
	std::getline(ifs , MapData);

	std::string token;
	std::istringstream stream(MapData);

	while (std::getline(stream , token , ','))
	{
		TempVector.push_back(std::stod(token));
	}

	m_Ground.Initialize(&POSITION(TempVector[0] / 2 , WINDOW_HEIGHT - 32) , &VELOCITY() , &ACCELARATION() , &THREE_DIMENSION_VECTOR(TempVector[0]) , 
		&THREE_DIMENSION_VECTOR(0 , 32));

	ReleaseVector(TempVector);

	return true;
}

//////////////////////////////////////////////////////////////////////////////
//public関数
//////////////////////////////////////////////////////////////////////////////

GroundClass MapManagerClass::GetGround()
{
	return m_Ground;
}

bool MapManagerClass::Initialize(int stage_num)
{
	switch(stage_num)
	{
	case E_STAGE1:
		LoadMapData("data/stage/stage1.csv");
		break;

	}
	return true;
}

bool MapManagerClass::Update()
{
	m_Ground.SetVertex();



	return true;
}

void MapManagerClass::Render()
{
	FOUR_VERTEX Vertex = m_Ground.GetVertex();
	DrawBox(Vertex.m_VertexPosition[0].m_Vector.x , Vertex.m_VertexPosition[0].m_Vector.y ,
		Vertex.m_VertexPosition[2].m_Vector.x , Vertex.m_VertexPosition[2].m_Vector.y , 0xffffff , true);
}