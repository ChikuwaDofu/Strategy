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

CScene Title,Stage;

CTitle title;
CBack back;
CProduct product;
CCommon common;

//CStage *stage;
//CStage s;

void Start(){
	Game.AddChild(&Title);
}

void GoTitle(){
	Game.RemoveChild();
	Game.AddChild(&Title);
}

void DrawTitle(){
	title.DrawTitle();
}

void GoStage(){
	if(Event.key.GetDown(Event.key.RETURN)){
		Game.RemoveChild();
		Game.AddChild(&Stage);
		StageEnter();
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

void StageEnter(){
	product.battle.unitm.Awake();
	product.stage.Awake();
	product.stage.CreateStage();
	product.Awake();

//	stage = new CStage(1);
}
