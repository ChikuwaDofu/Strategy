#pragma once

#include"Suken.h"

class CPicture{
private:

public:
	int numPic[10];
	int tilePic[5];
	int townPic;
	int unitPic[5];
	int flagPic[5];
	int productScr;//���Y��ʂ̔w�i
	int cannot[5];
	int close;
	int ok;
	int mapHandle;
	int TmapHandle;//�s�s�̃}�b�v�`�b�v
	int RangeBox;
	int move[10];
	int siegepic[5];
	void LoadUnitPic();
	void LoadFlagPic();
	void LoadProductPic();
	void LoadMapPic();
	void LoadNumPic();
	void LoadUnitmPic();
};
