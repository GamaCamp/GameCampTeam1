#include "SceneClass.h"
#include "Help.h"
#include "GroundClass.h"
#include "SceneManagerClass.h"


int HelpMove(int& Mousex,int& Mousey){
	int Mouse=0;

	//現在のマウス入力取得
	Mouse = GetMouseInput();

	//左クリックされたとき
	if(Mouse&MOUSE_INPUT_LEFT)
	{
		SceneManagerClass::ChangeScene(SceneManagerClass::E_GAME_TITLE);
	}
	return true;
}