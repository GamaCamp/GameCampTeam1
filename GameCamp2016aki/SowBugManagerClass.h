#pragma once
#include "singletonclass.h"
#include "ListClass.h"
#include "SowBugClass.h"
#include "GraphicClass.h"

class SowBugManagerClass :
	public SingletonClass<SowBugManagerClass>
{
public:
	friend class SingletonClass<SowBugManagerClass>;

	enum SOW_BUG_TYPE
	{
		E_NORMAL,

		E_MAX_SOW_BUG_TYPE
	};

private:
	ListClass<SowBugContextClass> m_SowBugList;
	SowBugContextClass m_DummyBug;
	GraphicClass m_SowBugImage[E_MAX_SOW_BUG_TYPE];

public:
	SowBugManagerClass(void);
	~SowBugManagerClass(void);

	bool CreateSowBug(SowBugManagerClass::SOW_BUG_TYPE sow_bug_type , POSITION* position , THREE_DIMENSION_VECTOR* velocity);
	void EstimateOrbit(MapManagerClass *map_manager , SowBugManagerClass::SOW_BUG_TYPE sow_bug_type , POSITION* position , THREE_DIMENSION_VECTOR* velocity);

	bool Initialize();
	bool Update(MapManagerClass* map_manager);
	void Render();
};

