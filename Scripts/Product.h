#pragma once

#include"Suken.h"
#include"General.h"
#include"Picture.h"
#include"Stage.h"
#include"Cursor.h"
#include"Battle.h"

class CProduct{
private:
	CCursor cursor;
	CPicture picture;
	int forcheck;//���j�b�g�g�m�F�p
	int Getcx();
	int Getcy();
	int window;
	int cannot;
	int close;
	int unitpic[2];
	int country;
	int locationX;
	int locationY;
	bool openwin;//���Y��ʂ��J���Ă��邩
	bool cant;//can't ���Y�ł��Ȃ��Ƃ��̉�ʕ\��
	bool openednow;
	bool produced;
	bool UnitOnTown();

public:
	CProduct(); 
	CBattle battle;
	CStage stage;
	void Awake();
	void Product();
};
