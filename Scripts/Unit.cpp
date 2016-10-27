#include"DxLib.h"
#include"Unit.h"
#include"Savedata.h"

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

bool CUnit::GetAttacked(){
	return attacked;
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
	MoveEnd=false;
	moves = file.move[unitType];
}

void CUnit::SetPrepared(bool prepare){
	if (siege){
		prepared = prepare;
	}
}

void CUnit::SetAttacked(bool hadAttacked){
	attacked = hadAttacked;
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

	attacked = false;
	
	picture.LoadUnitPic();
	picture.LoadNumPic();
	picture.LoadFlagPic();
}

void CUnit::SkipTurn(){
	if(!Moved() && !MoveEnd){
		if(hp<=90){
			Recover(10);
		}else{
			hp=100;
		}
	}

	SetMoves();

	SetAttacked(false);
}

void CUnit::SetObstacle(int x,int y,int type){
	obstacle[x][y] = type;
}

int CUnit::GetObstacle(int x, int y){
	return obstacle[x][y];
}

void CUnit::Move(int dir, int cost){
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

	if(dir!=0){
		switch(unitType){
		case 1:
		case 2:
		case 6:
		case 7:

			music->AddSound(sMarch);

			break;

		case 3:
		case 4:
		case 5:

			music->AddSound(sHorse);

			break;

		case 8:
		case 9:
		case 10:

			music->AddSound(sWheel);

			break;
		}
	}
}

bool CUnit::Moved(){
	if(moves==file.move[unitType]){
		return false;
	}else{
		return true;
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
	Awake(x, y, type);
	hp = 100;
	moves = 0;
	MoveEnd = true;
}

void CUnit::DrawUnit(int country, int stage, int adjX, int adjY){

	displayX = unitX - adjX;
	displayY = unitY - adjY;

	if (displayX >= 0 && displayX < MAP_W && displayY >= 0 && displayY < MAP_H){

		DrawGraph(displayX * 50 + 100, displayY * 50 + 50, picture.unitPic[unitType - 1], true);
		DrawGraph(displayX * 50 + 125, displayY * 50 + 75, picture.flagPic[country], true);

		if (hp < 100){
			DrawGraph(displayX * 50 + 102, displayY * 50 + 77, picture.numPic[hp / 10], true);
			DrawGraph(displayX * 50 + 112, displayY * 50 + 77, picture.numPic[hp % 10], true);
		}

		if (siege){
			if (prepared){
				DrawGraph(displayX * 50 + 125, displayY * 50 + 60, picture.siegepic[1], true);
			}
			else{
				DrawGraph(displayX * 50 + 125, displayY * 50 + 60, picture.siegepic[0], true);
			}
		}
	}
}

void CUnit::DrawMoves(){
	if (displayX >= 0 && displayX < MAP_W && displayY >= 0 && displayY < MAP_H){
		for (int i = 1; i <= 4; i++){
			if (moves >= i){
				DrawGraph(displayX * 50 + 140, displayY * 50 + 51 + (i - 1) * 4, picture.move[i], true);
			}
		}

		if(!MoveEnd && prepared && !attacked){
			DrawGraph(displayX * GRID_L + 115, displayY * GRID_L + 65, picture.attackable, true);
		}
	}
}

void CUnit::DrawHeal(){
	if (displayX >= 0 && displayX < MAP_W && displayY >= 0 && displayY < MAP_H){
		if (!Moved() && !MoveEnd){
			DrawGraph(displayX * 50 + 125, displayY * 50 + 50, picture.heal, true);
		}
	}
}

void CUnit::Load(int country, int unit){
	picture.LoadUnitPic();
	picture.LoadNumPic();
	picture.LoadFlagPic();

	unitX=GetUnitX(country,unit);
	unitY=GetUnitY(country,unit);
	moves=GetUnitMove(country,unit);
	prepared=GetUnitPrepare(country,unit);
	attacked=GetUnitAttacked(country,unit);
	unitType=GetUnitType(country,unit);
	hp=GetUnitHP(country,unit);

	strength = file.strength[unitType];
	r_strength = file.rangedStrength[unitType];
	s_strength = file.siegeStrength[unitType];
	siege = file.siege[unitType];
	moves = file.move[unitType];
	range = file.range[unitType];

	if(moves==0){
		MoveEnd=true;
	}
}
