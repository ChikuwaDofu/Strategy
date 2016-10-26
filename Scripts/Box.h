#pragma once

const int table[361]={	18,17,16,15,14,13,12,11,10, 9,10,11,12,13,14,15,16,17,18,
						17,16,15,14,13,12,11,10, 9, 8, 9,10,11,12,13,14,15,16,17,
						16,15,14,13,12,11,10, 9, 8, 7, 8, 9,10,11,12,13,14,15,16,
						15,14,13,12,11,10, 9, 8, 7, 6, 7, 8, 9,10,11,12,13,14,15,
						14,13,12,11,10, 9, 8, 7, 6, 5, 6, 7, 8, 9,10,11,12,13,14,
						13,12,11,10, 9, 8, 7, 6, 5, 4, 5, 6, 7, 8, 9,10,11,12,13,
						12,11,10, 9, 8, 7, 6, 5, 4, 3, 4, 5, 6, 7, 8, 9,10,11,12,
						11,10, 9, 8, 7, 6, 5, 4, 3, 2, 3, 4, 5, 6, 7, 8, 9,10,11,
						10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,
						9,8,7,6,5,4,3,2,1, 0 ,1,2,3,4,5,6,7,8,9,
						10,9,8,7,6,5,4,3,2,1,2,3,4,5,6,7,8,9,10,
						11,10,9,8,7,6,5,4,3,2,3,4,5,6,7,8,9,10,11,
						12,11,10,9,8,7,6,5,4,3,4,5,6,7,8,9,10,11,12,
						13,12,11,10,9,8,7,6,5,4,5,6,7,8,9,10,11,12,13,
						14,13,12,11,10,9,8,7,6,5,6,7,8,9,10,11,12,13,14,
						15,14,13,12,11,10,9,8,7,6,7,8,9,10,11,12,13,14,15,
						16,15,14,13,12,11,10,9,8,7,8,9,10,11,12,13,14,15,16,
						17,16,15,14,13,12,11,10,9,8,9,10,11,12,13,14,15,16,17,
						18,17,16,15,14,13,12,11,10,9,10,11,12,13,14,15,16,17,18};

int Array2D(int x,int y);

#include"Suken.h"
#include"Cursor.h"
#include"General.h"

class CUnit{
private:
	CCursor cursor;
	CTurn turn;
	int width;
	int height;
	int type;
	int unitX;
	int unitY;
	bool up,down,right,left;
	bool lclick;
	bool selected;
	int moves;
	int route[20][20];
	bool moving;
	bool MoveEnd;
	bool able[20][20];
	int hp;
	int strength;
	int shotstrength;
	int range;

public:
	CUnit();
	void SetWidth();
	void SetHeight();
	void SetunitX();
	void SetunitY();
	void SetMoves();
	void SetMoveEnd();
	void MakeMoveEnd();
	int Getx();
	int Gety();
	int GetWidth();
	int GetHeight();
	int Gettype();
	int GetunitX();
	int GetunitY();
	int GetMoves();
	int GetRoute(int _x,int _y);
	bool Getmoving();
	bool GetSelected();
	bool GetMoveEnd();
	bool Getable(int _x,int _y);
	void Move(int a);
	void SetObstacle(int _x,int _y);
	void CheckSelected();
	void Awake(int _x,int _y,int type,int str,int Rstr);
	void SetMoveable();
	void CheckMoveable();
	void SkipTurn();
	int Gethp();
	void Sethp();
	int Getstrength();
	void Setstrength();
	int GetSstrength();
	int GetRange();
	void Damage(int d);
	void Death();
	void Survive();

};
