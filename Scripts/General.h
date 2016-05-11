#pragma once

#include"DxLib.h"
#include"Suken.h"

const int GRID_L = 50;
const int MAP_W = 700/GRID_L;//700‚Æ500‚ÌŒö–ñ”
const int MAP_H = 500/GRID_L;//2,2,5,5‚ğ‘g‚İ‡‚í‚¹‚é
const int UNIT_NUM = 2;
const int COUNTRY_NUM = 2;
const int RIGHT = 1;
const int LEFT = 2;
const int DOWN = 3;
const int UP = 4;
const int COMBAT = 22;
const int SHOT = 12;
const int NONE = 0;
const int PLAIN = 1;
const int RIVER = 2;

class CTurn{
private:
	int turn;
	bool skip;

public:
	void SkipTurn();
	bool Getskip();

};

class CCal{
public:
	int Absolute(int a);//â‘Î’l

};

class CCommon{
private:
	bool rclick;

public:
	void CheckRClick();
	bool GetOnRClick();
	int GetNumKey();
	int CheckArrow();
}; 