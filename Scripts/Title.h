#pragma once

#include"Suken.h"
#include"Picture.h"

class CTitle{
private:
	CPicture picture;
	int stageNow;
	int tile[5][20][20];
	int town[5][20][20];
	int MapHandle[5];
	int TMapHandle[5];

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
