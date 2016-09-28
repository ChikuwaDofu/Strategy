#include"Manager.h"
#include"Title.h"
#include"Back.h"
#include"Cursor.h"
#include"UnitManager.h"
#include"Battle.h"
#include"Stage.h"
#include"Product.h"
#include"General.h"
#include"MyScene.h"

CScene Title,HowTo,Stage;

CTitle title;
CBack back;
CProduct product;
CCommon common;

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

void StageEnter(int stage){
	product.battle.unitm.Awake();
	product.stage.Awake();
	product.stage.CreateStage(stage);
	product.Awake();
	product.battle.Awake();

//	stage = new CStage(1);
}
