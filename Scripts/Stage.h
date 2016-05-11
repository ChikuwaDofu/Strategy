#pragma once

#include"Suken.h"
#include"General.h"

class CStage{
private:
	int type;
	int MapHandle[2];
	int TMapHandle[2];
	int TownGraph;
	int TileGraph[3];
	int town[MAP_W][MAP_H];
	int tile[MAP_W][MAP_H];

public:
	CStage(/*int _type*/);
	~CStage();
	int GetTownOwner(int _x,int _y); 
	void CreateMap(int _x,int _y);
	void CreateTown(int _x,int _y);
	void CreateStage();
	void DrawStage();
	void Awake();
};

class CStageManager{
public:
	CStageManager();
	~CStageManager();

private:

};

//CStage* stage;

void AwakeStage(int type);

void DeleteStage();
