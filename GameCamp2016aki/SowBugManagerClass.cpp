#include "SowBugManagerClass.h"

//コンストラクタ
SowBugManagerClass::SowBugManagerClass(void)
{
}

//デストラクタ
SowBugManagerClass::~SowBugManagerClass(void)
{
}

//////////////////////////////////////////////////////////////////////////////
//public関数
//////////////////////////////////////////////////////////////////////////////

bool SowBugManagerClass::CreateSowBug(SowBugManagerClass::SOW_BUG_TYPE sow_bug_type , POSITION* position , VELOCITY* velocity)
{
	switch (sow_bug_type)
	{
	case SowBugManagerClass::E_NORMAL:
		SowBugContextClass NewSowBug;
		if(!NewSowBug.Initialize(sow_bug_type , position , velocity)) return false;
		m_SowBugList.PushBack(NewSowBug);
		break;
	}

	return true;
}

bool SowBugManagerClass::Initialize()
{
	return true;
}

bool SowBugManagerClass::Update(MapManagerClass* map_manager)
{
#ifdef DEBUG
	if(m_SowBugList.ToBegin())
	{
		do
		{
			m_SowBugList.GetCurrentNode().Update(map_manager);
		} while (m_SowBugList.Next());
	}
#endif // DEBUG

	return true;
}

void SowBugManagerClass::Render()
{
#ifdef DEBUG
	if(m_SowBugList.ToBegin())
	{
		do
		{
			DrawCircle(m_SowBugList.GetCurrentNode().GetPosition().m_Vector.x , m_SowBugList.GetCurrentNode().GetPosition().m_Vector.y , m_SowBugList.GetCurrentNode().GetRadius() , 0xffffff , false);

		} while (m_SowBugList.Next());
	}
#endif // DEBUG

}