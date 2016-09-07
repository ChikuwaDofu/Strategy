#pragma once

#include"Suken.h"
#include"Unit.h"
#include"Country.h"
#include"Picture.h"
#include"Cursor.h"
#include"General.h"

class CUnitManager{
private:
	CUnit unit[UNIT_NUM+1];
	CCal cal;
	CCursor cursor;
	CPicture picture;
	CTurn turn;
	CCommon common;
	int selectingC;
	int selectingU;
	bool NotPrepared();
	int Getx(int nation,int unit);
	int Gety(int nation,int unit);
	bool GetRoute(int nation,int unit,int x,int y);
	int GetObstacle(int nation, int unit, int x, int y);
	void ChangeObstacle(int x, int y,int type);
	bool screen;
	bool Moveable(int dir /*direction*/);
	bool IsFair(int x,int y);
	bool onemove; //一マス動いた
	void Select(int unit);
	void Setselecting();
	bool Selecting(); //ユニットのいずれかを選んでいるか
	void Move();
	void SetUnit();
	void PaintUnit();
	bool CheckLCOn(int nation, int unit);
	bool CheckRCOn(int nation, int unit);

public:
	CCountry country[COUNTRY_NUM+1];
	CUnitManager();
	int GetselectingU();
	void ProductScr(bool open1,bool open2);//生産画面が開いているか
	void DrawUnit();
	void MoveUnit();
	void CheckMoveend();
	void Awake();

};
