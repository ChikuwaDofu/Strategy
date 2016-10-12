#pragma once

#include"Suken.h"
#include"General.h"
#include"Picture.h"
#include"Files.h"
#include"Screen.h"

class CStage{
private:

	CPicture picture;
	CFiles file;
	CScreen screen;
	int sNum;
	int mapW;
	int mapH;
	int type;
	int MapHandle[5];
	int TMapHandle[5];
	int town[20][20];
	int townHp[20][20];
	int tile[20][20];
	int townNum[COUNTRY_NUM+1];
	bool exist[COUNTRY_NUM + 1];
	int displayX;
	int displayY;
	//int countryNow;

public:
	CTurn turn;
	int GetTerrain(int x, int y);
	int GetTNum(int country);
	int GetTownOwner(int x,int y);
	int GetTownHp(int x,int y);
	int GetLast();
	//void SetCountryNow(int country);
	void CreateMap(int x,int y,int stage);
	void CreateTown(int x,int y,int stage);
	void CreateStage(int stage);
	void DamageTown(int x, int y, int damage, int attacker);
	void DrawStage();
	void Awake(int stage);
};

//CStage* stage;

void AwakeStage(int type);

void DeleteStage();
