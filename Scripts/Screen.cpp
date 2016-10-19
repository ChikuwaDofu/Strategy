#include"DxLib.h"
#include"Suken.h"
#include"Screen.h"
#include"General.h"

void CScreen::SetStage(){
	file.LoadMapSize();
	adjX = 0;
	adjY = 0;
}

void CScreen::MoveAdj(int stage){
	if (Event.LMouse.GetClick(400, 25, 500, 50) && adjY > 0){
		adjY--;
	}

	if (Event.LMouse.GetClick(400, 550, 500, 575) && adjY < file.mapY[stage]-MAP_H){
		adjY++;
	}

	if (Event.LMouse.GetClick(75, 225, 100, 326) && adjX > 0){
		adjX--;
	}

	if (Event.LMouse.GetClick(800, 225, 825, 326) && adjX < file.mapX[stage]-MAP_W){
		adjX++;
	}
}

