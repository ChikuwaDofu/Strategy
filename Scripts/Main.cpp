#include"DxLib.h"
#include"MyScene.h"
#include"General.h"
#include"Music.h"

int howButton = 0;
int cross = 0;
int newGame,contGame;

void suken::Awake(){
	/*game.addChild(&Title);

	for(int i=0;i<4;i++){
		a[i]=10+i*30;
	}
	
	Title.SetButton(400,500,500,550,YELLOW,"ì“à",BLACK,null);
	Title.SetButton(&a[0],&a[1],&a[2],&a[3],YELLOW,"ì“à",BLACK,null);*/

	howButton = LoadGraph("Kawachi2/HowToButton.png", true);

	cross = LoadGraph("Kawachi2/Close.png", true);

	newGame = LoadGraph("Kawachi2/NewGame.png", true);
	
	contGame = LoadGraph("Kawachi2/Continue.png", true);

	Start();

	Title.input.AddEventListener(Event.EVERY_FRAME,DrawTitle);

	//Title.input.AddEventListener(Event.EVERY_FRAME,GoStage);

	Title.SetButton(350, 0, 550, 50, howButton,GoHowTo);

	Title.SetButton(150, 550, 350, 590, newGame, GoStage);

	Title.SetButton(550, 550, 750, 590, contGame, ContinueStage);

	HowTo.input.AddEventListener(Event.EVERY_FRAME, DrawHowTo);

	HowTo.SetButton(870, 0, 900, 30, cross, BackToTitle);

	Stage.input.AddEventListener(Event.EVERY_FRAME, SkipTurn);

	Stage.input.AddEventListener(Event.EVERY_FRAME,DrawStage);
	
	Stage.input.AddEventListener(Event.EVERY_FRAME,MoveUnit);

	Stage.input.AddEventListener(Event.EVERY_FRAME,FightUnit);

	Stage.input.AddEventListener(Event.EVERY_FRAME, GameOver);

	Stage.input.AddEventListener(Event.EVERY_FRAME, GoTitle);

	Stage.input.AddEventListener(Event.EVERY_FRAME, SaveStage);

	//Stage.SetButton(870, 0, 900, 30, cross, GoTitle);

	Result.input.AddEventListener(Event.EVERY_FRAME, DrawResult);

	AwakeMusic();
}

void suken::GameLoopEnter(){
	/*if(Event.key.GetDown(Event.key.RETURN)){
		GoStage();
	}*/
}

void suken::GameLoopExit(){
	music->Play();
}
