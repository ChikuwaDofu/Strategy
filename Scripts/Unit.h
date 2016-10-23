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
#include"Picture.h"
#include"Files.h"
#include"Screen.h"

class CUnit{
private:
	CPicture picture;
	CFiles file;
	int unitType;
	bool siege; //攻城兵器か否か
	bool prepared;
	int unitX;
	int unitY;
	int displayX;
	int displayY;
	int moves;
	int obstacle[20][20];
	bool Moved();//　仮の変数：一度でも動いたか　ファイル読み込み方式導入まで
	bool MoveEnd;
	int hp;
	int strength;
	int r_strength;
	int s_strength;
	int range;
	bool attacked;

public:
	CUnit();
	void Setunit();
	void SetMoves();
	void SetMoveEnd();
	void MakeMoveEnd(); //移動停止判定
	void SetPrepared(bool prepare);
	void SetAttacked(bool hadAttacked);
	bool GetPrepared();
	int Getx();
	int Gety();
	int Gettype();
	bool IsSiege();
	int GetunitX();
	int GetunitY();
	int GetMoves();
	int GetObstacle(int x, int y);
	bool GetMoveEnd();
	bool GetAttacked();
	void Move(int dir /*direction*/, int cost);
	void SetObstacle(int x,int y,int type);
	void Awake(int x,int y,int type);
	void SkipTurn();
	int Gethp();
	int Getstrength();
	int GetRstrength();
	int GetSstrength();
	int GetRange();
	void Damage(int d);
	void Death();
	void Survive(); //強制生存処理
	void Recover(int r);
	void Product(int x,int y,int type); //生産されたときに使う
	void DrawUnit(int country, int stage, int adjX, int adjY);
	void DrawMoves();
	void DrawHeal();
	void Load(int country,int unit);
};
