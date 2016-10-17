#include "youDebugRoom.h"
#include "GroundClass.h"
#include "SceneManagerClass.h"

SceneManagerClass* TestScene = SingletonClass<SceneManagerClass>::GetInstance();

void DebugInit()
{
	SceneManagerClass::ChangeScene(SceneManagerClass::E_GAME_MAIN);
	GameMode = GAME_PLAY;
}

void DebugView()
{
	SceneManagerClass::Update();
	SceneManagerClass::Render();
}