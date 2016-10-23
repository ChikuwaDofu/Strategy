#pragma once

#include"Suken.h"
#include"Files.h"

//enum SaveData{}
//	ghjk,
//	sEnd
//;



class CSaveData{
private:
	CFiles file;
	int turnNum;
	int turnCountry;
	int unitLocX[5][20];
	int unitLocY[5][20];
	int unitMoves[5][20];
	int unitPrepare[5][20];
	int unitType[5][20];
	int unitAttacked[5][20];
	int unitHP[5][20];
	int countryMoney[5];
	int townOwner[20][20];
	int townHP[20][20];

	void Write(int stage);
	
public:
	CData *data;

	CSaveData(int stage);

	friend void WriteSave(int stage);
	friend void DeleteSave();
	friend void LoadSave(int stage);

	friend int GetTurnNum();
	friend int GetTurnCountry();
	friend int GetUnitX(int country, int unit);
	friend int GetUnitY(int country, int unit);
	friend int GetUnitMove(int country, int unit);
	friend int GetUnitPrepare(int country, int unit);
	friend int GetUnitType(int country, int unit);
	friend int GetUnitAttacked(int country, int unit);
	friend int GetUnitHP(int country, int unit);
	friend int GetCountryMoney(int country);
	friend int GetOwner(int x, int y);
	friend int GetTHP(int x, int y);

	friend void SetTurnNum(int tNum);
	friend void SetTurnCountry(int tCountry);
	friend void SetUnitX(int country, int unit, int x);
	friend void SetUnitY(int country, int unit, int y);
	friend void SetUnitMove(int country, int unit, int moves);
	friend void SetUnitPrepare(int country, int unit, bool prepared);
	friend void SetUnitType(int country, int unit, int type);
	friend void SetUnitAttacked(int country, int unit, bool attacked);
	friend void SetUnitHP(int country, int unit, int uHp);
	friend void SetCountryMoney(int country, int money);
	friend void SetTownOwner(int x, int y, int tOwner);
	friend void SetTownHP(int x, int y, int tHp);
	//int Get(SaveData num);
};
