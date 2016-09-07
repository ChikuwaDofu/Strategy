#include"DxLib.h"
#include"Suken.h"
#include"Battle.h"
#include"Cursor.h"
#include"General.h"
#include<math.h>

const int ATTACK=1;
const int DEFEND=2;

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

int CBattle::LocationX(int country,int unit){
	return unitm.country[country].unit[unit].GetunitX();
}

int CBattle::LocationY(int country,int unit){
	return unitm.country[country].unit[unit].GetunitY();
}

bool CBattle::Selecting(){
	if(selectingC!=0 && selectingU!=0){
		return true;
	}else{
		return false;
	}
}

bool CBattle::Enemy(int country){
	if(country == selectingC){
		return false;
	}else{
		return true;
	}
}

int CBattle::GetHP(int country,int unit){
	return unitm.country[country].unit[unit].Gethp();
}

int CBattle::GetStrength(int country,int unit){
	return unitm.country[country].unit[unit].Getstrength();
}

int CBattle::GetRStrength(int country,int unit){
	return unitm.country[country].unit[unit].GetRstrength();
}

int CBattle::GetRange(int country, int unit){
	return unitm.country[country].unit[unit].GetRange();
}

bool CBattle::CheckRCOnUnit(int country,int unit){
	if(Event.RMouse.GetClick(LocationX(country,unit)*50+100,LocationY(country,unit)*50+50,LocationX(country,unit)*50+150,LocationY(country,unit)*50+100)){
		return true;
	}else{
		return false;
	}
}

bool CBattle::CheckRCOnTown(int type){
	if(Event.RMouse.GetClick(100,50,100+GRID_L*(MAP_W-1),50+GRID_L*(MAP_H-1))){
		switch (type){
		case 1:
			return SCtarget[cursorX][cursorY];

			break;
	
		case 2:
			return SRtarget[cursorX][cursorY];

			break;
		}
	}
}

int CBattle::Attack(int base,int atkC,int atkU,int defC,int defU){
	return (base+GetRand(6))*(1+pow(GetStrength(atkC,atkU)-GetStrength(defC,defU),index)/pow(GetStrength(defC,defU),index))*(GetHP(atkC,atkU)/2+50)/100;
}

int CBattle::FightTown(int type,int base,int power,int unitC,int unitU){
	switch(type){
	case ATTACK:
		if(power>=15){
			return (base+GetRand(6))*(1+pow(power-15,index)/pow(15,index))*(GetHP(unitC,unitU)/2+50)/100;
		}else{
			return (base+GetRand(6))*(1-pow(power-15,index)/pow(15,index))*(GetHP(unitC,unitU)/2+50)/100;
		}
		break;

	case DEFEND:
		if(power>=15){
			return (base+GetRand(6))*(1-pow(15-power,index)/pow(power,index));
		}else{
			return (base+GetRand(6))*(1+pow(15-power,index)/pow(power,index));
		}
		break;
	}
}

void CBattle::Damage(int country,int unit,int damage){
	unitm.country[country].unit[unit].Damage(damage);
}

void CBattle::CheckSelecting(){
	selectingC=turn.GetCountry();
	selectingU=unitm.GetselectingU();
}

bool CBattle::Dead(int country,int unit){
	if(unitm.country[country].unit[unit].Gethp()<=0){
		return true;
	}else{
		return false;
	}
}

void CBattle::SetTownOwner(int x, int y,int owner){
	townOwner[x][y] = owner;
}

void CBattle::SetTarget(){
	
	cursorm.cursor.Setm();
	cursorm.cursor.Setc();

	cursorX=cursorm.cursor.Getcx();
	cursorY=cursorm.cursor.Getcy();

	for(int x=0;x<MAP_W;x++){
		for(int y=0;y<MAP_H;y++){
			target[x][y]=false;
			Ctarget[x][y]=false;
			Rtarget[x][y]=false;
			SCtarget[x][y] = false;
			SRtarget[x][y] = false;
		}
	}

	for(int i=1;i<=COUNTRY_NUM;i++){
		for(int n=1;n<=UNIT_NUM;n++){
			if (Enemy(i)){
				target[LocationX(i, n)][LocationY(i, n)] = true;
			}
		}
	}

	for(int i=1;i<=COUNTRY_NUM;i++){
		for(int n=1;n<=UNIT_NUM;n++){
			for(int a=0;a<4;a++){
				if(target[LocationX(selectingC,selectingU)+checkx[a]][LocationY(selectingC,selectingU)+checky[a]]){
					Ctarget[LocationX(selectingC,selectingU)+checkx[a]][LocationY(selectingC,selectingU)+checky[a]]=true;
				}
			}

			for(int x=0;x<MAP_W;x++){
				for(int y=0;y<MAP_H;y++){
					if(cal.Absolute(LocationX(selectingC,selectingU)-x)+cal.Absolute(LocationY(selectingC,selectingU)-y)<=GetRange(selectingC,selectingU) && target[x][y] && GetRStrength(selectingC,selectingU)>0){
						Rtarget[x][y]=true;
					}
				}
			}
		}
	}

	for (int x = 0; x < MAP_W; x++){
		for (int y = 0; y < MAP_H; y++){
			if (unitm.country[selectingC].unit[selectingU].GetObstacle(x, y) == 2){
				town[x][y] = true;
			}
		}
	}

	for (int x = 0; x < MAP_W; x++){
		for (int y = 0; y < MAP_H; y++){
			if (townOwner[x][y] != selectingC){
				for (int a = 0; a < 4; a++){
					if (town[LocationX(selectingC, selectingU) + checkx[a]][LocationY(selectingC, selectingU) + checky[a]]){
						SCtarget[x][y] = true;
					}

					if (cal.Absolute(LocationX(selectingC, selectingU) - x) + cal.Absolute(LocationY(selectingC, selectingU) - y) <= GetRange(selectingC, selectingU) && town[x][y] && GetRStrength(selectingC, selectingU)>0){
						SRtarget[x][y] = true;
					}
				}
			}
		}
	}
}

void CBattle::Battle(){

	turn.SkipTurn();

	CheckSelecting();

	range_attack=false;

	besiege = false;

	AtkDam=0;
	DefDam=0;

	if(Selecting()){
		SetTarget();

		if (unitm.country[selectingC].unit[selectingU].GetPrepared()){
			Siege();

			Ranged();

			if (!range_attack){
				Combat();
			}
		}
	}
}

void CBattle::Combat(){
	for(int i=1;i<=COUNTRY_NUM;i++){
		for(int n=1;n<=UNIT_NUM;n++){
			if(CheckRCOnUnit(i,n)&& Ctarget[LocationX(i,n)][LocationY(i,n)]  && Enemy(i)){
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

				unitm.country[selectingC].unit[selectingU].Move(0);
			}
		}
	}
}

void CBattle::Ranged(){
	
	if(GetRStrength(selectingC,selectingU)!=0){
		for(int x=0;x<MAP_W;x++){
			for(int y=0;y<MAP_H;y++){
				if(Rtarget[x][y]){
					DrawCircle((x+2)*GRID_L+25,(y+1)*GRID_L+25,25,RED,false);
				}
			}
		}

		for(int i=1;i<=COUNTRY_NUM;i++){
			for(int n=1;n<=UNIT_NUM;n++){
				if(CheckRCOnUnit(i,n) && Rtarget[LocationX(i,n)][LocationY(i,n)] && Enemy(i)){				
					range_attack=true;

					if (cal.Absolute(LocationX(selectingC, selectingU) - LocationX(i, n))+cal.Absolute(LocationY(selectingC, selectingU) - LocationY(i, n)) == 1){
						AtkDam = Attack(22, i, n, selectingC, selectingU);
					}

					DefDam=Attack(12,selectingC,selectingU,i,n);

					Damage(i, n, DefDam);
					Damage(selectingC, selectingU, AtkDam);

					if(Dead(i,n)){
						unitm.country[i].unit[n].Death();
					}

					unitm.country[selectingC].unit[selectingU].Move(0);
				}
			}
		}
	}
}

void CBattle::Siege(){
	if (CheckRCOnTown(2)){
		besiege=true;

		tDamage=FightTown(ATTACK,10,unitm.country[selectingC].unit[selectingU].GetSstrength(),selectingC,selectingU);

		unitm.country[selectingC].unit[selectingU].Move(0);
	}
	else if(CheckRCOnTown(1)){
		besiege=true;

		tDamage=FightTown(ATTACK,18,unitm.country[selectingC].unit[selectingU].GetSstrength(),selectingC,selectingU);
		AtkDam=FightTown(DEFEND,18,unitm.country[selectingC].unit[selectingU].GetSstrength(),selectingC,selectingU);

		Damage(selectingC,selectingU,AtkDam);

		if(Dead(selectingC,selectingU)){
			unitm.country[selectingC].unit[selectingU].Death();
		}
		
		unitm.country[selectingC].unit[selectingU].Move(0);
	}

}

int CBattle::GetTDamage(){
	return tDamage;
}

bool CBattle::GetBesiege(){
	return besiege;
}
