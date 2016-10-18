#pragma once
class InputClass
{
	int m_OldMouse;
	int m_NowMouse;
	int m_MouseFlag;

public:
	//インプットモード
	enum MOUSE_INPUT_MODE
	{
		E_LEFT_BUTTON = 1,
		E_LEFT_BUTTON_DOWN = 1 << 1,
		E_LEFT_BUTTON_UP = 1 << 2,
		E_MIDDLE_BUTTON = 1 << 3,
		E_MIDDLE_BUTTON_DOWN = 1 << 4,
		E_MIDDLE_BUTTON_UP = 1 << 5,
		E_RIGHT_BUTTON = 1 << 6,
		E_RIGHT_BUTTON_DOWN = 1 << 7,
		E_RIGHT_BUTTON_UP = 1 << 8
	};


	InputClass(void);
	~InputClass(void);

	int InputMouse();
};

