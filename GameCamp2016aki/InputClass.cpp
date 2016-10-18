#include "InputClass.h"
#include "common.h"

InputClass::InputClass(void)
{
	m_OldMouse = 0;
	m_NowMouse = 0;
	m_MouseFlag = 0;
}


InputClass::~InputClass(void)
{
}

int InputClass::InputMouse()
{
	int ret = 0;

	m_NowMouse = GetMouseInput();
	if(m_NowMouse & MOUSE_INPUT_LEFT) ret |= E_LEFT_BUTTON;
	if(m_NowMouse & MOUSE_INPUT_RIGHT) ret |= E_RIGHT_BUTTON;
	if(m_NowMouse & MOUSE_INPUT_MIDDLE) ret |= E_MIDDLE_BUTTON;

	return ret;
}

int InputClass::InputMouseDown()
{
	int ret = 0;
	m_OldMouse = m_NowMouse;	//前の入力を記憶
	m_NowMouse = GetMouseInput();
	m_MouseFlag = m_NowMouse & ~m_OldMouse;	//2度押しチェック

	if(m_MouseFlag & MOUSE_INPUT_LEFT) ret |= E_LEFT_BUTTON;
	if(m_MouseFlag & MOUSE_INPUT_RIGHT) ret |= E_RIGHT_BUTTON;
	if(m_MouseFlag & MOUSE_INPUT_MIDDLE) ret |= E_MIDDLE_BUTTON;

	return ret;
}

int InputClass::InputMouseUp()
{
	int ret = 0;

	return ret;
}