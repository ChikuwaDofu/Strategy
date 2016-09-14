#pragma once

#include"Suken.h"

class CFiles{
private:
	FILE* funit;

	FILE* fterrain;

public:
	void LoadUnitFile();
	int types;
	char name[5][10];
	int strength[5];
	int rangedStrength[5];
	int siegeStrength[5];
	bool siege[5];
	int move[5];
	int range[5];

	void LoadTerrainFile();
	int terrains;
	int moveCost[5];

};
