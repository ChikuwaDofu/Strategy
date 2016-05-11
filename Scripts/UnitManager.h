#pragma once

#include"Suken.h"
#include"Unit.h"
#include"Country.h"
#include"Cursor.h"
#include"General.h"

class CUnitManager{
private:
	CUnit unit[UNIT_NUM];
	CCal cal;
	CCursor cursor;
	CTurn turn;
	CCommon common;
	int selectingC;
	int selectingU;
	int GetX(int _country,int _unit);
	int GetY(int _country,int _unit);
	int GetRoute(int _country,int _unit,int _x,int _y);
	bool Moveable(int dir /*direction*/);
	bool onemove; //一マス動いた
	void Select(int _country,int _unit);
	void Setselecting();
	bool Selecting(); //ユニットのいずれかを選んでいるか
	void Move();
	void SetUnit();
	void PaintUnit();

public:
	CCountry country[COUNTRY_NUM];
	CUnitManager();
	int GetselectingC();
	int GetselectingU();
	void DrawUnit();
	void MoveUnit();
	void Moveend();
	void Awake();

};
