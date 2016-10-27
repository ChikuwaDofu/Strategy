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
	int forcheck;//���j�b�g�g�m�F�p
	int Getcx();
	int Getcy();
	int window;
	int cannot[2];
	int close;
	int locationX;
	int locationY;
	bool openwin;//���Y��ʂ��J���Ă��邩
	bool cant[2];//can't ���Y�ł��Ȃ��Ƃ��̉�ʕ\��
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
