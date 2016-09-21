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
	int MapHandle[2];
	int TMapHandle[2];
	int TownGraph;
	int TileGraph[3];
	int town[20][20];
	int townHp[20][20];
	int tile[20][20];
	int townNum[COUNTRY_NUM+1];
	int displayX;
	int displayY;

public:
	CStage(/*int _type*/);
	~CStage();
	int GetTerrain(int x, int y);
	int GetTNum(int country);
	int GetTownOwner(int x,int y);
	int GetTownHp(int x,int y);
	void CreateMap(int x,int y);
	void CreateTown(int x,int y);
	void CreateStage();
	void DamageTown(int x, int y, int damage, int attacker);
	void DrawStage();
	void Awake();
};

//CStage* stage;

void AwakeStage(int type);

void DeleteStage();
