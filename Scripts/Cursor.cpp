#include"DxLib.h"
#include"Suken.h"
#include"Cursor.h"
#include"General.h"

void CCursor::Setc(){
	for(int i=0;i<900/GRID_L;i++){
		for(int j=0;j<600/GRID_L;j++){
			if(mousex==i*GRID_L){
				cursorX=-1;
			}
			if(mousey==j*GRID_L){
				cursorY=-1;
			}
			if(mousex>i*GRID_L && mousex<(i+1)*GRID_L && mousey>j*GRID_L && mousey<(j+1)*GRID_L){
				cursorX=i-2;
				cursorY=j-1;
			}
		}
	}
}

void CCursor::Setm(){
	GetMousePoint(&mousex,&mousey);
}

int CCursor::Getcx(){
	return cursorX;
}

int CCursor::Getcy(){
	return cursorY;
}

int CCursor::Getmx(){
	return mousex;
}

int CCursor::Getmy(){
	return mousey;
}

void CCursorManager::SetCursor(){
	cursor.Setm();
	cursor.Setc();
}

void CCursorManager::PaintCursor(){
	if(cursor.Getcx()>=0 && cursor.Getcx()<MAP_W && cursor.Getcy()>=0 && cursor.Getcy()<MAP_H)
	DrawBox((cursor.Getcx()+2)*GRID_L+2,(cursor.Getcy()+1)*GRID_L+2,(cursor.Getcx()+3)*GRID_L-1,(cursor.Getcy()+2)*GRID_L-1,RED,false);
}

void CCursorManager::DrawCursor(){
	SetCursor();
	PaintCursor();
}
