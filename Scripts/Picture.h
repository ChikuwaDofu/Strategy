#pragma once

#include"Suken.h"

class CPicture{
private:

public:
	int numPic[10];
	int tilePic[10];
	int townPic;
	int coin;
	int arrowPic[4];
	int unitPic[10];
	int flagPic[5];
	int productScr;//ê∂éYâÊñ ÇÃîwåi
	int cannot[5];
	int close;
	int ok;
	int mapHandle[10];
	int TmapHandle[10];//ìsésÇÃÉ}ÉbÉvÉ`ÉbÉv
	int RangeBox;
	int move[10];
	int siegepic[5];
	int heal;
	int shotRangeBox;
	int combatRangeBox;
	int attackable;
	int strength[3];
	int saveButton[3];
	int closeButton[2];
	void LoadUnitPic();
	void LoadFlagPic();
	void LoadProductPic();
	void LoadMapPic();
	void LoadNumPic();
	void LoadUnitmPic();
	void LoadBattlePic();
	void LoadButtonPic();

	int stageSelect;
	int smallTile[10];
	int howTo[10];
	void LoadTitlePic();
	void LoadHowToPic();

	int result;
	int lFlag[5];
	void LoadResultPic();
};
