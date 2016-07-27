#include"DxLib.h"
#include"Unit.h"
#include<queue>
using namespace std;
typedef pair<int,int>P;
queue<P>Q;
P now,Next;
int Dx[4]={0,1,0,-1};
int Dy[4]={1,0,-1,0};

int Array2D(int x,int y){
	return 19*x + y ;
}

CUnit::CUnit(){
	type=1;
	hp=100;
	strength=5;
	siege = false;
	prepared = true;

	unitX=-100;
	unitY=-100;
}

int CUnit::Gettype(){
	return type;
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

int CUnit::Getstrength(){
	return strength;
}

int CUnit::GetSstrength(){
	return shotstrength;
}

int CUnit::Gethp(){
	return hp;
}

bool CUnit::GetMoveEnd(){
	return MoveEnd;
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
	moves=2;
}

void CUnit::SetPrepared(bool prepare){
	if (type == 4){
		prepared = prepare;
	}
}

void CUnit::Awake(int _x,int _y,int _type){
	unitX=_x;
	unitY=_y;
	type=_type;

	switch(type){
	case 1:

		strength=9;
		shotstrength=0;

		break;

	case 2:

		strength=5;
		shotstrength=10;

		break;

	case 4:

		strength = 4;
		shotstrength = 15;
		siege = true;
		prepared = false;

		break;
	}
	
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

void CUnit::CheckMoveable(){
	for(int x=0;x<MAP_W;x++){
		for(int y=0;y<MAP_H;y++){
			route[x][y]=0;
			if(moves >= table[Array2D(unitX-x+9,unitY-y+9)] && Array2D(unitX-x+9,unitY-y+9) > 0 && Array2D(unitX-x+9,unitY-y+9)<361 ){
				route[x][y]=1;
			}
		}
	}
	/*
	Q.push(now);
	while(!Q.empty()){
		now=Q.front();
		Q.pop();
		for(int j=0;j<4;j++){
			Next.first=now.first+Dx[j];
			Next.second=now.second+Dy[j];
			if(route[Next.first][Next.second]>route[now.first][now.second]){
				if(Next.first>=0 && Next.first<=13 && Next.second>=0 && Next.second<=9 && route[now.first][now.second]<moves){
					route[Next.first][Next.second]=route[now.first][now.second]+1;
					able[Next.first][Next.second]=true;
					Q.push(Next);
				}else{
					able[Next.first][Next.second]=false;
				}
			}
		}
	}*/
}

void CUnit::SetObstacle(int _x,int _y){
	route[_x][_y]=2;
}

int CUnit::GetRoute(int _x,int _y){
	return route[_x][_y];
}

void CUnit::Move(int dir){
	moved=true;

	moves--;

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

void CUnit::Product(int _x,int _y,int _type){
	hp=100;
	moves=0;
	MoveEnd=true;
	Awake(_x,_y,_type);
}

void CUnit::DrawUnit(int _country){
	DrawGraph(unitX * 50 + 100, unitY * 50 + 50, picture.unitPic[type - 1], true);
	DrawGraph(unitX * 50 + 125, unitY * 50 + 75, picture.flagPic[_country], true);

	if (hp < 100){
		DrawGraph(unitX * 50 + 102, unitY * 50 + 77, picture.numPic[hp / 10], true);
		DrawGraph(unitX * 50 + 112, unitY * 50 + 77, picture.numPic[hp % 10], true);
	}

	if (type == 4){
		if (prepared){
			DrawGraph(unitX * 50 + 125, unitY * 50 + 50, picture.siegepic[1],true);
		}
		else{
			DrawGraph(unitX * 50 + 125, unitY * 50 + 50, picture.siegepic[0], true);
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
