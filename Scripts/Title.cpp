#include"DxLib.h"
#include"Suken.h"
#include"Title.h"
#include"General.h"

int CTitle::GetStageNow(){
	return stageNow;
}

void CTitle::Awake(){
	picture.LoadTitlePic();
	picture.LoadMapPic();
	picture.LoadFlagPic();

	stageNow = 1;

	for (int i = 1; i <= STAGE_NUM; i++){
		for (int x = 0; x < MAP_W + 1; x++){
			for (int y = 0; y < MAP_H + 1; y++){
				town[i][x][y] = -1;

				CreateMap(x, y, i);
				CreateTown(x, y, i);
			}
		}
	}
}

void CTitle::DrawTitle(){
	DrawGraph(0, 0, picture.stageSelect, true);

	DrawGraph(75, 225, picture.arrowPic[2], true);
	if (Event.LMouse.GetClick(75, 225, 100, 325) || Event.key.GetDown(Event.key.LEFT)){
		ChangeStage(-1);
	}

	DrawGraph(825, 225, picture.arrowPic[3], true);
	if (Event.LMouse.GetClick(825, 225, 850, 325) || Event.key.GetDown(Event.key.RIGHT)){
		ChangeStage(1);
	}

	for (int x = 0; x < MAP_W + 1; x++){
		for (int y = 0; y < MAP_H + 1; y++){
			DrawGraph(25 * x + 100, 25 * y + 50, picture.smallTile[tile[stageNow][x][y]], true);
			DrawGraph(25 * x + 100, 25 * y + 50, picture.flagPic[town[stageNow][x][y]], true);
		}
	}
}

void CTitle::CreateMap(int x, int y, int stage){
	int r = 0, g = 0, b = 0, a = 0;
	tile[stage][x][y] = 0;
	GetPixelSoftImage(picture.mapHandle[stage], x, y, &r, &g, &b, &a);
	if (r == 128 && g == 255 && b == 0){
		tile[stage][x][y] = PLAIN;
	}
	if (r == 0 && g == 255 && b == 255){
		tile[stage][x][y] = RIVER;
	}
	if (r == 0 && g == 0 && b == 255){
		tile[stage][x][y] = BRIDGE_T;
	}
	if (r == 0 && g == 0 && b == 128){
		tile[stage][x][y] = BRIDGE_Y;
	}
	if (r == 128 && g == 128 && b == 128){
		tile[stage][x][y] = MOUNTAIN;
	}
}

void CTitle::CreateTown(int x, int y, int stage){
	int r, g, b, a;
	town[stage][x][y] = 0;
	GetPixelSoftImage(picture.TmapHandle[stage], x, y, &r, &g, &b, &a);
	if (r == 255 && g == 0 && b == 0){
		town[stage][x][y] = 1;
	}
	if (r == 0 && g == 0 && b == 255){
		town[stage][x][y] = 2;
	}
	if (r == 0 && g == 255 && b == 0){
		town[stage][x][y] = 3;
	}
}

void CTitle::ChangeStage(int stage){
	stageNow += stage;

	if (stageNow < 1){
		stageNow = STAGE_NUM;
	}
	if (stageNow > STAGE_NUM){
		stageNow = 1;
	}
}

void CTitle::AwakeHow(){
	howToNum = 0;

	picture.LoadHowToPic();
}

void CTitle::HowTo(){
	DrawGraph(0, 0, picture.howTo[stageNow], true);

	DrawGraph(0, 249, picture.arrowPic[2], true);
	if (Event.LMouse.GetClick(0, 249, 25, 351)){
		ChangeHowTo(-1);
	}

	DrawGraph(875, 249, picture.arrowPic[3], true);
	if (Event.LMouse.GetClick(875, 249, 900, 351)){
		ChangeHowTo(1);
	}
}

void CTitle::ChangeHowTo(int change){
	stageNow += change;

	if (stageNow < 0){
		stageNow = 3;
	}
	if (stageNow > 3){
		stageNow = 0;
	}
}
