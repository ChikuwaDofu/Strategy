#include"DxLib.h"
#include"UnitManager.h"

CUnitManager::CUnitManager(){
	selectingC=0;
	selectingU=0;
}

void CUnitManager::Awake(){
	SetUnit();
	country[1].unit[1].Awake(6,4,1);
	country[1].unit[2].Awake(5,3,2);
	country[2].unit[1].Awake(7,5,1);
	country[2].unit[2].Awake(8,6,2);

	picture.LoadUnitmPic();
	picture.LoadFlagPic();

	selectingC=1;
}

void CUnitManager::SetUnit(){
	for(int i=1;i<=COUNTRY_NUM;i++){
		for(int n=1;n<=UNIT_NUM;n++){
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
	if(Event.LMouse.GetClick(GetX(_country,_unit)*50+100,GetY(_country,_unit)*50+50,GetX(_country,_unit)*50+150,GetY(_country,_unit)*50+100)){
		return true;
	}else{
		return false;
	}
}

void CUnitManager::Select(int _unit){
	selectingU=_unit;
}

void CUnitManager::ProductScr(bool open1,bool open2){
	if(open1 || open2){
		screen = true;
	}else{
		screen = false;
	}
}

void CUnitManager::Setselecting(){
	
	cursor.Setm();
	cursor.Setc();
	
	if(Event.LMouse.GetClick(0,0,WINDOW_WIDTH,WINDOW_HEIGHT)){
		Select(0);
		for(int n=1;n<=UNIT_NUM;n++){
			if(CheckLCOn(selectingC,n) && !country[selectingC].unit[n].GetMoveEnd() && !screen){
				Select(n);
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
	if(selectingU==0){
		return false;
	}else{
		return true;
	}
}

int CUnitManager::GetselectingU(){
	return selectingU;
}

void CUnitManager::MoveUnit(){

	if(Event.key.GetDown(Event.key.RETURN)){
		DrawString(5,300,"pass",RED);

			for(int n=1;n<=UNIT_NUM;n++){
				country[selectingC].unit[n].SkipTurn();

				Select(0);
			}
	}
	
	turn.SkipTurn();

	if(turn.Getskip()){
		selectingC=turn.GetCountry();
	}

	if(Selecting()){
		for(int i=1;i<=COUNTRY_NUM;i++){
			for(int n=1;n<=UNIT_NUM;n++){
				country[selectingC].unit[selectingU].SetObstacle(GetX(i,n),GetY(i,n));
			}
		}
		if(country[selectingC].unit[selectingU].GetMoves()>0){
			for(int j=1;j<=COUNTRY_NUM;j++){
				for(int n=1;n<=UNIT_NUM;n++){
					if(selectingU!=n){
						country[selectingC].unit[selectingU].SetObstacle(GetX(j,n),GetY(j,n));
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
		Select(0);
	}
}

void CUnitManager::PaintUnit(){

	for(int i=1;i<=COUNTRY_NUM;i++){
		for(int n=1;n<=UNIT_NUM;n++){
			if(country[i].unit[n].GetMoveEnd()){
				DrawBox(GetX(i,n)*GRID_L+100,GetY(i,n)*GRID_L+50,(GetX(i,n)+1)*GRID_L+100,(GetY(i,n)+1)*GRID_L+50,YELLOW,true);
			}else{
				DrawBox(GetX(i,n)*GRID_L+100,GetY(i,n)*GRID_L+50,(GetX(i,n)+1)*GRID_L+100,(GetY(i,n)+1)*GRID_L+50,BLUE,true);
			}
		}
	}

	if(Selecting()){
		country[selectingC].unit[selectingU].CheckMoveable();

		for(int x=0;x<MAP_W;x++){
			for(int y=0;y<MAP_H;y++){
				if(country[selectingC].unit[selectingU].GetRoute(x,y)==1){
					DrawGraph(x*GRID_L + 102, y*GRID_L + 52, picture.RangeBox, true);
				}
			}
		}

		DrawBox(GetX(selectingC,selectingU)*GRID_L+100,GetY(selectingC,selectingU)*GRID_L+50,GRID_L+GetX(selectingC,selectingU)*GRID_L+100,GRID_L+GetY(selectingC,selectingU)*GRID_L+50,GREEN,true);
	}

	for(int i=1;i<=COUNTRY_NUM;i++){
		for(int n=1;n<=UNIT_NUM;n++){
			//DrawFormatString(country[i].unit[n].GetunitX()*GRID_L+GRID_L/2-2+100,country[i].unit[n].GetunitY()*GRID_L+GRID_L/2-5+50,WHITE,"%d",country[i].unit[n].Gettype());
			//DrawFormatString(country[i].unit[n].GetunitX()*GRID_L+GRID_L/2-2+100,country[i].unit[n].GetunitY()*GRID_L+GRID_L/2+15+50,BLACK,"%d",country[i].unit[n].Gethp());
			country[i].unit[n].DrawUnit(i);
		}
	}
}

void CUnitManager::Moveend(){
	country[selectingC].unit[selectingU].MakeMoveEnd();

	Select(0);
}

void CUnitManager::DrawUnit(){

	Setselecting();
	PaintUnit();
	
	DrawFormatString(30,30,GREEN,"%d %d",cursor.Getcx(),cursor.Getcy());
	DrawFormatString(30,50,GREEN,"%d %d",cursor.Getmx(),cursor.Getmy());
	
	DrawFormatString(5,5,GREEN,"%d,%d",selectingC,selectingU);
}
