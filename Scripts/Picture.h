#pragma once

#include"Suken.h"

class CPicture{
private:

public:
	int numPic[10];
	int tilePic[5];
	int townPic;
	int unitPic[5];
	int productScr;//¶Y‰æ–Ê‚Ì”wŒi
	int cannot;
	int close;
	int ok;
	int mapHandle;
	int TmapHandle;//“ss‚Ìƒ}ƒbƒvƒ`ƒbƒv
	int RangeBox;
	void LoadUnitPic();
	void LoadProductPic();
	void LoadMapPic();
	void LoadNumPic();
	void LoadUnitmPic();
};
