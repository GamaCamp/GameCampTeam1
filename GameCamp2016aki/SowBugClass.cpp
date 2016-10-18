#include "SowBugManagerClass.h"
#include <fstream>
#include <sstream>

#include "system.h"

//////////////////////////////////////////////////////////////////////////////
//SowBugStatePatternClass
//////////////////////////////////////////////////////////////////////////////

//�R���X�g���N�^
SowBugStatePatternClass::SowBugStatePatternClass()
{
	m_ThrowedFlag = false;
}

//�f�X�g���N�^
SowBugStatePatternClass::~SowBugStatePatternClass()
{
}

//////////////////////////////////////////////////////////////////////////////
//protected�֐�
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//�T��:
//	�f�[�^���[�h�i�������z�֐��j
//////////////////////////////////////////////////////////////////////////////
bool SowBugStatePatternClass::LoadSowBugData(POSITION* position , VELOCITY* velocity)
{
	return true;
}

//////////////////////////////////////////////////////////////////////////////
//public�֐�
//////////////////////////////////////////////////////////////////////////////

void SowBugStatePatternClass::CheckHitMap(MapManagerClass *map_manager)
{
}

//////////////////////////////////////////////////////////////////////////////
//�T��:
//	�������i�������z�֐��j
//////////////////////////////////////////////////////////////////////////////
bool SowBugStatePatternClass::Initialize(POSITION* position , VELOCITY* velocity)
{
	return true;
}

//////////////////////////////////////////////////////////////////////////////
//�T��:
//	�X�V�i�������z�֐��j
//////////////////////////////////////////////////////////////////////////////
bool SowBugStatePatternClass::Update()
{
	return true;
}

//////////////////////////////////////////////////////////////////////////////
//�T��:
//	�`��i�������z�֐��j
//////////////////////////////////////////////////////////////////////////////
void SowBugStatePatternClass::Render()
{
}

//////////////////////////////////////////////////////////////////////////////
//NormalSowBugClass
//////////////////////////////////////////////////////////////////////////////

//�R���X�g���N�^
NormalSowBugClass::NormalSowBugClass()
{
}

//�f�X�g���N�^
NormalSowBugClass::~NormalSowBugClass()
{
}

//////////////////////////////////////////////////////////////////////////////
//private�֐�
//////////////////////////////////////////////////////////////////////////////

bool NormalSowBugClass::LoadSowBugData(POSITION* position , VELOCITY* velocity)
{
	std::ifstream ifs("data/sow_bug/normal_sow_bug.csv");
	if(ifs.fail()) return false;

	std::string SowBugData;
	for(int i = 0 ; i < 2 ; i++)
	{
		std::getline(ifs , SowBugData);
	}

	std::string token;
	std::istringstream stream(SowBugData);
	std::vector<double> TempVector;

	while (std::getline(stream , token , ','))
	{
		TempVector.push_back(std::stod(token));
	}

	CircleClass::Initialize(position , velocity , &ACCELARATION() , TempVector[0]);

	m_Speed = TempVector[2];

	ReleaseVector(TempVector);

	return true;
}

//////////////////////////////////////////////////////////////////////////////
//public�֐�
//////////////////////////////////////////////////////////////////////////////

void NormalSowBugClass::CheckHitMap(MapManagerClass *map_manager)
{
	CircleClass EstimateCircle;
	EstimateCircle.Initialize(&EstimatePosition(m_GroundedFlag) , &m_Velocity , &m_Accelaration , m_Radius);
	
	if(CheckHitCircleandBox(&EstimateCircle , &map_manager->GetGround()))
	{
		if(m_Position.m_Vector.y + m_Radius <  map_manager->GetGround().GetVertex(0).m_Vector.y)
		{
			m_Position.m_Vector.y = map_manager->GetGround().GetPosition().m_Vector.y - map_manager->GetGround().GetSemiShortAxis() - m_Radius;
		}
	}
}

bool NormalSowBugClass::Initialize(POSITION* position , VELOCITY* velocity)
{
	LoadSowBugData(position , velocity);
	return true;
}

bool NormalSowBugClass::Update()
{
	MoveObject(m_GroundedFlag);
	return true;
}

void NormalSowBugClass::Render()
{
}

//////////////////////////////////////////////////////////////////////////////
//SowBugContextClass
//////////////////////////////////////////////////////////////////////////////

//�R���X�g���N�^
SowBugContextClass::SowBugContextClass(void)
{
}

//�f�X�g���N�^
SowBugContextClass::~SowBugContextClass(void)
{
}

//////////////////////////////////////////////////////////////////////////////
//public�֐�
//////////////////////////////////////////////////////////////////////////////

POSITION SowBugContextClass::GetPosition()
{
	return m_SowBug->GetPosition();
}

double SowBugContextClass::GetRadius()
{
	return m_SowBug->GetRadius();
}

bool SowBugContextClass::Initialize(int sow_bug_type , POSITION* position , VELOCITY* velocity)
{
	switch (sow_bug_type)
	{
	case SowBugManagerClass::E_NORMAL:
		m_SowBug = new NormalSowBugClass;
		break;
	}

	if(!m_SowBug->Initialize(position , velocity)) return false;
	return true;
}

bool SowBugContextClass::Update(MapManagerClass *map_manager)
{
	m_SowBug->Update();
	m_SowBug->CheckHitMap(map_manager);
	return true;
}