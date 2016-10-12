#include"DxLib.h"
#include"Suken.h"
#include"Files.h"
#include"General.h"

void CFiles::LoadUnitFile(){
	funit = fopen("Kawachi2/Data_Unit.txt", "r");

	fscanf(funit,"%d",&types);

	for (int i = 1; i <= types; i++){
		fscanf(funit, "%s %d %d %d %d %d %d %d", &name[i], &strength[i], &rangedStrength[i], &siegeStrength[i], &siege[i], &move[i], &range[i], &cost[i]);
	}

	fclose(funit);
}

void CFiles::LoadTerrainFile(){
	fterrain = fopen("Kawachi2/Data_Terrain.txt", "r");

	fscanf(fterrain,"%d",&terrains);

	for (int i = 1; i <= terrains; i++){
		fscanf(fterrain,"%d",&moveCost[i]);
	}

	fclose(fterrain);
}

void CFiles::LoadMapSize(){
	fmap = fopen("Kawachi2/Data_MapSize.txt", "r");

	for (int i = 1; i <= STAGE_NUM; i++){
		fscanf(fmap, "%d %d", &mapX[i], &mapY[i]);
	}

	fclose(fmap);
}
