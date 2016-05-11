#pragma once

#include"Suken.h"

class CPicture{
private:
	int tilePic[3];
	int townPic;
	int unitPic[2];
	int productScr;//¶Y‰æ–Ê‚Ì”wŒi
	int mapHandle;
	int TmapHandle;//“ss‚Ìƒ}ƒbƒvƒ`ƒbƒv

public:
	void LoadPicture();
	void LoadMapImage();

};
