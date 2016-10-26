#include"DxLib.h"
#include"Suken.h"
#include"Picture.h"
#include"General.h"

void CPicture::LoadUnitPic(){
	unitPic[0] = LoadGraph("Chikuwa2/Spear.png");
	unitPic[1] = LoadGraph("Chikuwa2/CrossBow.png");
	unitPic[2] = LoadGraph("Chikuwa2/Horseman.png");
	unitPic[3] = LoadGraph("Chikuwa2/HorseArcher.png");
	unitPic[4] = LoadGraph("Chikuwa2/HeavyHorseMan.png");
	unitPic[5] = LoadGraph("Chikuwa2/Sword.png");
	unitPic[6] = LoadGraph("Chikuwa2/Musket.png");
	unitPic[7] = LoadGraph("Chikuwa2/Catapult.png");
	unitPic[8] = LoadGraph("Chikuwa2/Trebuchet.png");
	unitPic[9] = LoadGraph("Chikuwa2/Artillery.png");

	move[1] = LoadGraph("Chikuwa2/move1.png");
	move[2] = LoadGraph("Chikuwa2/move2.png");
	move[3] = LoadGraph("Chikuwa2/move3.png");
	move[4] = LoadGraph("Chikuwa2/move4.png");

	siegepic[0] = LoadGraph("Chikuwa2/SiegeNG.png");
	siegepic[1] = LoadGraph("Chikuwa2/SiegeOK.png");

	heal = LoadGraph("Chikuwa2/heal.png");

	attackable = LoadGraph("Chikuwa2/Attackable.png");
}

void CPicture::LoadFlagPic(){
	flagPic[1] = LoadGraph("Chikuwa2/country1.png");
	flagPic[2] = LoadGraph("Chikuwa2/country2.png");
	flagPic[3] = LoadGraph("Chikuwa2/country3.png");
	flagPic[4] = LoadGraph("Chikuwa2/country4.png");
}

void CPicture::LoadMapPic(){
	tilePic[0] = LoadGraph("Chikuwa2/Void.png");
	tilePic[1] = LoadGraph("Chikuwa2/Grass.png");
	tilePic[2] = LoadGraph("Chikuwa2/River.png");
	tilePic[3] = LoadGraph("Chikuwa2/BridgeV.png");
	tilePic[4] = LoadGraph("Chikuwa2/BridgeH.png");
	tilePic[5] = LoadGraph("Chikuwa2/Mountain.png");
	townPic = LoadGraph("Chikuwa2/Town.png");

	coin=LoadGraph("Chikuwa2/Coin.png");

	arrowPic[0] = LoadGraph("Chikuwa2/ArrowUp.png");
	arrowPic[1] = LoadGraph("Chikuwa2/ArrowDown.png");
	arrowPic[2] = LoadGraph("Chikuwa2/ArrowLeft.png");
	arrowPic[3] = LoadGraph("Chikuwa2/ArrowRight.png");

	mapHandle[1] = LoadSoftImage("Chikuwa2/TestMap.png");
	mapHandle[2] = LoadSoftImage("Chikuwa2/TestMap2.png");
	mapHandle[3] = LoadSoftImage("Chikuwa2/TestMap3.png");
	TmapHandle[1] = LoadSoftImage("Chikuwa2/TestMapTown.png");
	TmapHandle[2] = LoadSoftImage("Chikuwa2/TestMap2Town.png");
	TmapHandle[3] = LoadSoftImage("Chikuwa2/TestMap3Town.png");
}

void CPicture::LoadProductPic(){
	productScr = LoadGraph("Chikuwa2/production.png");
	close = LoadGraph("Chikuwa2/close.png");
	cannot[0] = LoadGraph("Chikuwa2/Can't.png");
	cannot[1] = LoadGraph("Chikuwa2/NoMoney.png");
	ok = LoadGraph("Chikuwa2/OK.png");
	coin = LoadGraph("Chikuwa2/Coin.png");
	strength[0] = LoadGraph("Chikuwa2/Str.png");
	strength[1] = LoadGraph("Chikuwa2/RStr.png");
	strength[2] = LoadGraph("Chikuwa2/SStr.png");
}

void CPicture::LoadNumPic(){
	numPic[0] = LoadGraph("Chikuwa2/0.png");
	numPic[1] = LoadGraph("Chikuwa2/1.png");
	numPic[2] = LoadGraph("Chikuwa2/2.png");
	numPic[3] = LoadGraph("Chikuwa2/3.png");
	numPic[4] = LoadGraph("Chikuwa2/4.png");
	numPic[5] = LoadGraph("Chikuwa2/5.png");
	numPic[6] = LoadGraph("Chikuwa2/6.png");
	numPic[7] = LoadGraph("Chikuwa2/7.png");
	numPic[8] = LoadGraph("Chikuwa2/8.png");
	numPic[9] = LoadGraph("Chikuwa2/9.png");
}

void CPicture::LoadUnitmPic(){
	RangeBox = LoadGraph("Chikuwa2/Range.png");
}

void CPicture::LoadBattlePic(){
	shotRangeBox = LoadGraph("Chikuwa2/ShotRange.png");
	combatRangeBox=LoadGraph("Chikuwa2/CombatRange.png");
}

void CPicture::LoadTitlePic(){
	stageSelect = LoadGraph("Chikuwa2/StageSelect.png");

	smallTile[1] = LoadGraph("Chikuwa2/SGrass.png");
	smallTile[2] = LoadGraph("Chikuwa2/SRiver.png");
	smallTile[3] = LoadGraph("Chikuwa2/SBridge.png");
	smallTile[4] = LoadGraph("Chikuwa2/SBridge.png");
	smallTile[5] = LoadGraph("Chikuwa2/SMountain.png");
}

void CPicture::LoadHowToPic(){
	howTo[0] = LoadGraph("Chikuwa2/HowTo1.png");
	howTo[1] = LoadGraph("Chikuwa2/HowTo2.png");
	howTo[2] = LoadGraph("Chikuwa2/HowTo3.png");
	howTo[3] = LoadGraph("Chikuwa2/HowTo4.png");
	howTo[4] = LoadGraph("Chikuwa2/HowTo5.png");
	howTo[5] = LoadGraph("Chikuwa2/HowTo6.png");
	howTo[6] = LoadGraph("Chikuwa2/HowTo7.png");
}

void CPicture::LoadResultPic(){
	result = LoadGraph("Chikuwa2/GameOver.png");

	lFlag[1] = LoadGraph("Chikuwa2/Lcountry1.png");
	lFlag[2] = LoadGraph("Chikuwa2/Lcountry2.png");
	lFlag[3] = LoadGraph("Chikuwa2/Lcountry3.png");
	lFlag[4] = LoadGraph("Chikuwa2/Lcountry4.png");
}

void CPicture::LoadButtonPic(){
	closeButton[0] = LoadGraph("Chikuwa2/Close.png");
	closeButton[1] = LoadGraph("Chikuwa2/AskClose.png");
	saveButton[0] = LoadGraph("Chikuwa2/SaveButton.png");
	saveButton[1] = LoadGraph("Chikuwa2/SaveButtonAsk.png");
	saveButton[2] = LoadGraph("Chikuwa2/SaveButtonEnd.png");
}
