#include "PlayerManagerClass.h"
#define _USE_MATH_DEFINES
#include <math.h>

#include "system.h"

PlayerManagerClass::PlayerManagerClass(void)
{
	m_ThrowFlag = false;
	m_HaveSowBug = SowBugManagerClass::E_NORMAL;
	m_ChangeFlag = true;
	m_MouseState = 0;
}


PlayerManagerClass::~PlayerManagerClass(void)
{
}

//////////////////////////////////////////////////////////////////////////////
//privateä÷êî
//////////////////////////////////////////////////////////////////////////////

void PlayerManagerClass::RotateSowBug()
{
	if(m_ChangeFlag)
	{
		if(GetMouseWheelRotVol() > 0)
		{
			m_HaveSowBug++;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////
//publicä÷êî
//////////////////////////////////////////////////////////////////////////////

bool PlayerManagerClass::Initialize()
{
	m_ThrowFlag = false;
	m_HaveSowBug = SowBugManagerClass::E_NORMAL;
	m_ChangeFlag = true;
	m_MouseState = 0;

	m_Player.Initialize(&POSITION(112 , WINDOW_HEIGHT - 112) , &VELOCITY() , &ACCELARATION() , &THREE_DIMENSION_VECTOR(48) , &THREE_DIMENSION_VECTOR(0 , 48));
	for(int i = 0 ; i < 3 ; i++)
	{
		m_SowBugPosition[i].m_Vector.x = m_Player.GetPosition().m_Vector.x + 64 * cos(M_PI * 2 / 3 * i + M_PI_2);
		m_SowBugPosition[i].m_Vector.y = m_Player.GetPosition().m_Vector.y - 64 + 64 * sin(M_PI * 2 / 3 * i + M_PI_2);
	}
	return true;
}

bool PlayerManagerClass::Update(MapManagerClass *map_manager , SowBugManagerClass *sow_bug_manager)
{
	m_Player.Update();
	m_MouseState = InputMouse();
	if(m_MouseState & InputClass::E_LEFT_BUTTON_DOWN)
	{
		int m_ClickPositionX;
		int m_ClickPositionY;
		
		m_ThrowFlag = true;
		
		GetMousePoint(&m_ClickPositionX , &m_ClickPositionY);

		m_ClickPosition.m_Vector.x = m_ClickPositionX;
		m_ClickPosition.m_Vector.y = m_ClickPositionY;
	}
	else if(m_MouseState & InputClass::E_LEFT_BUTTON_UP)
	{
		if(GetDistance(&m_ClickPosition , &m_DragPosition) > 10)
		{
			sow_bug_manager->CreateSowBug((SowBugManagerClass::SOW_BUG_TYPE)m_HaveSowBug , &m_Player.GetPosition() , &((m_ClickPosition.m_Vector - m_DragPosition.m_Vector) * 0.1));
		}
		m_ThrowFlag = false;
	}

	if(m_MouseState & InputClass::E_LEFT_BUTTON)
	{
		int m_DragPositionX;
		int m_DragPositionY;

		GetMousePoint(&m_DragPositionX , &m_DragPositionY);

		m_DragPosition.m_Vector.x = m_DragPositionX;
		m_DragPosition.m_Vector.y = m_DragPositionY;

		sow_bug_manager->EstimateOrbit(map_manager , (SowBugManagerClass::SOW_BUG_TYPE)m_HaveSowBug , &m_Player.GetPosition() , &((m_ClickPosition.m_Vector - m_DragPosition.m_Vector) * 0.1));
	}

	return true;
}

void PlayerManagerClass::Render()
{
	m_Player.Render();

	if(m_ThrowFlag)
	{
		DrawCircle(m_SowBugPosition[m_HaveSowBug].m_Vector.x , m_SowBugPosition[m_HaveSowBug].m_Vector.y , 32 , 0xffffff , false);
	}
	else
	{
		for(int i = 0 ; i < 3 ; i++)
		{
			DrawCircle(m_SowBugPosition[i].m_Vector.x , m_SowBugPosition[i].m_Vector.y , 32 , 0xffffff , false);
		}
	}
}