#pragma once
//�Q��
#include"Suken.h"
#include"Manager.h"
//�V�[��
extern CScene Title;
extern CScene HowTo;
extern CScene Stage;

void Start();
void GoTitle();
void DrawTitle();
void GoHowTo();
void DrawHowTo();
void GoStage();
void DrawStage();
void MoveUnit();
void FightUnit();
void StageEnter(int stage);
