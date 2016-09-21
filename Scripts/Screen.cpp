#include"DxLib.h"
#include"Suken.h"
#include"Screen.h"
#include"General.h"

CScreen::CScreen(){
	adjX = 0;
	adjY = 0;
}

void CScreen::MoveAdj(){
	if (Event.LMouse.GetClick(400, 25, 500, 50) && adjY > 0){
		adjY--;
	}

	if (Event.LMouse.GetClick(400, 550, 500, 575) && adjY < 1){
		adjY++;
	}

	if (Event.LMouse.GetClick(75, 225, 100, 326) && adjX > 0){
		adjX--;
	}

	if (Event.LMouse.GetClick(800, 225, 825, 326) && adjX < 1){
		adjX++;
	}
}

