#pragma once

#include"Suken.h"
#include"Unit.h"
#include"Country.h"
#include"Screen.h"
#include"Picture.h"
#include"Files.h"
#include"Cursor.h"
#include"General.h"

class CUnitManager{
private:
	CUnit unit[UNIT_NUM+1];
	CCal cal;
	CCursor cursor;
	CScreen cscreen;
	CPicture picture;
	CFiles file;
	CCommon common;
	int sNum;
	int mapW;
	int mapH;
	int displayX;
	int displayY;
	int moveCost[20][20];
	int selectingC;
	int selectingU;
	bool NotPrepared();
	int Getx(int nation,int unit);
	int Gety(int nation,int unit);
	int GetMoves(int nation, int unit);
	int route[20][20];
	int GetObstacle(int nation, int unit, int x, int y);
	void ChangeObstacle(int x, int y,int type);
	bool screen;
	bool Moveable(int dir /*direction*/);
	bool IsFair(int x,int y);
	bool onemove; //一マス動いた
	void Select(int unit);
	void Setselecting();
	bool Selecting(); //ユニットのいずれかを選んでいるか
	void CheckRoute();
	void Move();
	void SetUnit();
	void PaintUnit();
	bool CheckLCOn(int nation, int unit);
	bool CheckRCOn(int nation, int unit);

public:
	CCountry country[COUNTRY_NUM + 1];
	CTurn turn;
	CUnitManager();
	int GetselectingU();
	void SetMoveCost(int x, int y, int cost);
	void ProductScr(bool open1,bool open2);//生産画面が開いているか
	void DrawUnit();
	void MoveUnit();
	void CheckMoveend();
	void Awake(int stage);

};
