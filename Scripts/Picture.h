#pragma once

#include"Suken.h"

class CPicture{
private:

public:
	int numPic[10];
	int tilePic[10];
	int townPic;
	int arrowPic[4];
	int unitPic[5];
	int flagPic[5];
	int productScr;//ê∂éYâÊñ ÇÃîwåi
	int cannot[5];
	int close;
	int ok;
	int mapHandle[5];
	int TmapHandle[5];//ìsésÇÃÉ}ÉbÉvÉ`ÉbÉv
	int RangeBox;
	int move[10];
	int siegepic[5];
	int heal;
	void LoadUnitPic();
	void LoadFlagPic();
	void LoadProductPic();
	void LoadMapPic();
	void LoadNumPic();
	void LoadUnitmPic();

	int stageSelect;
	int smallTile[10];
	int howTo[10];
	void LoadTitlePic();
	void LoadHowToPic();
};
