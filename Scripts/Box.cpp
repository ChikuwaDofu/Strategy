#include"DxLib.h"
#include"Suken.h"
#include"Box.h"
#include"Cursor.h"
#include"General.h"
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
}

int CUnit::GetWidth(){
	return width;
}

int CUnit::GetHeight(){
	return height;
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

bool CUnit::GetSelected(){
	return selected;
}

bool CUnit::GetMoveEnd(){
	return MoveEnd;
}

bool CUnit::Getmoving(){
	return moving;
}

void CUnit::SetWidth(){
	width=GRID_L;
}

void CUnit::SetHeight(){
	height=GRID_L;
}

void CUnit::SetunitX(){
	unitX=0;
}

void CUnit::SetunitY(){
	unitY=0;
}

void CUnit::SetMoves(){
	MoveEnd=false;
	moves=2;
}

void CUnit::Awake(int _x,int _y,int _type,int _str,int _Rstr){
	unitX=_x;
	unitY=_y;
	type=_type;
	strength=_str;
	shotstrength=_Rstr;

}

void CUnit::CheckSelected(){
	cursor.Setm();
	cursor.Setc();

	if(GetMouseInput()&MOUSE_INPUT_LEFT && !lclick){
		if(cursor.Getcx()==unitX && cursor.Getcy()==unitY){
			if(!selected && !MoveEnd){
				selected=true;
			}
		}else{
			selected=false;
		}
	}

	if(GetMouseInput()&MOUSE_INPUT_LEFT){
		lclick=true;
	}else{
		lclick=false;
	}

	/*if(!selected){
		turn.SkipTurn();
	}*/

}

void CUnit::SkipTurn(){
	SetMoves();
}

void CUnit::SetMoveable(){
	for(int k=0;k<UNIT_NUM;k++){
		for(int i=0;i<20;i++){
			for(int j=0;j<20;j++){
				able[i][j]=false;
			}
		}
	}
}

bool CUnit::Getable(int _x,int _y){
	return able[_x][_y];
}

void CUnit::CheckMoveable(){
	for(int x=0;x<MAP_W;x++){
		for(int y=0;y<MAP_H;y++){
			route[x][y]=0;
			if(moves >= table[Array2D(unitX-x+9,unitY-y+9)] && Array2D(unitX-x+9,unitY-y+9) >= 0 && Array2D(unitX-x+9,unitY-y+9)<361 ){
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

void CUnit::Move(int a){
	moves--;
	if(a==RIGHT){
		unitX++;
	}
	if(a==LEFT){
		unitX--;
	}
	if(a==DOWN){
		unitY++;
	}
	if(a==UP){
		unitY--;
	}
}

void CUnit::SetMoveEnd(){
	MoveEnd=true;
	selected=false;
}

void CUnit::MakeMoveEnd(){
	SetMoveEnd();
	moves=0;
}

void CUnit::Damage(int d){
	hp-=d;
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