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

class CUnit{
private:
	CTurn turn;
	CPicture picture;
	int type;
	bool siege; //�U�镺�킩�ۂ�
	bool prepared;
	int unitX;
	int unitY;
	int moves;
	int route[20][20]; //�}�X�̏�ԁi�ʍs�\����route�j
	bool moved;//�@���̕ϐ��F��x�ł����������@�t�@�C���ǂݍ��ݕ��������܂�
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
	void MakeMoveEnd(); //�ړ��������I�ɒ�~�i�퓬��ɌĂяo���j
	void SetPrepared(bool prepare);
	bool GetPrepared();
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
	void Awake(int _x,int _y,int type);
	void CheckMoveable();
	void SkipTurn();
	int Gethp();
	int Getstrength();
	int GetSstrength();
	int GetRange();
	void Damage(int d);
	void Death();
	void Survive(); //������������
	void Recover(int r);
	void Product(int _x,int _y,int _type); //���Y���ꂽ�Ƃ��Ɏg��
	void DrawUnit(int _country);
	void DrawMoves();
};
