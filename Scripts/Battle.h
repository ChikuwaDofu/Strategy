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
	int checkx[4];
	int checky[4];
	bool target[MAP_W][MAP_H];
	bool Ctarget[MAP_W][MAP_H];
	bool Starget[MAP_W][MAP_H];
	bool range_attack;
	void SetTarget();
	void Combat();
	void Shot();
	int LocationX(int _country,int _unit);
	int LocationY(int _country,int _unit);
	void CheckSelecting();
	int selectingC;
	int selectingU;
	bool Selecting();
	int GetHP(int _country,int _unit);
	int GetStrength(int _country,int _unit);
	int GetSStrength(int _country,int _unit);
	int AtkDam;
	int DefDam;
	double index;
	int Attack(int base /*ダメージの基礎値*/,int atkC,int atkU,int defC,int defU);
	void Damage(int _country,int _unit,int _damage);
	bool Dead(int _country,int _unit);
	bool Enemy(int _country); //敵ならばtrue
	bool CheckRCOn(int _country,int _unit);

public:
	CCursorManager cursorm;
	CUnitManager unitm;
	CBattle();
	void Battle();

};
