#include"DxLib.h"
#include"Suken.h"
#include"Battle.h"
#include"Cursor.h"
#include"General.h"
#include<math.h>

const int ATTACK=1;
const int DEFEND=2;

const int TOWN_STRENGTH=11;

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

void CBattle::Awake(int stage){
	turn.Awake();

	file.LoadMapSize();

	picture.LoadBattlePic();

	screen.SetStage();
	
	sNum=stage;

	mapW = file.mapX[stage];
	mapH = file.mapY[stage];
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

bool CBattle::CheckCOnUnit(int country,int unit){
	displayX = LocationX(country, unit) - screen.adjX;
	displayY = LocationY(country, unit) - screen.adjY;

	if (Event.RMouse.GetClick(displayX * 50 + 100, displayY * 50 + 50, displayX * 50 + 150, displayY * 50 + 100) || Event.LMouse.GetClick(displayX * 50 + 100, displayY * 50 + 50, displayX * 50 + 150, displayY * 50 + 100)){
		return true;
	}else{
		return false;
	}
}

bool CBattle::CheckCOnTown(int type){
	if (Event.RMouse.GetClick(100, 50, 100 + GRID_L * MAP_W, 50 + GRID_L*MAP_H) || Event.LMouse.GetClick(100, 50, 100 + GRID_L*MAP_W, 50 + GRID_L*MAP_H)){
		switch (type){
		case 1:
			return SCtarget[cursorX+screen.adjX][cursorY+screen.adjY];

			break;
	
		case 2:
			return SRtarget[cursorX+screen.adjX][cursorY+screen.adjY];

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
		if(power>=TOWN_STRENGTH){
			return (base+GetRand(6))*(1+pow(power-TOWN_STRENGTH,index)/pow(TOWN_STRENGTH,index))*(GetHP(unitC,unitU)/2+50)/100;
		}else{
			return (base+GetRand(6))*(1-pow(power-TOWN_STRENGTH,index)/pow(TOWN_STRENGTH,index))*(GetHP(unitC,unitU)/2+50)/100;
		}
		break;

	case DEFEND:
		if(power>=TOWN_STRENGTH){
			return (base+GetRand(6))*(1-pow(TOWN_STRENGTH-power,index)/pow(power,index));
		}else{
			return (base+GetRand(6))*(1+pow(TOWN_STRENGTH-power,index)/pow(power,index));
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

	for(int x=0;x<mapW;x++){
		for(int y=0;y<mapH;y++){
			target[x][y]=false;
			Ctarget[x][y]=false;
			Rtarget[x][y]=false;
			town[x][y]=false;
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
				if(target[LocationX(selectingC,selectingU)+checkx[a]][LocationY(selectingC,selectingU)+checky[a]] && GetRStrength(selectingC,selectingU)==0){
					Ctarget[LocationX(selectingC,selectingU)+checkx[a]][LocationY(selectingC,selectingU)+checky[a]]=true;
				}
			}

			for(int x=0;x<mapW;x++){
				for(int y=0;y<mapH;y++){
					if(cal.Absolute(LocationX(selectingC,selectingU)-x)+cal.Absolute(LocationY(selectingC,selectingU)-y)<=GetRange(selectingC,selectingU) && target[x][y] && GetRStrength(selectingC,selectingU)>0){
						Rtarget[x][y]=true;
					}
				}
			}
		}
	}

	for (int x = 0; x < mapW; x++){
		for (int y = 0; y < mapH; y++){
			if (unitm.country[selectingC].unit[selectingU].GetObstacle(x, y) == 2){
				town[x][y] = true;
			}
		}
	}

	for (int x = 0; x < mapW; x++){
		for (int y = 0; y < mapH; y++){
			if (townOwner[x][y] != selectingC && !target[x][y] && townOwner[x][y] != 0){
				for (int a = 0; a < 4; a++){
					if (town[LocationX(selectingC, selectingU) + checkx[a]][LocationY(selectingC, selectingU) + checky[a]]){
						SCtarget[LocationX(selectingC, selectingU) + checkx[a]][LocationY(selectingC, selectingU) + checky[a]] = true;
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
	screen.MoveAdj(sNum);
	CheckSelecting();

	range_attack=false;
	besiege = false;

	AtkDam=0;
	DefDam=0;

	if(Selecting()){
		SetTarget();

		for (int x = screen.adjX; x < screen.adjX + MAP_W; x++){
			for (int y = screen.adjY; y < screen.adjY + MAP_H; y++){
				if (Ctarget[x][y] || SCtarget[x][y]){
					DrawGraph((x - screen.adjX)*GRID_L + 102, (y - screen.adjY)*GRID_L + 52, picture.combatRangeBox, true);
				}
				if (Rtarget[x][y] || SRtarget[x][y]){
					DrawGraph((x - screen.adjX)*GRID_L + 102, (y - screen.adjY)*GRID_L + 52, picture.shotRangeBox, true);
				}
			}
		}

		if (unitm.country[selectingC].unit[selectingU].GetPrepared() && !unitm.country[selectingC].unit[selectingU].GetAttacked()){
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
			if(CheckCOnUnit(i,n)&& Ctarget[LocationX(i,n)][LocationY(i,n)]  && Enemy(i)){
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

				unitm.country[selectingC].unit[selectingU].SetAttacked(true);

				unitm.country[selectingC].unit[selectingU].Move(0, 1);

				LoadSound();
			}
		}
	}
}

void CBattle::Ranged(){
	if(GetRStrength(selectingC,selectingU)!=0){
		for(int x=0;x<MAP_W;x++){
			for(int y=0;y<MAP_H;y++){
				if(Rtarget[x+screen.adjX][y+screen.adjY]){
					DrawCircle((x+2)*GRID_L+25,(y+1)*GRID_L+25,25,RED,false);
				}
			}
		}

		for(int i=1;i<=COUNTRY_NUM;i++){
			for(int n=1;n<=UNIT_NUM;n++){
				if(CheckCOnUnit(i,n) && Rtarget[LocationX(i,n)][LocationY(i,n)] && Enemy(i)){	
					range_attack=true;

					if (cal.Absolute(LocationX(selectingC, selectingU) - LocationX(i, n))+cal.Absolute(LocationY(selectingC, selectingU) - LocationY(i, n)) == 1){
						AtkDam = Attack(12, i, n, selectingC, selectingU);
					}

					DefDam=Attack(17,selectingC,selectingU,i,n);

					Damage(i, n, DefDam);
					Damage(selectingC, selectingU, AtkDam);

					if(Dead(selectingC,selectingU)){
						unitm.country[selectingC].unit[selectingU].Death();
						unitm.country[i].unit[n].Survive();
					}else{
						if(Dead(i,n)){
							unitm.country[i].unit[n].Death();
						}
					}

					unitm.country[selectingC].unit[selectingU].SetAttacked(true);

					unitm.country[selectingC].unit[selectingU].Move(0, 1);

					LoadSound();
				}
			}
		}
	}
}

void CBattle::Siege(){
	if (CheckCOnTown(2)){
		besiege=true;

		tDamage=FightTown(ATTACK,10,unitm.country[selectingC].unit[selectingU].GetSstrength(),selectingC,selectingU);

		unitm.country[selectingC].unit[selectingU].SetAttacked(true);

		unitm.country[selectingC].unit[selectingU].Move(0, 1);

		LoadSound();
	}
	else if(CheckCOnTown(1)){
		besiege=true;

		tDamage=FightTown(ATTACK,18,unitm.country[selectingC].unit[selectingU].GetSstrength(),selectingC,selectingU);
		AtkDam=FightTown(DEFEND,18,unitm.country[selectingC].unit[selectingU].GetSstrength(),selectingC,selectingU);

		Damage(selectingC,selectingU,AtkDam);

		if(Dead(selectingC,selectingU)){
			unitm.country[selectingC].unit[selectingU].Death();
		}

		unitm.country[selectingC].unit[selectingU].SetAttacked(true);

		unitm.country[selectingC].unit[selectingU].Move(0, 1);

		LoadSound();
	}
}

int CBattle::GetTDamage(){
	return tDamage;
}

bool CBattle::GetBesiege(){
	return besiege;
}

void CBattle::LoadSound(){
	switch(unitm.country[selectingC].unit[selectingU].Gettype()){
	case 1:
	case 3:
		music->AddSound(sStab);
		break;

	case 2:
	case 4:
		music->AddSound(sBow);
		break;

	case 5:
	case 6:
		music->AddSound(sSlash);
		break;

	case 7:
		music->AddSound(sShoot);
		break;

	case 8:
	case 9:
		music->AddSound(sCrash);
		break;

	case 10:
		music->AddSound(sBoom);
		break;
	}
}
