#include"DxLib.h"
#include"Suken.h"
#include"Product.h"
#include"General.h"

CProduct::CProduct(){
	openwin=false;
	openednow=false;
	country=-1;
	locationX=0;
	locationY=0;
	produced=false;
	cant=false;
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
}

bool CProduct::UnitOnTown(){
	for (int i = 0; i < COUNTRY_NUM; i++){
		for (int n = 0; n < UNIT_NUM ; n++){
			if (cursor.Getcx() == battle.unitm.country[i].unit[n].GetunitX() && cursor.Getcy() == battle.unitm.country[i].unit[n].GetunitY()){
				return true;
			}
		}
	}

	return false;
}

void CProduct::Product(){
	cursor.Setm();
	cursor.Setc();

	openednow = false;

	produced = false;

	for (int x = 0; x < MAP_W; x++){
		for (int y = 0; y < MAP_H; y++){
			if (Event.LMouse.GetClick(100, 50, 100 + GRID_L*MAP_W, 50 + GRID_L*MAP_H) && stage.GetTownOwner(cursor.Getcx(), cursor.Getcy()) != -1 && !(openwin || cant) && !UnitOnTown()){

				forcheck = 0;

				while(forcheck < UNIT_NUM){
					if (battle.unitm.country[stage.GetTownOwner(cursor.Getcx(), cursor.Getcy())].unit[forcheck].GetunitX() == -100){
						openwin = true;
						openednow = true;
						country = stage.GetTownOwner(cursor.Getcx(), cursor.Getcy());
						locationX = cursor.Getcx();
						locationY = cursor.Getcy();

						forcheck = UNIT_NUM+1;
					} else {
						forcheck++;
					}
				}

				if(forcheck != UNIT_NUM + 1){
					cant = true;
					openednow = true;
				}
			}
		}
	}

	if (cant){
		DrawGraph(350, 250, picture.cannot, true);

		DrawGraph(425, 300, picture.ok, true);

		if(Event.LMouse.GetClick(424,299,475,325)){
			cant = false;
		}
	}

	if (openwin){
		DrawGraph(100, 50, picture.productScr, true);

		DrawString(150, 100, "Type1", BLACK);

		DrawString(150, 150, "Type2", BLACK);

		DrawGraph(250, 95, picture.unitPic[0], true);
		
		DrawGraph(250, 145, picture.unitPic[1], true);

		for(int i=0;i<2;i++){
			if(cursor.Getmx()>145 && cursor.Getmx()<305 && cursor.Getmy()>95+i*50 && cursor.Getmy()<125+i*50){
				DrawBox(140,90+i*50,305,125+i*50,RED,false);
			}

			if(Event.LMouse.GetClick(145,95+i*50,305,125+i*50) && !openednow){
				for(int n=0;n<UNIT_NUM;n++){
					if(battle.unitm.country[country].unit[n].GetunitX()==-100 && !produced){
						battle.unitm.country[country].unit[n].Product(locationX,locationY,i+1);
						produced=true;
					}
				}

				openwin=false;
				country=-1;
			}
		}

		DrawGraph(770,50,picture.close,true);

		if(Event.LMouse.GetClick(770,50,800,80)){
			openwin = false;
		}
	}

	if(openwin){
		battle.unitm.ProductScr(openwin);
	}
	else{
		battle.unitm.ProductScr(cant);
	}
}
