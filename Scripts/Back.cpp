#include"DxLib.h"
#include"Suken.h"
#include"Back.h"
#include"General.h"

void CBack::DrawLine(){
	for(int i=100 ; i<=800 ; i+=GRID_L){
		DrawBox(i,50,i+1,551,WHITE,true);
	}
	for(int i=50 ; i<=550 ; i+=GRID_L){
		DrawBox(100,i,800,i+1,WHITE,true);
	}
}

void CButtons::Awake(){
	picture.LoadButtonPic();

	clickedClose=false;
	clickedSave=false;
	saveFin=false;
}

void CButtons::DrawButton(){
	closed=false;

	DrawGraph(870,0,picture.closeButton[0],true);

	if(clickedClose){
		if(!Event.LMouse.GetOn(870,0,900,30)){
			clickedClose=false;
		}

		DrawGraph(870,0,picture.closeButton[1],true);

		if(Event.LMouse.GetClick(870,0,900,30)){
			closed=true;
		}

	}else if(Event.LMouse.GetClick(870,0,900,30)){
		clickedClose=true;
	}

	saved=false;

	DrawGraph(300,0,picture.saveButton[0],true);

	if(clickedSave){
		if(!Event.LMouse.GetOn(300,0,360,30)){
			clickedSave=false;
		}

		DrawGraph(300,0,picture.saveButton[1],true);
		
		if(Event.LMouse.GetClick(300,0,360,30)){
			saved=true;
			saveFin=true;
			clickedSave=false;
		}

	}else if(Event.LMouse.GetClick(300,0,360,30) && !clickedSave){
		clickedSave=true;
	}

	if(saveFin){
		DrawGraph(300,0,picture.saveButton[2],true);

		if(!Event.LMouse.GetOn(300,0,360,30)){
			saveFin=false;
		}
	}
}

bool CButtons::GetClosed(){
	return closed;
}

bool CButtons::GetSaved(){
	return saved;
}
