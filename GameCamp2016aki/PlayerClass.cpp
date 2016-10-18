#include "PlayerClass.h"

//コンストラクタ
PlayerClass::PlayerClass(void)
{
}

//デストラクタ
PlayerClass::~PlayerClass(void)
{
}

//////////////////////////////////////////////////////////////////////////////
//public関数
//////////////////////////////////////////////////////////////////////////////

bool PlayerClass::Update()
{
	SetVertex();
	return true;
}

void PlayerClass::Render()
{
	DrawBox(m_Vertex.m_VertexPosition[0].m_Vector.x , m_Vertex.m_VertexPosition[0].m_Vector.y , m_Vertex.m_VertexPosition[2].m_Vector.x ,
		m_Vertex.m_VertexPosition[2].m_Vector.y , 0xffffff , false);
}