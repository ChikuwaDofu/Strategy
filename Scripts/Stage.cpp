#include"DxLib.h"
#include"Suken.h"
#include"Stage.h"
#include"General.h"

CStage::CStage(/*int _type*/){
	type = /*_type*/1;

	for(int i=1;i<=COUNTRY_NUM;i++){
		townNum[i]=0;
	}
}

CStage::~CStage(){
	
}

void CStage::Awake(){
	picture.LoadMapPic();
	picture.LoadFlagPic();
}

void CStage::CreateMap(int _x,int _y){
	int r=0,g=0,b=0,a=0;
	tile[_x][_y]=NULL;
	GetPixelSoftImage(picture.mapHandle,_x,_y,&r,&g,&b,&a);
	if(r==128 && g==255 && b==0){
		tile[_x][_y]=PLAIN;
	}
	if(r==0 && g==255 && b==255){
		tile[_x][_y]=RIVER;
	}


}

void CStage::CreateTown(int _x,int _y){
	int r,g,b,a;
	town[_x][_y]=0;
	GetPixelSoftImage(picture.TmapHandle,_x,_y,&r,&g,&b,&a);
	if(r==255 && g==0 && b==0){
		town[_x][_y]=1;
		townNum[1]++;
	}
	if(r==0 && g==0 && b==255){
		town[_x][_y]=2;
		townNum[2]++;
	}
}

void CStage::CreateStage(){
	for(int x=0;x<MAP_W;x++){
		for(int y=0;y<MAP_H;y++){
			town[x][y]=-1;

			CreateMap(x,y);
			CreateTown(x,y);
		}
	}
}

void CStage::DrawStage(){
	turn.SkipTurn();

	for(int i=1;i<=COUNTRY_NUM;i++){
		DrawGraph(810,20+i*25,picture.flagPic[i],true);
	}

	for(int i=0;i<3;i++){
		DrawBox(810+i,20+turn.GetCountry()*25+i,835-i,45+turn.GetCountry()*25-i,RED,false);
	}

	for(int x=0;x<MAP_W;x++){
		for(int y=0;y<MAP_H;y++){
			switch(tile[x][y]){
			case NULL:
				DrawGraph(GRID_L*(x+2),GRID_L*(y+1),picture.tilePic[BBOX],true);
				break;

			case PLAIN:
				DrawGraph(GRID_L*(x + 2), GRID_L*(y + 1), picture.tilePic[PLAIN], true);
				break;

			case RIVER:
				DrawGraph(GRID_L*(x + 2), GRID_L*(y + 1), picture.tilePic[RIVER], true);
				break;
			}

			if(town[x][y]!=0){
				DrawGraph(GRID_L*(x+2),GRID_L*(y+1),picture.townPic,true);
				DrawGraph(GRID_L*(x+2)+25,GRID_L*(y+1)+25,picture.flagPic[town[x][y]],true);
			}

			if(town[x][y]==turn.GetCountry()){
				for(int i=0;i<=1;i++){
					DrawBox(GRID_L*(x+2)+2+i,GRID_L*(y+1)+2+i,GRID_L*(x+3)-1-i,GRID_L*(y+2)-1-i,M_PINK,false);
				}
			}
		}
	}
}

int CStage::GetTownOwner(int _x,int _y){
	if (0<=_x && _x<MAP_W && 0<=_y && _y<MAP_H){
		return town[_x][_y];
	}else{
		return -1;
	}
}

int CStage::GetTNum(int _country){
	return townNum[_country];
}

//void AwakeStage(int type){
//	stage = new CStage(type);
//} 
//
//void DeleteStage(){
//	delete stage;
//	stage = NULL;
//}
