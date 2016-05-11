#pragma once

#include"Suken.h"

class CCursor{
private:
	int mousex;
	int mousey;
	int cursorX;
	int cursorY;

public:
	void Setc();
	void Setm();
	int Getcx();
	int Getcy();
	int Getmx();
	int Getmy();

};

class CCursorManager{
private:
	void SetCursor();
	void PaintCursor();

public:
	CCursor cursor;
	void DrawCursor();

};
