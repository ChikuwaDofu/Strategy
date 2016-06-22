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
	int forcheck;//ユニット枠確認用
	int Getcx();
	int Getcy();
	int window;
	int cannot;
	int close;
	int unitpic[2];
	int country;
	int locationX;
	int locationY;
	bool openwin;//生産画面が開いているか
	bool cant;//can't 生産できないときの画面表示
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
