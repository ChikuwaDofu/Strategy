#pragma once
//参照
#include"Suken.h"
#include"Manager.h"
//シーン
extern CScene Title;
extern CScene Stage;

void Start();
void GoTitle();
void DrawTitle();
void GoStage();
void DrawStage();
void MoveUnit();
void FightUnit();
void StageEnter();
