#include "SceneManagerClass.h"

//////////////////////////////////////////////////////////////////////////////
//静的変数
//////////////////////////////////////////////////////////////////////////////

BaseSceneClass *SceneManagerClass::m_Scene;

SceneManagerClass::SceneManagerClass(void)
{
}


SceneManagerClass::~SceneManagerClass(void)
{
}

//////////////////////////////////////////////////////////////////////////////
//public関数
//////////////////////////////////////////////////////////////////////////////

void SceneManagerClass::ChangeScene(_SCENE scene)
{
	static SceneTitleClass SceneTitle;
	static SceneMainClass SceneMain;

	switch (scene)
	{
	case SceneManagerClass::E_GAME_TITLE:
		m_Scene = &SceneTitle;
		break;

	case SceneManagerClass::E_GAME_MAIN:
		m_Scene = &SceneMain;
		break;
	}
	
	m_Scene->Initialize();

}

void SceneManagerClass::Render()
{
	m_Scene->Render();
}

bool SceneManagerClass::Update()
{
	m_Scene->Update();
	return true;
}