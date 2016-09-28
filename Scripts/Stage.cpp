#include"DxLib.h"
#include"Suken.h"
#include"Stage.h"
#include"General.h"

int Ax[4] = { 400, 400, 75, 800 };
int Ay[4] = { 25, 550, 225, 225 };
void CStage::Awake(){
	picture.LoadMapPic();
	picture.LoadFlagPic();
	picture.LoadNumPic();

	turn.Awake();

	for (int i = 1; i <= COUNTRY_NUM; i++){
		townNum[i] = 0;
	}
}

void CStage::CreateMap(int x,int y,int stage){
	int r=0,g=0,b=0,a=0;
	tile[x][y]=NULL;
	GetPixelSoftImage(picture.mapHandle[stage],x,y,&r,&g,&b,&a);
	if(r==128 && g==255 && b==0){
		tile[x][y]=PLAIN;
	}
	if(r==0 && g==255 && b==255){
		tile[x][y]=RIVER;
	}
	if(r==0 && g==0 && b==255){
		tile[x][y]=BRIDGE_T;
	}
	if(r==0 && g==0 && b==128){
		tile[x][y]=BRIDGE_Y;
	}
	if (r == 128 && g == 128 && b == 128){
		tile[x][y] = MOUNTAIN;
	}
}

void CStage::CreateTown(int x,int y,int stage){
	int r,g,b,a;
	town[x][y]=0;
	GetPixelSoftImage(picture.TmapHandle[stage],x,y,&r,&g,&b,&a);
	if(r==255 && g==0 && b==0){
		town[x][y]=1;
		townNum[1]++;
		townHp[x][y] = 100;
	}
	if(r==0 && g==0 && b==255){
		town[x][y]=2;
		townNum[2]++;
		townHp[x][y] = 100;
	}
	if (r == 0 && g == 255 && b == 0){
		town[x][y] = 3;
		townNum[3]++;
		townHp[x][y] = 100;

	}
}

void CStage::CreateStage(int stage){
	for(int x=0;x<MAP_W+1;x++){
		for(int y=0;y<MAP_H+1;y++){
			town[x][y]=-1;

			CreateMap(x,y,stage);
			CreateTown(x,y,stage);
		}
	}
}

void CStage::DamageTown(int x, int y, int damage, int attacker){
	townHp[x][y] -= damage;

	if (townHp[x][y] <= 0){
		townNum[town[x][y]]--;
		town[x][y] = attacker;
		townNum[attacker]++;
	}
}

void CStage::DrawStage(){
	turn.SkipTurn();
	screen.MoveAdj();

	for(int i=1;i<=COUNTRY_NUM;i++){
		DrawGraph(810,20+i*25,picture.flagPic[i],true);
	}

	for(int i=0;i<3;i++){
		DrawBox(810+i,20+turn.GetCountry()*25+i,835-i,45+turn.GetCountry()*25-i,RED,false);
	}

	for(int x=0;x<MAP_W;x++){
		for(int y=0;y<MAP_H;y++){
			displayX = x + screen.adjX;
			displayY = y + screen.adjY;

			DrawGraph(GRID_L*(x + 2), GRID_L*(y + 1), picture.tilePic[tile[displayX][displayY]], true);

			if (town[displayX][displayY] != 0){
				DrawGraph(GRID_L*(x + 2), GRID_L*(y + 1), picture.townPic, true);
				DrawGraph(GRID_L*(x + 2) + 25, GRID_L*(y + 1) + 25, picture.flagPic[town[displayX][displayY]], true);

				if (townHp[displayX][displayY]<100){
					DrawGraph(x * 50 + 102, y * 50 + 77, picture.numPic[townHp[displayX][displayY] / 10], true);
					DrawGraph(x * 50 + 112, y * 50 + 77, picture.numPic[townHp[displayX][displayY] % 10], true);
				}
			}

			if (town[displayX][displayY] == turn.GetCountry()){
				for(int i=0;i<=1;i++){
					DrawBox(GRID_L*(x+2)+2+i,GRID_L*(y+1)+2+i,GRID_L*(x+3)-1-i,GRID_L*(y+2)-1-i,M_PINK,false);
				}
			}

			if (townHp[displayX][displayY] <= 0 && town[displayX][displayY] != 0){
				town[displayX][displayY] = turn.GetCountry();
				townHp[displayX][displayY] = 50;
			}
		}
	}

	for (int i = 0; i < 4; i++){
		DrawGraph(Ax[i], Ay[i], picture.arrowPic[i], true);
	}
}

int CStage::GetTerrain(int x, int y){
	return tile[x][y];
}

int CStage::GetTownOwner(int x,int y){
	if (0<=x && x<MAP_W+1 && 0<=y && y<MAP_H+1){
		return town[x][y];
	}else{
		return -1;
	}
}

int CStage::GetTNum(int country){
	return townNum[country];
}

int CStage::GetTownHp(int x,int y){
	return townHp[x][y];
}

//void AwakeStage(int type){
//	stage = new CStage(type);
//} 
//
//void DeleteStage(){
//	delete stage;
//	stage = NULL;
//}
