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

	m_OldMouse = m_NowMouse;	//������Ă���}�E�X���L��
	m_NowMouse = GetMouseInput();	//�}�E�X�̃C���v�b�g���擾
	m_MouseFlag = m_NowMouse & ~m_OldMouse;	//2�x�����`�F�b�N

	if(m_NowMouse & MOUSE_INPUT_LEFT) ret |= E_LEFT_BUTTON;
	if(m_NowMouse & MOUSE_INPUT_RIGHT) ret |= E_RIGHT_BUTTON;
	if(m_NowMouse & MOUSE_INPUT_MIDDLE) ret |= E_MIDDLE_BUTTON;
	if(m_MouseFlag & MOUSE_INPUT_LEFT) ret |= E_LEFT_BUTTON_DOWN;
	if(m_MouseFlag & MOUSE_INPUT_RIGHT) ret |= E_RIGHT_BUTTON_DOWN;
	if(m_MouseFlag & MOUSE_INPUT_MIDDLE) ret |= E_MIDDLE_BUTTON_DOWN;
	if(m_OldMouse & MOUSE_INPUT_LEFT && !(m_NowMouse & MOUSE_INPUT_LEFT)) ret |= E_LEFT_BUTTON_UP;
	if(m_OldMouse & MOUSE_INPUT_RIGHT && !(m_NowMouse & MOUSE_INPUT_RIGHT)) ret |= E_RIGHT_BUTTON_UP;
	if(m_OldMouse & MOUSE_INPUT_MIDDLE && !(m_NowMouse & MOUSE_INPUT_MIDDLE)) ret |= E_MIDDLE_BUTTON_UP;

	return ret;
}