#include"DxLib.h"
#include"Suken.h"
#include"Picture.h"
#include"General.h"

void CPicture::LoadPicture(){
	tilePic[NONE]=LoadGraph("Kawachi2/Void.png");
	tilePic[PLAIN]=LoadGraph("Kawachi2/Grass.png");
	tilePic[RIVER]=LoadGraph("Kawachi2/River.png");

	townPic=LoadGraph("Kawachi2/Town.png");

	productScr=LoadGraph("Kawachi2/Production.png");

	unitPic[0]=LoadGraph("Kawachi2/Spear.png");
	unitPic[1]=LoadGraph("Kawachi2/Bow.png");
}

void CPicture::LoadMapImage(){
	mapHandle=LoadSoftImage("Kawachi2/TestMap.png");
	TmapHandle=LoadSoftImage("Kawachi2/TestMapTown.png");
}