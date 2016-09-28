#include"DxLib.h"
#include"Suken.h"
#include"General.h"

void CTurn::Awake(){
	country=1;
	turn=1;
}

void CTurn::SkipTurn(){
	if(turn<10){
		DrawFormatString(810,25,GetColor(255,255,255),"  %d",turn);
	}

	if(turn>=10 && turn<100){
		DrawFormatString(810,25,GetColor(255,255,255)," %d",turn);
	}

	if(turn>=100){
		DrawFormatString(810,25,GetColor(255,255,255),"%d",turn);
	}

	skip=false;

	if(Event.key.GetDown(Event.key.RETURN)){
		if(country==COUNTRY_NUM){
			turn++;
			country=1;
		}else{
			country++;
		}

		skip=true;
	}
}

bool CTurn::Getskip(){
	return skip;
}

int CTurn::GetCountry(){
	return country;
}

int CCal::Absolute(int a){
	if(a<0){
		return -a;
	}else{
		return a;
	}
}

void CDraw::DrawNumber(int x,int y,int color,int num){
	if(num>=100){
	DrawFormatString(x,y,color,"%d",num);
	}else if(num>=10){
		DrawFormatString(x,y,color," %d",num);
	}else{
		DrawFormatString(x,y,color,"  %d",num);
	}
}

int CCommon::CheckArrow(){
	if(Event.key.GetDown(Event.key.UP)){
		return UP;
	}
	if(Event.key.GetDown(Event.key.DOWN)){
		return DOWN;
	}
	if(Event.key.GetDown(Event.key.LEFT)){
		return LEFT;
	}
	if(Event.key.GetDown(Event.key.RIGHT)){
		return RIGHT;
	}
	return 0;
}
