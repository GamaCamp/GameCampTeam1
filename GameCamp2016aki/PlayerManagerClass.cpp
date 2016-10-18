#include "PlayerManagerClass.h"
#define _USE_MATH_DEFINES
#include <math.h>

PlayerManagerClass::PlayerManagerClass(void)
{
	m_ThrowFlag = false;
	m_HaveSowBug = 0;
	m_ChangeFlag = false;
}


PlayerManagerClass::~PlayerManagerClass(void)
{
}

//////////////////////////////////////////////////////////////////////////////
//privateä÷êî
//////////////////////////////////////////////////////////////////////////////

void PlayerManagerClass::RotateSowBug()
{

}

//////////////////////////////////////////////////////////////////////////////
//publicä÷êî
//////////////////////////////////////////////////////////////////////////////

bool PlayerManagerClass::Initialize()
{
	m_ThrowFlag = false;
	m_HaveSowBug = 0;
	m_ChangeFlag = false;
	m_Player.Initialize(&POSITION(112 , WINDOW_HEIGHT - 112) , &VELOCITY() , &ACCELARATION() , &THREE_DIMENSION_VECTOR(48) , &THREE_DIMENSION_VECTOR(0 , 48));
	for(int i = 0 ; i < 3 ; i++)
	{
		m_SowBugPosition[i].m_Vector.x = m_Player.GetPosition().m_Vector.x + 64 * cos(M_PI * 2 / 3 * i + M_PI_2);
		m_SowBugPosition[i].m_Vector.y = m_Player.GetPosition().m_Vector.y - 64 + 64 * sin(M_PI * 2 / 3 * i + M_PI_2);
	}
	return true;
}

bool PlayerManagerClass::Update()
{
	m_Player.Update();
	return true;
}

void PlayerManagerClass::Render()
{
	m_Player.Render();

	if(m_ThrowFlag)
	{
		for(int i = 0 ; i < 3 ; i++)
		{
			DrawCircle(m_SowBugPosition[i].m_Vector.x , m_SowBugPosition[i].m_Vector.y , 32 , 0xffffff , false);
		}
	}
}