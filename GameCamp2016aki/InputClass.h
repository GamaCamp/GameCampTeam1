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
		E_MIDDLE_BUTTON = 1 << 1,
		E_RIGHT_BUTTON = 1 << 2,
	};


	InputClass(void);
	~InputClass(void);

	int InputMouse();
	int InputMouseDown();
	int InputMouseUp();
};

