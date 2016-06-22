#include"DxLib.h"
#include"Suken.h"
#include"Stage.h"
#include"General.h"

CStage::CStage(/*int _type*/){
	type = /*_type*/1;
}

CStage::~CStage(){
	
}

void CStage::Awake(){
	picture.LoadMapPic();
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
	town[_x][_y]=-1;
	GetPixelSoftImage(picture.TmapHandle,_x,_y,&r,&g,&b,&a);
	if(r==255 && g==0 && b==0){
		town[_x][_y]=0;
	}
	if(r==0 && g==0 && b==255){
		town[_x][_y]=1;
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
	for(int x=0;x<MAP_W;x++){
		for(int y=0;y<MAP_H;y++){
			switch(tile[x][y]){
			case NULL:
				DrawGraph(GRID_L*(x+2),GRID_L*(y+1),picture.tilePic[NONE],true);
				break;

			case PLAIN:
				DrawGraph(GRID_L*(x + 2), GRID_L*(y + 1), picture.tilePic[PLAIN], true);
				break;

			case RIVER:
				DrawGraph(GRID_L*(x + 2), GRID_L*(y + 1), picture.tilePic[RIVER], true);
				break;
			}
			if(town[x][y]!=-1){
				DrawGraph(GRID_L*(x+2),GRID_L*(y+1),picture.townPic,true);
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

//void AwakeStage(int type){
//	stage = new CStage(type);
//} 
//
//void DeleteStage(){
//	delete stage;
//	stage = NULL;
//}
