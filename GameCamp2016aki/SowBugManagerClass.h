#pragma once
#include "singletonclass.h"
class SowBugManagerClass :
	public SingletonClass<SowBugManagerClass>
{
public:
	friend class SingletonClass<SowBugManagerClass>;

public:
	SowBugManagerClass(void);
	~SowBugManagerClass(void);
};

