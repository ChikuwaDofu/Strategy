#include"DxLib.h"
#include"Suken.h"
#include"Files.h"
#include"General.h"

void CFiles::LoadUnitFile(){
	funit = fopen("Kawachi2/Data_Unit.txt", "r");

	fscanf(funit,"%d",&types);

	for (int i = 1; i <= types; i++){
		fscanf(funit, "%d %d %d %d %d %d", &strength[i], &rangedStrength[i], &siegeStrength[i], &siege[i], &move[i], &range[i]);
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
