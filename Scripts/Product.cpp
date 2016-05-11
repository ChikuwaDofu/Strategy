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
}

int CProduct::Getcx(){
	return cursor.Getcx();
}

int CProduct::Getcy(){
	return cursor.Getcy();
}

void CProduct::Awake(){
	window = LoadGraph("Kawachi2/Production.png");
	unitpic[0] = LoadGraph("Kawachi2/Spear.png");
	unitpic[1] = LoadGraph("Kawachi2/Bow.png");
}

void CProduct::Product(){
	cursor.Setm();
	cursor.Setc();

	openednow = false;

	if(openwin){
		int a=0;
		a++;
	}

	for (int x = 0; x < MAP_W; x++){
		for (int y = 0; y < MAP_H; y++){
			if (Event.LMouse.GetClick(100, 50, 100 + GRID_L*MAP_W, 50 + GRID_L*MAP_H) && stage.GetTownOwner(cursor.Getcx(), cursor.Getcy()) != -1 && !openwin){
				openwin = true;
				openednow = true;
				country = stage.GetTownOwner(cursor.Getcx(), cursor.Getcy());
				locationX=cursor.Getcx();
				locationY=cursor.Getcy();
			}
		}
	}

	if (openwin){
		DrawGraph(100, 50, window, true);

		DrawString(150, 100, "Type1", BLACK);

		DrawString(150, 150, "Type2", BLACK);

		DrawGraph(250, 95, unitpic[0], true);
		
		DrawGraph(250, 145, unitpic[1], true);

		for(int i=0;i<2;i++){
			if(cursor.Getmx()>145 && cursor.Getmx()<305 && cursor.Getmy()>95+i*50 && cursor.Getmy()<125+i*50){
				DrawBox(140,90+i*50,305,125+i*50,RED,false);
			}

			if(Event.LMouse.GetClick(145,95+i*50,305,125+i*50) && !openednow){
				for(int n=0;n<UNIT_NUM;n++){
					if(battle.unitm.country[country].unit[n].GetunitX()==-100){
						battle.unitm.country[country].unit[n].Product(locationX,locationY);
					}
				}

				openwin=false;
				country=-1;
			}
		}
	}
}
