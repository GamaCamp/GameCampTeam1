#pragma once
#include "boxclass.h"
#include "CircleClass.h"
#include "MapManagerClass.h"

class SowBugStatePatternClass :
	public CircleClass
{
protected:
	bool m_ThrowedFlag;
	double m_Speed;

	virtual bool LoadSowBugData(POSITION* position , VELOCITY* velocity) = 0;

public:
	SowBugStatePatternClass();
	virtual ~SowBugStatePatternClass();

	virtual void CheckHitMap(MapManagerClass *map_manager) = 0;

	virtual bool Initialize(POSITION* position , VELOCITY* velocity) = 0;
	virtual bool Update() = 0;
	virtual void Render() = 0;
};

class NormalSowBugClass :
	public SowBugStatePatternClass
{
private:
	bool LoadSowBugData(POSITION* position , VELOCITY* velocity);

public:
	NormalSowBugClass();
	~NormalSowBugClass();

	void CheckHitMap(MapManagerClass *map_manager);

	bool Initialize(POSITION* position , VELOCITY* velocity);
	bool Update();
	void Render();
};

class SowBugContextClass
{
private:
	SowBugStatePatternClass* m_SowBug;

public:
	SowBugContextClass(void);
	~SowBugContextClass(void);

	POSITION GetPosition();
	double GetRadius();

	bool Initialize(int sow_bug_type , POSITION* position , VELOCITY* velocity);
	bool Update(MapManagerClass* map_manager);
};