#pragma once
#include "singletonclass.h"
#include "PlayerClass.h"
#include "SowBugManagerClass.h"
#include "InputClass.h"

class PlayerManagerClass :
	public SingletonClass<PlayerManagerClass> , public InputClass
{
public:
	friend class SingletonClass<PlayerManagerClass>;

private:
	bool m_ThrowFlag;
	int m_HaveSowBug;
	PlayerClass m_Player;
	bool m_ChangeFlag;
	POSITION m_SowBugPosition[3];
	POSITION m_ClickPosition;
	POSITION m_DragPosition;
	int m_MouseState;

	void RotateSowBug();
	void WantThrow();

public:
	PlayerManagerClass(void);
	~PlayerManagerClass(void);

	bool Initialize();
	bool Update(MapManagerClass *map_manager , SowBugManagerClass *sow_bug_manager);
	void Render();
};

