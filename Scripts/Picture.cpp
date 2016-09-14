#include"DxLib.h"
#include"Suken.h"
#include"Picture.h"
#include"General.h"

void CPicture::LoadUnitPic(){
	unitPic[0] = LoadGraph("Kawachi2/Spear.png");
	unitPic[1] = LoadGraph("Kawachi2/Bow.png");
	unitPic[2] = LoadGraph("Kawachi2/Artillery.png");

	move[1] = LoadGraph("Kawachi2/move1.png");
	move[2] = LoadGraph("Kawachi2/move2.png");
	move[3] = LoadGraph("Kawachi2/move3.png");
	move[4] = LoadGraph("Kawachi2/move4.png");

	siegepic[0] = LoadGraph("Kawachi2/SiegeNG.png");
	siegepic[1] = LoadGraph("Kawachi2/SiegeOK.png");

	heal = LoadGraph("Kawachi2/heal.png");
}

void CPicture::LoadFlagPic(){
	flagPic[1] = LoadGraph("Kawachi2/country1.png");
	flagPic[2] = LoadGraph("Kawachi2/country2.png");
}

void CPicture::LoadMapPic(){
	tilePic[BBOX] = LoadGraph("Kawachi2/Void.png");
	tilePic[PLAIN] = LoadGraph("Kawachi2/Grass.png");
	tilePic[RIVER] = LoadGraph("Kawachi2/River.png");
	tilePic[BRIDGE_T] = LoadGraph("Kawachi2/BridgeV.png");
	tilePic[BRIDGE_Y] = LoadGraph("Kawachi2/BridgeH.png");
	townPic = LoadGraph("Kawachi2/Town.png");

	mapHandle = LoadSoftImage("Kawachi2/TestMap.png");
	TmapHandle = LoadSoftImage("Kawachi2/TestMapTown.png");
}

void CPicture::LoadProductPic(){
	productScr = LoadGraph("Kawachi2/production.png");
	close = LoadGraph("Kawachi2/close.png");
	cannot[0] = LoadGraph("Kawachi2/Can't.png");
	cannot[1] = LoadGraph("Kawachi2/NoMoney.png");
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
