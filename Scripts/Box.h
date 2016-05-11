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
#include"General.h"

class CUnit{
private:
	CTurn turn;
	int type;
	int unitX;
	int unitY;
	int moves;
	int route[20][20]; //マスの状態（通行可能か＞route）
	bool MoveEnd;
	int hp;
	int strength;
	int shotstrength;
	int range;

public:
	CUnit();
	void Setunit();
	void SetMoves();
	void SetMoveEnd();
	void MakeMoveEnd(); //移動を強制的に停止（戦闘後に呼び出し）
	int Getx();
	int Gety();
	int Gettype();
	int GetunitX();
	int GetunitY();
	int GetMoves();
	int GetRoute(int _x,int _y);
	bool GetMoveEnd();
	void Move(int dir /*direction*/);
	void SetObstacle(int _x,int _y);
	void Awake(int _x,int _y,int type,int str /*strength*/,int Rstr);
	void CheckMoveable();
	void SkipTurn();
	int Gethp();
	int Getstrength();
	int GetSstrength();
	int GetRange();
	void Damage(int d);
	void Death();
	void Survive(); //強制生存処理

};
