#pragma once

#include"Suken.h"
#include"Unit.h"
#include"Cursor.h"
#include"Screen.h"
#include"UnitManager.h"
#include"Picture.h"
#include"Files.h"

class CBattle{
private:
	CScreen screen;
	CCal cal;
	CCommon common;
	CFiles file;
	CPicture picture;
	int sNum;
	int mapW;
	int mapH;
	int cursorX;
	int cursorY;
	int checkx[4];
	int checky[4];
	int displayX;
	int displayY;
	bool target[20][20];
	bool Ctarget[20][20];
	bool Rtarget[20][20];
	bool town[20][20];
	bool SCtarget[20][20];
	bool SRtarget[20][20];
	int townOwner[20][20];
	bool range_attack;
	void SetTarget();
	void Combat();
	void Ranged();
	void Siege();
	bool besiege;
	int tDamage;
	int LocationX(int country,int unit);
	int LocationY(int country,int unit);
	void CheckSelecting();
	int selectingC;
	int selectingU;
	bool Selecting();
	int GetHP(int country,int unit);
	int GetStrength(int country,int unit);
	int GetRStrength(int country,int unit);
	int GetRange(int country, int unit);
	int AtkDam;
	int DefDam;
	double index;
	int Attack(int base /*ダメージの基礎値*/,int atkC,int atkU,int defC,int defU);
	int FightTown(int type,int base,int power,int unitC,int unitU);
	void Damage(int country,int unit,int damage);
	bool Dead(int country,int unit);
	bool Enemy(int country); //敵ならばtrue
	bool CheckCOnUnit(int country,int unit);
	bool CheckCOnTown(int type);

public:
	CCursorManager cursorm;
	CUnitManager unitm;
	CTurn turn;
	CBattle();
	void Awake(int stage);
	bool GetBesiege();
	int GetTDamage();
	void SetTownOwner(int x,int y,int owner);
	void Battle();

};
