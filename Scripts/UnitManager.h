#pragma once

#include"Suken.h"
#include"Unit.h"
#include"Country.h"
#include"Picture.h"
#include"Cursor.h"
#include"General.h"

class CUnitManager{
private:
	CUnit unit[UNIT_NUM];
	CCal cal;
	CCursor cursor;
	CPicture picture;
	CTurn turn;
	CCommon common;
	int selectingC;
	int selectingU;
	int GetX(int _country,int _unit);
	int GetY(int _country,int _unit);
	int GetRoute(int _country,int _unit,int _x,int _y);
	bool screen;
	bool Moveable(int dir /*direction*/);
	bool onemove; //��}�X������
	void Select(int _country,int _unit);
	void Setselecting();
	bool Selecting(); //���j�b�g�̂����ꂩ��I��ł��邩
	void Move();
	void SetUnit();
	void PaintUnit();
	bool CheckLCOn(int _country,int _unit);

public:
	CCountry country[COUNTRY_NUM];
	CUnitManager();
	int GetselectingC();
	int GetselectingU();
	void ProductScr(bool open);//���Y��ʂ��J���Ă��邩
	void DrawUnit();
	void MoveUnit();
	void Moveend();
	void Awake();

};
