#include"DxLib.h"
#include"MyScene.h"
#include"General.h"

int cross = 0;

void suken::Awake(){
	/*game.addChild(&Title);

	for(int i=0;i<4;i++){
		a[i]=10+i*30;
	}
	
	Title.SetButton(400,500,500,550,YELLOW,"ì“à",BLACK,null);
	Title.SetButton(&a[0],&a[1],&a[2],&a[3],YELLOW,"ì“à",BLACK,null);*/

	cross = LoadGraph("Kawachi2/Close.PNG", true);

	Start();

	Title.input.AddEventListener(Event.EVERY_FRAME,DrawTitle);

	Title.input.AddEventListener(Event.EVERY_FRAME,GoStage);

	Stage.input.AddEventListener(Event.EVERY_FRAME,DrawStage);
	
	Stage.input.AddEventListener(Event.EVERY_FRAME,MoveUnit);

	Stage.input.AddEventListener(Event.EVERY_FRAME,FightUnit);

	Stage.SetButton(870, 0, 900, 30, cross, GoTitle);
}

void suken::GameLoopEnter(){
	/*if(Event.key.GetDown(Event.key.RETURN)){
		GoStage();
	}*/
}

void suken::GameLoopExit(){
}
