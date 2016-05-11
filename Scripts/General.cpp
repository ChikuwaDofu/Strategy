#include"DxLib.h"
#include"Suken.h"
#include"General.h"

void CTurn::SkipTurn(){
	if(skip){
		DrawFormatString(5,200,GetColor(255,255,255),"%d",turn);
	}else DrawFormatString(5,220,GetColor(255,255,255),"turn");

	skip=false;

	if(Event.key.GetDown(Event.key.RETURN)){
		turn++;
		skip=true;
	}
	
}

bool CTurn::Getskip(){
	return skip;
}

int CCal::Absolute(int a){
	if(a<0){
		return -a;
	}else{
		return a;
	}
}

void CCommon::CheckRClick(){
	rclick=false;
	if(GetMouseInput()&MOUSE_INPUT_RIGHT){
		rclick=true;
	}
}

bool CCommon::GetOnRClick(){
	if(GetMouseInput()&MOUSE_INPUT_RIGHT && !rclick){
		return true;
	}else{
		return false;
	}
}

int CCommon::GetNumKey(){
	if(Event.key.GetDown(Event.key.NUM0)){
		return 0;
	}else{
		if(Event.key.GetDown(Event.key.NUM1)){
			return 1;
		}else{
			return -1;
		}
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
