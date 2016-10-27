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

void CProduct::Awake(int stageNum){
	picture.LoadProductPic();
	picture.LoadUnitPic();

	file.LoadUnitFile();
	file.LoadTerrainFile();
	file.LoadMapSize();

	mapW = file.mapX[stageNum];
	mapH = file.mapY[stageNum];

	turn.Awake();

	screen.SetStage();

	for(int i=1;i<=COUNTRY_NUM;i++){
		battle.unitm.country[i].Awake();
	}

	for (int x = 0; x < mapW; x++){
		for (int y = 0; y < mapH; y++){
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

	sNum=stageNum;

	openwin=false;
	cant[0]=false;
	cant[1]=false;
}

bool CProduct::UnitOnTown(){
	for (int i = 1; i <= COUNTRY_NUM; i++){
		for (int n = 1; n <= UNIT_NUM ; n++){
			if (cursor.Getcx() + screen.adjX == battle.unitm.country[i].unit[n].GetunitX() && cursor.Getcy() + screen.adjY == battle.unitm.country[i].unit[n].GetunitY()){
				return true;
			}
		}
	}

	return false;
}

void CProduct::SetTownOwner(){
	for (int x = 0; x < mapW; x++){
		for (int y = 0; y < mapH; y++){
			battle.SetTownOwner(x, y, stage.GetTownOwner(x, y));
		}
	}
}

void CProduct::Product(){
	//debug.Print("%",);
	//DEBUG_PRINT_VALUE();

	cursor.Setm();
	cursor.Setc();
	screen.MoveAdj(sNum);

	openednow = false;

	produced = false;

	
	if (Event.LMouse.GetClick(100, 50, 100 + GRID_L*MAP_W, 50 + GRID_L*MAP_H) && stage.GetTownOwner(cursor.Getcx() + screen.adjX, cursor.Getcy() + screen.adjY) == turn.GetCountry() && !(openwin || cant[0] || cant[1]) && !UnitOnTown()){

		forcheck = 1;

		while (forcheck <= UNIT_NUM){
			if (battle.unitm.country[turn.GetCountry()].unit[forcheck].GetunitX() == -100){
				openwin = true;
				openednow = true;
				locationX = cursor.Getcx() + screen.adjX;
				locationY = cursor.Getcy() + screen.adjY;

				forcheck = UNIT_NUM + 100;
			}
			else {
				forcheck++;
			}
		}

		if (forcheck != UNIT_NUM + 100){
			cant[0] = true;
			openednow = true;
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

		for (int j = 0; j < 2; j++){
			for (int i = 0; i < 3; i++){
				DrawGraph(307 + j * 270, 73, picture.coin, true);

				DrawGraph(328 + 20 * i + j * 270, 70, picture.strength[i], true);
			}
		}

		for(int i=0;i<UTYPE_NUM;i++){
			DrawGraph(150 + (i / 5) * 270, 95 + 50 * (i % 5), picture.unitPic[i], true);

			DrawFormatString(180 + (i / 5) * 270, 100 + 50 * (i % 5), BLACK, file.name[i + 1]);

			draw.DrawNumber(295 + (i / 5) * 270, 100 + 50 * (i % 5), GRAY, file.cost[i + 1]);
			
			draw.DrawNumber(320 + (i / 5) * 270, 100 + 50 * (i % 5), RED, file.strength[i + 1]);
			
			draw.DrawNumber(340 + (i / 5) * 270, 100 + 50 * (i % 5), GREEN, file.rangedStrength[i + 1]);
			
			draw.DrawNumber(360 + (i / 5) * 270, 100 + 50 * (i % 5), BLUE, file.siegeStrength[i + 1]);
			
			if (cursor.Getmx()>140 + (i / 5) * 270 && cursor.Getmx()<390 + (i / 5) * 270 && cursor.Getmy()>95 + (i % 5) * 50 && cursor.Getmy()<125 + (i % 5) * 50){
				DrawBox(140 + (i / 5) * 270, 90 + (i % 5) * 50, 390 + (i / 5) * 270, 125 + (i % 5) * 50, RED, false);
			}
			
			if (Event.LMouse.GetClick(145 + (i / 5) * 270, 95 + (i % 5) * 50, 390 + (i / 5) * 270, 125 + (i % 5) * 50) && !openednow){
				for(int n=1;n<=UNIT_NUM;n++){
					if(battle.unitm.country[turn.GetCountry()].unit[n].GetunitX()==-100 && !produced){
						if (battle.unitm.country[turn.GetCountry()].CanPay(file.cost[i + 1])){
							battle.unitm.country[turn.GetCountry()].unit[n].Product(locationX,locationY,i+1);
							battle.unitm.country[turn.GetCountry()].Pay(file.cost[i+1]);
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

	for (int i = 1; i <= COUNTRY_NUM; i++){
		if (stage.GetTNum(i) != 0){
			battle.unitm.country[i].ShowMoney(i);
		}else{
			battle.unitm.country[i].GameOver();
		}
	}

	Income();

	if (Event.RMouse.GetClick(100, 50, 100 + GRID_L*MAP_W, 50 + GRID_L*MAP_H) || Event.LMouse.GetClick(100, 50, 100 + GRID_L*MAP_W, 50 + GRID_L*MAP_H)){
		DamageTown(cursor.Getcx() + screen.adjX, cursor.Getcy() + screen.adjY, battle.GetTDamage(), turn.GetCountry());
	}

	if(Event.key.GetDown(Event.key.RETURN)){
		for(int x=0;x<mapW;x++){
			for(int y=0;y<mapH;y++){
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
	if(turn.Getskip() && stage.GetTNum(turn.GetCountry()) != 0){
		battle.unitm.country[turn.GetCountry()].Income(stage.GetTNum(turn.GetCountry())*10);
	}
}

void CProduct::DamageTown(int x,int y,int damage,int attacker){
	if(battle.GetBesiege()){
		stage.DamageTown(x, y, damage, attacker);
	}
}

int CProduct::GetStage(){
	return sNum;
}
