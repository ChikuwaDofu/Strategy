#pragma once

#include"Suken.h"

class CFiles{
private:
	FILE* funit;

	FILE* fterrain;

	FILE* fmap;

public:
	void LoadUnitFile();
	int types;
	char name[15][20];
	int strength[15];
	int rangedStrength[15];
	int siegeStrength[15];
	bool siege[15];
	int move[15];
	int range[15];
	int cost[15];

	void LoadTerrainFile();
	int terrains;
	int moveCost[10];

	void LoadMapSize();
	int mapX[10];
	int mapY[10];
};
