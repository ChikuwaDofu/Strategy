#include"DxLib.h"
#include"MyScene.h"
#include"General.h"


int a[4];
void suken::Awake(){
	/*game.addChild(&Title);

	for(int i=0;i<4;i++){
		a[i]=10+i*30;
	}

	Title.input.AddEventListener(Event.EVERY_FRAME,DrawTitle);
	Title.SetButton(400,500,500,550,YELLOW,"ì“à",BLACK,null);
	Title.SetButton(&a[0],&a[1],&a[2],&a[3],YELLOW,"ì“à",BLACK,null);*/

	StageEnter();

	Stage.input.AddEventListener(Event.EVERY_FRAME,DrawStage);
	
	Stage.input.AddEventListener(Event.EVERY_FRAME,MoveUnit);

	Stage.input.AddEventListener(Event.EVERY_FRAME,FightUnit);
}

void suken::GameLoopEnter(){
}

void suken::GameLoopExit(){
}
