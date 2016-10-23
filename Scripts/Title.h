#pragma once

#include"Suken.h"
#include"Picture.h"
#include"Files.h"
#include"Music.h"

class CTitle{
private:
	CPicture picture;
	CFiles file;
	int stageNow;
	int tile[10][20][20];
	int town[10][20][20];
	int MapHandle[10];
	int TMapHandle[10];

	int howToNum;

public:
	int GetStageNow();

	void Awake();
	void DrawTitle();

	void ChangeStage(int stage);

	void BuildStage();
	void CreateMap(int x, int y, int stage);
	void CreateTown(int x, int y, int stage);

	void AwakeHow();
	void HowTo();
	void ChangeHowTo(int change);
};
