#include"DxLib.h"
#include"Suken.h"
#include"Back.h"
#include"General.h"

void CBack::DrawLine(){
	for(int i=100 ; i<=800 ; i+=GRID_L){
		DrawBox(i,50,i+1,551,WHITE,true);
	}
	for(int i=50 ; i<=550 ; i+=GRID_L){
		DrawBox(100,i,800,i+1,WHITE,true);
	}
}

