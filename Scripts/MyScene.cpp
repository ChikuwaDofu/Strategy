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
#include"Savedata.h"
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
CButtons buttons;

int stageNow;

bool enterHowTo;

//CStage *stage;
//CStage s;

void Start(){
	Game.AddChild(&Title);
	title.Awake();

	music->Loop(sTitle);
}

void GoTitle(){
	if(buttons.GetClosed()){
		Game.RemoveChild();
		Game.AddChild(&Title);

		DeleteSave();

		music->StopLoop(sCountry1);
		music->StopLoop(sCountry2);
		music->StopLoop(sCountry3);
		music->StopLoop(sCountry4);

		music->Loop(sTitle);
	}
}

void BackToTitle(){
	Game.RemoveChild();
	Game.AddChild(&Title);

	DeleteSave();

	music->Loop(sTitle);
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

	Game.RemoveChild();
	Game.AddChild(&Stage);
	StageEnter(stageNow);

	music->StopLoop(sTitle);
}

void DrawStage(){
	product.stage.DrawStage();
	product.battle.unitm.DrawUnit();
	back.DrawLine();
	buttons.DrawButton();
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
	LoadSave(stage);

	product.battle.unitm.Awake(stage);
	product.stage.Awake(stage);
	product.stage.CreateStage(stage);
	product.Awake(stage);
	product.battle.Awake(stage);
	turn.Awake();
	buttons.Awake();

//	stage = new CStage(1);
}

void LoadStage(int stage){
	LoadSave(stage);
	ReadSave(stage);

	turn.Load();
	product.turn.Load();
	product.stage.turn.Load();
	product.battle.turn.Load();
	product.battle.unitm.turn.Load();

	product.stage.Load();
	product.battle.unitm.Load();
}

void ContinueStage(){
	GoStage();

	LoadStage(stageNow);
}

void SaveStage(){
	if(buttons.GetSaved()){
		product.stage.Save();
		product.battle.unitm.Save();
		turn.Save();
		product.turn.Save();
		product.stage.turn.Save();
		product.battle.turn.Save();
		product.battle.unitm.turn.Save();

		WriteSave(product.GetStage());
	}
}

void GameOver(){
	if (LastOne()){
		Game.RemoveChild();
		Game.AddChild(&Result);
		result.Awake(product.stage.GetLast());

		music->StopLoop(sCountry1);
		music->StopLoop(sCountry2);
		music->StopLoop(sCountry3);
		music->StopLoop(sCountry4);

		music->AddSound(sWinner);
	}
}

void DrawResult(){
	result.DrawResult();

	if (Event.key.GetDown(Event.key.RETURN)){
		BackToTitle();
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
