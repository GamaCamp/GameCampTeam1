#pragma once
#include "singletonclass.h"
#include "GroundClass.h"
#include <string>

class MapManagerClass :
	public SingletonClass<MapManagerClass>
{
public:
	friend class SingletonClass<MapManagerClass>;
	enum STAGE_NUMBER
	{
		E_STAGE1,

		E_MAX_STAGE
	};

private:
	GroundClass m_Ground;
	std::vector<BoxClass> m_Map;

	bool LoadMapData(std::string file_name);

public:
	MapManagerClass(void);
	~MapManagerClass(void);

	GroundClass GetGround();

	bool Initialize(int stage_num);
	bool Update();
	void Render();
};

