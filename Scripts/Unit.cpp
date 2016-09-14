#include"DxLib.h"
#include"Unit.h"


int Array2D(int x,int y){
	return 19*x + y ;
}

CUnit::CUnit(){
	file.LoadUnitFile();

	unitType = 1;
	hp=100;
	strength=5;
	siege = false;
	prepared = true;

	unitX=-100;
	unitY=-100;

	for (int x = 0; x < MAP_W; x++){
		for (int y = 0; y < MAP_H; y++){
			obstacle[x][y] = 0;
		}
	}
}

int CUnit::Gettype(){
	return unitType;
}

int CUnit::GetunitX(){
	return unitX;
}

int CUnit::GetunitY(){
	return unitY;
}

int CUnit::GetMoves(){
	return moves;
}

int CUnit::GetRange(){
	return range;
}

int CUnit::Getstrength(){
	return strength;
}

int CUnit::GetRstrength(){
	return r_strength;
}

int CUnit::GetSstrength(){
	return s_strength;
}

int CUnit::Gethp(){
	return hp;
}

bool CUnit::GetMoveEnd(){
	return MoveEnd;
}

bool CUnit::IsSiege(){
	return siege;
}

bool CUnit::GetPrepared(){
	return prepared;
}

void CUnit::Setunit(){
	unitX=-100;
	unitY=-100;
}

void CUnit::SetMoves(){
	moved=false;
	MoveEnd=false;
	moves = file.move[unitType];
}

void CUnit::SetPrepared(bool prepare){
	if (siege){
		prepared = prepare;
	}
}

void CUnit::Awake(int x,int y,int type){
	unitX=x;
	unitY=y;
	unitType=type;

	strength = file.strength[type];
	r_strength = file.rangedStrength[type];
	s_strength = file.siegeStrength[type];
	siege = file.siege[type];
	moves = file.move[type];
	range = file.range[type];
	
	picture.LoadUnitPic();
	picture.LoadNumPic();
	picture.LoadFlagPic();
}

void CUnit::SkipTurn(){
	if(!moved && !MoveEnd){
		if(hp<=90){
			Recover(10);
		}else{
			hp=100;
		}
	}

	SetMoves();

}

void CUnit::SetObstacle(int x,int y,int type){
	obstacle[x][y] = type;
}

int CUnit::GetObstacle(int x, int y){
	return obstacle[x][y];
}

void CUnit::Move(int dir, int cost){
	moved=true;

	moves -= cost;

	if (moves < 0){
		moves = 0;
	}

	if(dir==RIGHT){
		unitX++;
	}
	if(dir==LEFT){
		unitX--;
	}
	if(dir==DOWN){
		unitY++;
	}
	if(dir==UP){
		unitY--;
	}
}

void CUnit::SetMoveEnd(){
	MoveEnd=true;
}

void CUnit::MakeMoveEnd(){
	SetMoveEnd();
	moves=0;
}

void CUnit::Damage(int d){
	hp-=d;
}

void CUnit::Recover(int r){
	hp+=r;
}

void CUnit::Death(){
	unitX=-100;
	unitY=-100;
}

void CUnit::Survive(){
	if(hp<=0){
		hp=1;
	}
}

void CUnit::Product(int x,int y,int type){
	hp=100;
	moves=0;
	MoveEnd=true;
	Awake(x,y,type);
}

void CUnit::DrawUnit(int country){
	DrawGraph(unitX * 50 + 100, unitY * 50 + 50, picture.unitPic[unitType - 1], true);
	DrawGraph(unitX * 50 + 125, unitY * 50 + 75, picture.flagPic[country], true);

	if (hp < 100){
		DrawGraph(unitX * 50 + 102, unitY * 50 + 77, picture.numPic[hp / 10], true);
		DrawGraph(unitX * 50 + 112, unitY * 50 + 77, picture.numPic[hp % 10], true);
	}

	if (unitType == 3){
		if (prepared){
			DrawGraph(unitX * 50 + 125, unitY * 50 + 60, picture.siegepic[1],true);
		}
		else{
			DrawGraph(unitX * 50 + 125, unitY * 50 + 60, picture.siegepic[0], true);
		}
	}
}

void CUnit::DrawMoves(){
	for (int i = 1; i <= 4; i++){
		if (moves >= i){
			DrawGraph(unitX * 50 + 140, unitY * 50 + 51 + (i - 1) * 4, picture.move[i], true);
		}
	}
}

void CUnit::DrawHeal(){
	if (!moved && !MoveEnd){
		DrawGraph(unitX * 50 + 125, unitY * 50 + 50, picture.heal, true);
	}
}
