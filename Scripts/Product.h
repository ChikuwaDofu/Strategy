#pragma once

#include"Suken.h"
#include"General.h"
#include"Picture.h"
#include"Stage.h"
#include"Files.h"
#include"Cursor.h"
#include"Screen.h"
#include"Battle.h"

class CProduct{
private:
	CCursor cursor;
	CPicture picture;
	CFiles file;
	CDraw draw;
	CScreen screen;
	int sNum;
	int mapW;
	int mapH;
	int forcheck;//ユニット枠確認用
	int Getcx();
	int Getcy();
	int window;
	int cannot[2];
	int close;
	int locationX;
	int locationY;
	bool openwin;//生産画面が開いているか
	bool cant[2];//can't 生産できないときの画面表示
	bool openednow;
	bool produced;
	bool UnitOnTown();
	void SetTownOwner();
	void DamageTown(int x, int y, int damage, int attacker);

public:
	CProduct(); 
	CBattle battle;
	CStage stage;
	CTurn turn;
	void Awake(int stageNum);
	void Product();
	int GetStage();
	void Income();
};
