#include "SceneClass.h"
#include "Help.h"
#include "GroundClass.h"
#include "SceneManagerClass.h"


int HelpMove(int& Mousex,int& Mousey){
	int Mouse=0;

	//���݂̃}�E�X���͎擾
	Mouse = GetMouseInput();

	//���N���b�N���ꂽ�Ƃ�
	if(Mouse&MOUSE_INPUT_LEFT)
	{
		SceneManagerClass::ChangeScene(SceneManagerClass::E_GAME_TITLE);
	}
	return true;
}