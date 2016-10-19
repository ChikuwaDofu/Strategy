#include"DxLib.h"
#include"Suken.h"
#include"Picture.h"
#include"General.h"

void CPicture::LoadUnitPic(){
	unitPic[0] = LoadGraph("Kawachi2/Spear.png");
	unitPic[1] = LoadGraph("Kawachi2/Bow.png");
	unitPic[2] = LoadGraph("Kawachi2/Artillery.png");
	unitPic[3] = LoadGraph("Kawachi2/Horseman.png");

	move[1] = LoadGraph("Kawachi2/move1.png");
	move[2] = LoadGraph("Kawachi2/move2.png");
	move[3] = LoadGraph("Kawachi2/move3.png");
	move[4] = LoadGraph("Kawachi2/move4.png");

	siegepic[0] = LoadGraph("Kawachi2/SiegeNG.png");
	siegepic[1] = LoadGraph("Kawachi2/SiegeOK.png");

	heal = LoadGraph("Kawachi2/heal.png");

	attackable = LoadGraph("Kawachi2/Attackable.png");
}

void CPicture::LoadFlagPic(){
	flagPic[1] = LoadGraph("Kawachi2/country1.png");
	flagPic[2] = LoadGraph("Kawachi2/country2.png");
	flagPic[3] = LoadGraph("Kawachi2/country3.png");
	flagPic[4] = LoadGraph("Kawachi2/country4.png");
}

void CPicture::LoadMapPic(){
	tilePic[0] = LoadGraph("Kawachi2/Void.png");
	tilePic[1] = LoadGraph("Kawachi2/Grass.png");
	tilePic[2] = LoadGraph("Kawachi2/River.png");
	tilePic[3] = LoadGraph("Kawachi2/BridgeV.png");
	tilePic[4] = LoadGraph("Kawachi2/BridgeH.png");
	tilePic[5] = LoadGraph("Kawachi2/Mountain.png");
	townPic = LoadGraph("Kawachi2/Town.png");

	coin=LoadGraph("Kawachi2/Coin.png");

	arrowPic[0] = LoadGraph("Kawachi2/ArrowUp.png");
	arrowPic[1] = LoadGraph("Kawachi2/ArrowDown.png");
	arrowPic[2] = LoadGraph("Kawachi2/ArrowLeft.png");
	arrowPic[3] = LoadGraph("Kawachi2/ArrowRight.png");

	mapHandle[1] = LoadSoftImage("Kawachi2/TestMap.png");
	mapHandle[2] = LoadSoftImage("Kawachi2/TestMap2.png");
	mapHandle[3] = LoadSoftImage("Kawachi2/TestMap3.png");
	TmapHandle[1] = LoadSoftImage("Kawachi2/TestMapTown.png");
	TmapHandle[2] = LoadSoftImage("Kawachi2/TestMap2Town.png");
	TmapHandle[3] = LoadSoftImage("Kawachi2/TestMap3Town.png");
}

void CPicture::LoadProductPic(){
	productScr = LoadGraph("Kawachi2/production.png");
	close = LoadGraph("Kawachi2/close.png");
	cannot[0] = LoadGraph("Kawachi2/Can't.png");
	cannot[1] = LoadGraph("Kawachi2/NoMoney.png");
	ok = LoadGraph("Kawachi2/OK.png");
	coin = LoadGraph("Kawachi2/Coin.png");
	strength[0] = LoadGraph("Kawachi2/Str.png");
	strength[1] = LoadGraph("Kawachi2/RStr.png");
	strength[2] = LoadGraph("Kawachi2/SStr.png");
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

void CPicture::LoadBattlePic(){
	shotRangeBox = LoadGraph("Kawachi2/ShotRange.png");
	combatRangeBox=LoadGraph("Kawachi2/CombatRange.png");
}

void CPicture::LoadTitlePic(){
	stageSelect = LoadGraph("Kawachi2/StageSelect.png");

	smallTile[1] = LoadGraph("Kawachi2/SGrass.png");
	smallTile[2] = LoadGraph("Kawachi2/SRiver.png");
	smallTile[3] = LoadGraph("Kawachi2/SBridge.png");
	smallTile[4] = LoadGraph("Kawachi2/SBridge.png");
	smallTile[5] = LoadGraph("Kawachi2/SMountain.png");
}

void CPicture::LoadHowToPic(){
	howTo[0] = LoadGraph("Kawachi2/HowTo1.png");
	howTo[1] = LoadGraph("Kawachi2/HowTo2.png");
	howTo[2] = LoadGraph("Kawachi2/HowTo3.png");
	howTo[3] = LoadGraph("Kawachi2/HowTo4.png");
	howTo[4] = LoadGraph("Kawachi2/HowTo5.png");
	howTo[5] = LoadGraph("Kawachi2/HowTo6.png");
	howTo[6] = LoadGraph("Kawachi2/HowTo7.png");
}

void CPicture::LoadResultPic(){
	result = LoadGraph("Kawachi2/GameOver.png");

	lFlag[1] = LoadGraph("Kawachi2/Lcountry1.png");
	lFlag[2] = LoadGraph("Kawachi2/Lcountry2.png");
	lFlag[3] = LoadGraph("Kawachi2/Lcountry3.png");
	lFlag[4] = LoadGraph("Kawachi2/Lcountry4.png");
}
