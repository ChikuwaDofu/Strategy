#include"photon.h"
#include"Suken.h"
#include<DxLib.h>


int key[259];

int Mouse ,
	curtime,
	lasttime;

float	frametime;

char	tmpkey[256];

void GetKeyState(){

	Mouse = GetMouseInput();
	GetHitKeyStateAll( tmpkey );
	for( int i=0; i<256; i++ ){ 
		if( tmpkey[i] != 0 ){
			key[i]++;   
		} 
		else {key[i] = 0;}   
	}
	if((Mouse & MOUSE_INPUT_LEFT) != 0){
		key[MOUSE_LEFT]++;
	}
	else {key[MOUSE_LEFT] = 0;}
	if((Mouse & MOUSE_INPUT_RIGHT) != 0){
		key[MOUSE_RIGHT]++;
	}
	else {key[MOUSE_RIGHT] = 0;}
	if((Mouse & MOUSE_INPUT_MIDDLE) != 0){
		key[MOUSE_CENTER]++;
	}
	else {
		key[MOUSE_CENTER] = 0;
	}


}

int Key(int KEY){
	return key[KEY];
}
