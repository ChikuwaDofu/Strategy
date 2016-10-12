#pragma once
//参照
#include"Suken.h"
#include"Manager.h"
//シーン
extern CScene Title;
extern CScene HowTo;
extern CScene Stage;
extern CScene Result;

void Start();
void GoTitle();
void DrawTitle();
void GoHowTo();
void DrawHowTo();
void GoStage();
void DrawStage();
void MoveUnit();
void FightUnit();
void SkipTurn();
bool LastOne();
void GameOver();
void DrawResult();
void StageEnter(int stage);
