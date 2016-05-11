#pragma once

#include"Suken.h"
#include"General.h"
#include"Stage.h"
#include"Cursor.h"
#include"Battle.h"

class CProduct{
private:
	CCursor cursor;
	int Getcx();
	int Getcy();
	int window;
	int unitpic[2];
	int country;
	int locationX;
	int locationY;
	bool openwin;//¶Y‰æ–Ê‚ªŠJ‚¢‚Ä‚¢‚é‚©
	bool openednow;

public:
	CProduct(); 
	CBattle battle;
	CStage stage;
	void Awake();
	void Product();
};
