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
	char name[10][10];
	int strength[10];
	int rangedStrength[10];
	int siegeStrength[10];
	bool siege[10];
	int move[10];
	int range[10];
	int cost[10];

	void LoadTerrainFile();
	int terrains;
	int moveCost[10];

	void LoadMapSize();
	int mapX[10];
	int mapY[10];
};
