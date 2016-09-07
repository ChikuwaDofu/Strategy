#pragma once

#include"Suken.h"
#include"Unit.h"
#include"Cursor.h"
#include"Country.h"
#include"UnitManager.h"

class CBattle{
private:
	CCal cal;
	CCommon common;
	CTurn turn;
	int cursorX;
	int cursorY;
	int checkx[4];
	int checky[4];
	bool target[MAP_W][MAP_H];
	bool Ctarget[MAP_W][MAP_H];
	bool Rtarget[MAP_W][MAP_H];
	bool town[MAP_W][MAP_H];
	bool SCtarget[MAP_W][MAP_H];
	bool SRtarget[MAP_W][MAP_H];
	int townOwner[MAP_W][MAP_H];
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
	bool CheckRCOnUnit(int country,int unit);
	bool CheckRCOnTown(int type);

public:
	CCursorManager cursorm;
	CUnitManager unitm;
	CBattle();
	bool GetBesiege();
	int GetTDamage();
	void SetTownOwner(int x,int y,int owner);
	void Battle();

};
