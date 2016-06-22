#include"DxLib.h"
#include"Suken.h"
#include"Picture.h"
#include"General.h"

void CPicture::LoadUnitPic(){
	unitPic[0] = LoadGraph("Kawachi2/Spear.png");
	unitPic[1] = LoadGraph("Kawachi2/Bow.png");
} 

void CPicture::LoadMapPic(){
	tilePic[0] = LoadGraph("Kawachi2/Void.png");
	tilePic[1] = LoadGraph("Kawachi2/Grass.png");
	tilePic[2] = LoadGraph("Kawachi2/River.png");
	townPic = LoadGraph("Kawachi2/Town.png");

	mapHandle = LoadSoftImage("Kawachi2/TestMap.png");
	TmapHandle = LoadSoftImage("Kawachi2/TestMapTown.png");
}

void CPicture::LoadProductPic(){
	productScr = LoadGraph("Kawachi2/production.png");
	close = LoadGraph("Kawachi2/close.png");
	cannot = LoadGraph("Kawachi2/Can't.png");
	ok = LoadGraph("Kawachi2/OK.png");
}

void CPicture::LoadNumPic(){
	numPic[0] = LoadGraph("Kawachi2/0.png");
	numPic[1] = LoadGraph("Kawachi2/1.png");
	numPic[2] = LoadGraph("Kawachi2/2.png");
	numPic[3] = LoadGraph("Kawachi2/3.png");
	numPic[4] = LoadGraph("Kawachi2/4.png");
	numPic[5] = LoadGraph("Kawachi2/5.png");
	numPic[6] = LoadGraph("Kawachi2/6.png");
	numPic[7] = LoadGraph("Kawachi2/7.png");
	numPic[8] = LoadGraph("Kawachi2/8.png");
	numPic[9] = LoadGraph("Kawachi2/9.png");
}

void CPicture::LoadUnitmPic(){
	RangeBox = LoadGraph("Kawachi2/Range.png");
}
