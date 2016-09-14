#include"DxLib.h"
#include"Suken.h"
#include"Product.h"
#include"General.h"

CProduct::CProduct(){
	openwin=false;
	openednow=false;
	locationX=0;
	locationY=0;
	produced=false;
	cant[0]=false;
	cant[1]=false;
}

int CProduct::Getcx(){
	return cursor.Getcx();
}

int CProduct::Getcy(){
	return cursor.Getcy();
}

void CProduct::Awake(){
	picture.LoadProductPic();
	picture.LoadUnitPic();

	file.LoadUnitFile();
	file.LoadTerrainFile();

	for(int i=1;i<=COUNTRY_NUM;i++){
		battle.unitm.country[i].Awake();
	}

	for (int x = 0; x < MAP_W; x++){
		for (int y = 0; y < MAP_H; y++){
			battle.unitm.SetMoveCost(x, y, file.moveCost[stage.GetTerrain(x, y)]);

			for (int i = 1; i <= COUNTRY_NUM; i++){
				if (stage.GetTownOwner(x, y) != i && stage.GetTownOwner(x, y) != 0){
					for (int n = 1; n <= UNIT_NUM; n++){
						battle.unitm.country[i].unit[n].SetObstacle(x, y, 2);
					}
				}
			}
		}
	}

	battle.unitm.country[1].Income(stage.GetTNum(1)*10);
}

bool CProduct::UnitOnTown(){
	for (int i = 1; i <= COUNTRY_NUM; i++){
		for (int n = 1; n <= UNIT_NUM ; n++){
			if (cursor.Getcx() == battle.unitm.country[i].unit[n].GetunitX() && cursor.Getcy() == battle.unitm.country[i].unit[n].GetunitY()){
				return true;
			}
		}
	}

	return false;
}

void CProduct::SetTownOwner(){
	for (int x = 0; x < MAP_W; x++){
		for (int y = 0; y < MAP_H; y++){
			battle.SetTownOwner(x, y, stage.GetTownOwner(x, y));
		}
	}
}

void CProduct::Product(){
	//debug.Print("%",);
	//DEBUG_PRINT_VALUE();

	cursor.Setm();
	cursor.Setc();

	openednow = false;

	produced = false;

	for (int x = 0; x < MAP_W; x++){
		for (int y = 0; y < MAP_H; y++){
			if (Event.LMouse.GetClick(100, 50, 100 + GRID_L*MAP_W, 50 + GRID_L*MAP_H) && stage.GetTownOwner(cursor.Getcx(), cursor.Getcy()) == turn.GetCountry() && !(openwin || cant[0] || cant[1]) && !UnitOnTown()){

				forcheck = 1;

				while(forcheck <= UNIT_NUM){
					if (battle.unitm.country[turn.GetCountry()].unit[forcheck].GetunitX() == -100){
						openwin = true;
						openednow = true;
						locationX = cursor.Getcx();
						locationY = cursor.Getcy();

						forcheck = UNIT_NUM+100;
					} else {
						forcheck++;
					}
				}

				if(forcheck != UNIT_NUM + 100){
					cant[0] = true;
					openednow = true;
				}
			}
		}
	}

	if (cant[0]){
		DrawGraph(350, 250, picture.cannot[0], true);

		DrawGraph(425, 300, picture.ok, true);

		if(Event.LMouse.GetClick(424,299,475,325)){
			cant[0] = false;
		}
	}

	if(cant[1]){
		DrawGraph(350, 250, picture.cannot[1], true);

		DrawGraph(425, 300, picture.ok, true);

		if(Event.LMouse.GetClick(424,299,475,325)){
			cant[1] = false;
		}
	}


	if (openwin){
		DrawGraph(100, 50, picture.productScr, true);

		for(int i=0;i<3;i++){
			DrawFormatString(150, 100+50*i, BLACK, file.name[i+1]);

			DrawGraph(250, 95+50*i, picture.unitPic[i], true);

			if(cursor.Getmx()>145 && cursor.Getmx()<305 && cursor.Getmy()>95+i*50 && cursor.Getmy()<125+i*50){
				DrawBox(140,90+i*50,305,125+i*50,RED,false);
			}
			
			if(Event.LMouse.GetClick(145,95+i*50,305,125+i*50) && !openednow){
				for(int n=1;n<=UNIT_NUM;n++){
					if(battle.unitm.country[turn.GetCountry()].unit[n].GetunitX()==-100 && !produced){
						if(battle.unitm.country[turn.GetCountry()].CanPay(5)){
							battle.unitm.country[turn.GetCountry()].unit[n].Product(locationX,locationY,i+1);
							battle.unitm.country[turn.GetCountry()].Pay(50);
						}else{
							cant[1]=true;
						}
						produced=true;
					}
				}

				openwin=false;
			}

		}

		DrawGraph(770,50,picture.close,true);

		if(Event.LMouse.GetClick(770,50,800,80)){
			openwin = false;
		}
	}

	if(openwin){
		battle.unitm.ProductScr(true,true);
	}
	else{
		battle.unitm.ProductScr(cant[0],cant[1]);
	}

	if(turn.Getskip()){
		openwin=false;
		cant[0]=false;
		cant[1]=false;
	}

	for(int i=1;i<=COUNTRY_NUM;i++){
		battle.unitm.country[i].ShowMoney(i);
	}

	Income();

	if(Event.RMouse.GetClick(100,50,100+GRID_L*(MAP_W-1),50+GRID_L*(MAP_H-1))){
		DamageTown(cursor.Getcx(),cursor.Getcy(),battle.GetTDamage(),turn.GetCountry());
	}

	if(Event.key.GetDown(Event.key.RETURN)){
		for(int x=0;x<MAP_W;x++){
			for(int y=0;y<MAP_H;y++){
				if(stage.GetTownOwner(x,y)==turn.GetCountry()){
					if(stage.GetTownHp(x,y)<=90){
						stage.DamageTown(x,y,-10,0);
					}
					else if(stage.GetTownHp(x,y)<100){
						stage.DamageTown(x,y,stage.GetTownHp(x,y)-100,0);
					}
				}
			}
		}
	}

	SetTownOwner();

	turn.SkipTurn();

}

void CProduct::Income(){
	if(turn.Getskip()){
		battle.unitm.country[turn.GetCountry()].Income(stage.GetTNum(turn.GetCountry())*10);
	}
}

void CProduct::DamageTown(int x,int y,int damage,int attacker){
	if(battle.GetBesiege()){
		stage.DamageTown(x, y, damage, attacker);
	}
}
