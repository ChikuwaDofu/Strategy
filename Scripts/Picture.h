#pragma once

#include"Suken.h"

class CPicture{
private:
	int tilePic[3];
	int townPic;
	int unitPic[2];
	int productScr;//���Y��ʂ̔w�i
	int mapHandle;
	int TmapHandle;//�s�s�̃}�b�v�`�b�v

public:
	void LoadPicture();
	void LoadMapImage();

};
