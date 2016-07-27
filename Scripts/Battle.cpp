#include"DxLib.h"
#include"Suken.h"
#include"Battle.h"
#include"Cursor.h"
#include"General.h"
#include<math.h>

CBattle::CBattle(){
	index=2;
	checkx[0]=0;
	checkx[1]=1;
	checkx[2]=0;
	checkx[3]=-1;
	checky[0]=1;
	checky[1]=0;
	checky[2]=-1;
	checky[3]=0;
}

int CBattle::LocationX(int _country,int _unit){
	return unitm.country[_country].unit[_unit].GetunitX();
}

int CBattle::LocationY(int _country,int _unit){
	return unitm.country[_country].unit[_unit].GetunitY();
}

bool CBattle::Selecting(){
	if(selectingC!=0 && selectingU!=0){
		return true;
	}else{
		return false;
	}
}

bool CBattle::Enemy(int _country){
	if(_country == selectingC){
		return false;
	}else{
		return true;
	}
}

int CBattle::GetHP(int _country,int _unit){
	return unitm.country[_country].unit[_unit].Gethp();
}

int CBattle::GetStrength(int _country,int _unit){
	return unitm.country[_country].unit[_unit].Getstrength();
}

int CBattle::GetSStrength(int _country,int _unit){
	return unitm.country[_country].unit[_unit].GetSstrength();
}

bool CBattle::CheckRCOn(int _country,int _unit){
	if(Event.RMouse.GetClick(LocationX(_country,_unit)*50+100,LocationY(_country,_unit)*50+50,LocationX(_country,_unit)*50+150,LocationY(_country,_unit)*50+100)){
		return true;
	}else{
		return false;
	}
}

int CBattle::Attack(int base,int atkC,int atkU,int defC,int defU){
	return (base+GetRand(6))*(1+pow(GetStrength(atkC,atkU)-GetStrength(defC,defU),index)/pow(GetStrength(defC,defU),index))*(GetHP(atkC,atkU)/2+50)/100;
}

void CBattle::Damage(int _country,int _unit,int _damage){
	unitm.country[_country].unit[_unit].Damage(_damage);
}

void CBattle::CheckSelecting(){
	selectingC=turn.GetCountry();
	selectingU=unitm.GetselectingU();
}

bool CBattle::Dead(int _country,int _unit){
	if(unitm.country[_country].unit[_unit].Gethp()<=0){
		return true;
	}else{
		return false;
	}
}

void CBattle::SetTarget(){
	for(int x=0;x<MAP_W;x++){
		for(int y=0;y<MAP_H;y++){
			target[x][y]=false;
			Ctarget[x][y]=false;
			Starget[x][y]=false;
		}
	}

	for(int i=1;i<=COUNTRY_NUM;i++){
		for(int n=1;n<=UNIT_NUM;n++){
			target[LocationX(i,n)][LocationY(i,n)]=true;
		}
	}

	for(int i=1;i<=COUNTRY_NUM;i++){
		for(int n=1;n<=UNIT_NUM;n++){
			if(Enemy(i)){
				for(int a=0;a<4;a++){
					if(target[LocationX(selectingC,selectingU)+checkx[a]][LocationY(selectingC,selectingU)+checky[a]]){
						Ctarget[LocationX(selectingC,selectingU)+checkx[a]][LocationY(selectingC,selectingU)+checky[a]]=true;
					}
				}

				for(int x=0;x<MAP_W;x++){
					for(int y=0;y<MAP_H;y++){
						if(cal.Absolute(LocationX(selectingC,selectingU)-x)+cal.Absolute(LocationY(selectingC,selectingU)-y)<=2 && target[x][y] && GetSStrength(selectingC,selectingU)>0){
							Starget[x][y]=true;
						}
					}
				}
			}
		}
	}
}

void CBattle::Battle(){

	cursorm.cursor.Setm();
	cursorm.cursor.Setc();

	turn.SkipTurn();

	CheckSelecting();

	range_attack=false;

	AtkDam=0;
	DefDam=0;

	if(Selecting()){
		SetTarget();

		if (unitm.country[selectingC].unit[selectingU].GetPrepared()){
			Shot();

			if (!range_attack){
				Combat();
			}
		}
	}
}

void CBattle::Combat(){
	for(int i=1;i<=COUNTRY_NUM;i++){
		for(int n=1;n<=UNIT_NUM;n++){
			if(CheckRCOn(i,n)&& Ctarget[LocationX(i,n)][LocationY(i,n)]  && Enemy(i)){
				DefDam=Attack(22,selectingC,selectingU,i,n);
				AtkDam=Attack(22,i,n,selectingC,selectingU);

				Damage(i,n,DefDam);
				Damage(selectingC,selectingU,AtkDam);

				if(Dead(selectingC,selectingU)){
					unitm.country[selectingC].unit[selectingU].Death();
					unitm.country[i].unit[n].Survive();
				}else{
					if(Dead(i,n)){
						unitm.country[i].unit[n].Death();
					}
				}

				unitm.Moveend();
			}
		}
	}
}

void CBattle::Shot(){
	
	if(GetSStrength(selectingC,selectingU)!=0){
		for(int x=0;x<MAP_W;x++){
			for(int y=0;y<MAP_H;y++){
				if(Starget[x][y]){
					DrawCircle((x+2)*GRID_L+25,(y+1)*GRID_L+25,25,RED,false);
				}
			}
		}

		for(int i=1;i<=COUNTRY_NUM;i++){
			for(int n=1;n<=UNIT_NUM;n++){
				if(CheckRCOn(i,n) && Starget[LocationX(i,n)][LocationY(i,n)] && Enemy(i)){				
					range_attack=true;

					DefDam=Attack(12,selectingC,selectingU,i,n);
					Damage(i,n,DefDam);

					if(Dead(i,n)){
						unitm.country[i].unit[n].Death();
					}

					unitm.Moveend();
				}
			}
		}
	}
}
