#pragma once
#include "BoxClass.h"
class PlayerClass :
	public BoxClass
{
public:
	PlayerClass(void);
	~PlayerClass(void);

	bool Update();
	void Render();
};

