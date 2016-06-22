#include"DxLib.h"
#include"UnitManager.h"

CUnitManager::CUnitManager(){
	selectingC=-1;
	selectingU=-1;
}

void CUnitManager::Awake(){
	SetUnit();
	country[0].unit[0].Awake(6,4,1);
	country[0].unit[1].Awake(5,3,2);
	country[1].unit[0].Awake(7,5,1);
	country[1].unit[1].Awake(8,6,2);

	picture.LoadUnitmPic();
}

void CUnitManager::SetUnit(){
	for(int i=0;i<COUNTRY_NUM;i++){
		for(int n=0;n<UNIT_NUM;n++){
			country[i].unit[n].Setunit();
			country[i].unit[n].SetMoves();
		}
	}
}

int CUnitManager::GetX(int _country,int _unit){
	return country[_country].unit[_unit].GetunitX();
}

int CUnitManager::GetY(int _country,int _unit){
	return country[_country].unit[_unit].GetunitY();
}

int CUnitManager::GetRoute(int _country,int _unit,int _x,int _y){
	return country[_country].unit[_unit].GetRoute(_x,_y);
}

bool CUnitManager::CheckLCOn(int _country,int _unit){
	if(Event.LMouse.GetClick(country[_country].unit[_unit].GetunitX()*50+100,country[_country].unit[_unit].GetunitY()*50+50,country[_country].unit[_unit].GetunitX()*50+150,country[_country].unit[_unit].GetunitY()*50+100)){
		return true;
	}else{
		return false;
	}
}

void CUnitManager::Select(int _country,int _unit){
	selectingC=_country;
	selectingU=_unit;
}

void CUnitManager::ProductScr(bool open){
	screen = open;
}

void CUnitManager::Setselecting(){
	cursor.Setm();
	cursor.Setc();
	
	if(Event.LMouse.GetClick(0,0,WINDOW_WIDTH,WINDOW_HEIGHT)){
		Select(-1,-1);
		for(int i=0;i<COUNTRY_NUM;i++){
			for(int n=0;n<UNIT_NUM;n++){
				if(CheckLCOn(i,n) && !country[i].unit[n].GetMoveEnd() && !screen){
					Select(i,n);
				}
			}
		}
	}
}

bool CUnitManager::Moveable(int dir){
	switch(dir){
	case UP:
		if(GetY(selectingC,selectingU)>0 && GetRoute(selectingC,selectingU,GetX(selectingC,selectingU),GetY(selectingC,selectingU)-1)==1){
			return true;
		}else{
			return false;
		}

		break;

	case DOWN:
		if(GetY(selectingC,selectingU)<MAP_H && GetRoute(selectingC,selectingU,GetX(selectingC,selectingU),GetY(selectingC,selectingU)+1)==1){
			return true;
		}else{
			return false;
		}

		break;

	case LEFT:
		if(GetX(selectingC,selectingU)>0 && GetRoute(selectingC,selectingU,GetX(selectingC,selectingU)-1,GetY(selectingC,selectingU))==1){
			return true;
		}else{
			return false;
		}

		break;

	case RIGHT:
		if(GetX(selectingC,selectingU)<MAP_W && GetRoute(selectingC,selectingU,GetX(selectingC,selectingU)+1,GetY(selectingC,selectingU))==1){
			return true;
		}else{
			return false;
		}

		break;

		default:
			return false;
	}
}

void CUnitManager::Move(){
	switch(common.CheckArrow()){
	case UP:
		country[selectingC].unit[selectingU].Move(UP);

	break;

	case DOWN:
		country[selectingC].unit[selectingU].Move(DOWN);

	break;

	case LEFT:
		country[selectingC].unit[selectingU].Move(LEFT);

	break;

	case RIGHT:
		country[selectingC].unit[selectingU].Move(RIGHT);

	break;
	}

	if(common.CheckArrow()!=0){
		onemove=true;
	}
}

bool CUnitManager::Selecting(){
	if(selectingC==-1){
		return false;
	}else{
		return true;
	}
}

int CUnitManager::GetselectingC(){
	return selectingC;
}

int CUnitManager::GetselectingU(){
	return selectingU;
}

void CUnitManager::MoveUnit(){

	turn.SkipTurn();

	if(turn.Getskip() == true){
		DrawString(5,300,"pass",RED);

		for(int i=0;i<COUNTRY_NUM;i++){
			for(int n=0;n<UNIT_NUM;n++){
				country[i].unit[n].SkipTurn();

				Select(-1,-1);
			}
		}
	}

	if(Selecting()){
		for(int i=0;i<COUNTRY_NUM;i++){
			for(int n=0;n<UNIT_NUM;n++){
				country[selectingC].unit[selectingU].SetObstacle(country[i].unit[n].GetunitX(),country[i].unit[n].GetunitY());
			}
		}
		if(country[selectingC].unit[selectingU].GetMoves()>0){
			for(int j=0;j<COUNTRY_NUM;j++){
				for(int n=0;n<UNIT_NUM;n++){
					if(selectingU!=n){
						country[selectingC].unit[selectingU].SetObstacle(country[j].unit[n].GetunitX(),country[j].unit[n].GetunitY());
					}
					for(int x=0;x<MAP_W;x++){
						for(int y=0;y<MAP_H;y++){
							if(country[selectingC].unit[selectingU].GetRoute(x,y) && !onemove){
								if(Moveable(common.CheckArrow())){
									Move();
								}

								if(country[selectingC].unit[selectingU].GetMoves()==0){
									country[selectingC].unit[selectingU].SetMoveEnd();
								}
								//
								DrawFormatString(5,30+selectingU*30,RED,"%d",country[selectingC].unit[selectingU].GetMoves());
							}
						}
					}
				}
			}
		}

		onemove=false;
	}
	if(country[selectingC].unit[selectingU].GetMoveEnd()){
		Select(-1,-1);
	}
}

void CUnitManager::PaintUnit(){

	for(int i=0;i<COUNTRY_NUM;i++){
		for(int n=0;n<UNIT_NUM;n++){
			if(country[i].unit[n].GetMoveEnd()){
				DrawBox(country[i].unit[n].GetunitX()*GRID_L+100,country[i].unit[n].GetunitY()*GRID_L+50,GRID_L+country[i].unit[n].GetunitX()*GRID_L+100,GRID_L+country[i].unit[n].GetunitY()*GRID_L+50,YELLOW,true);
			}else{
				DrawBox(country[i].unit[n].GetunitX()*GRID_L+100,country[i].unit[n].GetunitY()*GRID_L+50,GRID_L+country[i].unit[n].GetunitX()*GRID_L+100,GRID_L+country[i].unit[n].GetunitY()*GRID_L+50,BLUE,true);
			}
		}
	}

	if(Selecting()){
		country[selectingC].unit[selectingU].CheckMoveable();

		for(int x=0;x<MAP_W;x++){
			for(int y=0;y<MAP_H;y++){
				if(country[selectingC].unit[selectingU].GetRoute(x,y)==1){
					//DrawBox(x*GRID_L+102,y*GRID_L+52,GRID_L+x*GRID_L+99,GRID_L+y*GRID_L+49,LIGHTBLUE,true);
					DrawGraph(x*GRID_L + 102, y*GRID_L + 52, picture.RangeBox, true);
				}
			}
		}

		DrawBox(country[selectingC].unit[selectingU].GetunitX()*GRID_L+100,country[selectingC].unit[selectingU].GetunitY()*GRID_L+50,GRID_L+country[selectingC].unit[selectingU].GetunitX()*GRID_L+100,GRID_L+country[selectingC].unit[selectingU].GetunitY()*GRID_L+50,GREEN,true);
	}

	for(int i=0;i<COUNTRY_NUM;i++){
		for(int n=0;n<UNIT_NUM;n++){
			//DrawFormatString(country[i].unit[n].GetunitX()*GRID_L+GRID_L/2-2+100,country[i].unit[n].GetunitY()*GRID_L+GRID_L/2-5+50,WHITE,"%d",country[i].unit[n].Gettype());
			//DrawFormatString(country[i].unit[n].GetunitX()*GRID_L+GRID_L/2-2+100,country[i].unit[n].GetunitY()*GRID_L+GRID_L/2+15+50,BLACK,"%d",country[i].unit[n].Gethp());
			country[i].unit[n].DrawUnit();
		}
	}
}

void CUnitManager::Moveend(){
	country[selectingC].unit[selectingU].MakeMoveEnd();

	Select(-1,-1);
}

void CUnitManager::DrawUnit(){
	
	Setselecting();
	PaintUnit();
	
	DrawFormatString(30,30,GREEN,"%d %d",cursor.Getcx(),cursor.Getcy());
	DrawFormatString(30,50,GREEN,"%d %d",cursor.Getmx(),cursor.Getmy());
	
	DrawFormatString(5,5,GREEN,"%d,%d",selectingC,selectingU);
}
