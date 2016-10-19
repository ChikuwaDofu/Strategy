#include"Manager.h"
#include"Title.h"
#include"Back.h"
#include"Cursor.h"
#include"UnitManager.h"
#include"Battle.h"
#include"Stage.h"
#include"Product.h"
#include"Result.h"
#include"Files.h"
#include"General.h"
#include"MyScene.h"

CScene Title,HowTo,Stage,Result;

CTitle title;

CBack back;
CProduct product;
CCommon common;
CTurn turn;
CResult result;
CFiles file;

int stageNow;

bool enterHowTo;

//CStage *stage;
//CStage s;

void Start(){
	Game.AddChild(&Title);
	title.Awake();
}

void GoTitle(){
	Game.RemoveChild();
	Game.AddChild(&Title);
}

void DrawTitle(){
	title.DrawTitle();
}

void GoHowTo(){
	Game.RemoveChild();
	Game.AddChild(&HowTo);
	title.AwakeHow();
}

void DrawHowTo(){
	title.HowTo();
}

void GoStage(){
	stageNow = title.GetStageNow();

	if(Event.key.GetDown(Event.key.RETURN)){
		Game.RemoveChild();
		Game.AddChild(&Stage);
		StageEnter(stageNow);
	}
}

void DrawStage(){
	product.stage.DrawStage();
	product.battle.unitm.DrawUnit();
	back.DrawLine();
	product.battle.cursorm.DrawCursor();
}

void MoveUnit(){
	product.battle.unitm.MoveUnit();
}

void FightUnit(){
	product.battle.Battle();
	product.Product();
}

void SkipTurn(){
	turn.SkipTurn();

	while (product.stage.GetTNum(turn.GetCountry()) == 0){
		product.turn.SkipTurn();
		product.stage.turn.SkipTurn();
		product.battle.turn.SkipTurn();
		product.battle.unitm.turn.SkipTurn();
		turn.SkipTurn();
	}
}

void StageEnter(int stage){

	product.battle.unitm.Awake(stage);
	product.stage.Awake(stage);
	product.stage.CreateStage(stage);
	product.Awake(stage);
	product.battle.Awake(stage);
	turn.Awake();

//	stage = new CStage(1);
}

void GameOver(){
	if (LastOne()){
		Game.RemoveChild();
		Game.AddChild(&Result);
		result.Awake(product.stage.GetLast());
	}
}

void DrawResult(){
	result.DrawResult();

	if (Event.key.GetPush(Event.key.RETURN)){
		GoTitle();
	}
}

bool LastOne(){
	bool only = false;

	for (int i = 1; i <= COUNTRY_NUM; i++){
		if (product.stage.GetTNum(i)){
			if (only){
				only = false;
				break;
			}
			else{
				only = true;
			}
		}
	}

	return only;
}
