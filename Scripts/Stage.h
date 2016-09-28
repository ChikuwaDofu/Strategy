#pragma once

#include"Suken.h"
#include"General.h"
#include"Picture.h"
#include"Screen.h"

class CStage{
private:

	CPicture picture;
	CTurn turn;
	CScreen screen;
	int type;
	int MapHandle[5];
	int TMapHandle[5];
	int town[20][20];
	int townHp[20][20];
	int tile[20][20];
	int townNum[COUNTRY_NUM+1];
	int displayX;
	int displayY;

public:
	int GetTerrain(int x, int y);
	int GetTNum(int country);
	int GetTownOwner(int x,int y);
	int GetTownHp(int x,int y);
	void CreateMap(int x,int y,int stage);
	void CreateTown(int x,int y,int stage);
	void CreateStage(int stage);
	void DamageTown(int x, int y, int damage, int attacker);
	void DrawStage();
	void Awake();
};

//CStage* stage;

void AwakeStage(int type);

void DeleteStage();
