#include"Music.h"

CMusic *music;

CMusic::CMusic(){
	sound[sPractice] = LoadSoundMem("Chikuwa2/keyopen.mp3");
	sound[sMarch] = LoadSoundMem("Chikuwa2/March.mp3");
	sound[sHorse] = LoadSoundMem("Chikuwa2/Horse.mp3");
	sound[sWheel] = LoadSoundMem("Chikuwa2/Wheel.mp3");
	sound[sBoom] = LoadSoundMem("Chikuwa2/Boom.mp3");
	sound[sCrash] = LoadSoundMem("Chikuwa2/Crash.mp3");
	sound[sShoot] = LoadSoundMem("Chikuwa2/Shoot.mp3");
	sound[sStab] = LoadSoundMem("Chikuwa2/Stab.mp3");
	sound[sSlash] = LoadSoundMem("Chikuwa2/Slash.mp3");
	sound[sBow] = LoadSoundMem("Chikuwa2/Bow.mp3");
	sound[sSave] = LoadSoundMem("Chikuwa2/Save.mp3");
	sound[sLoad] = LoadSoundMem("Chikuwa2/Load.mp3");
	sound[sWinner] = LoadSoundMem("Chikuwa2/Winner.mp3");
	sound[sCountry1] = LoadSoundMem("Chikuwa2/Theme1.mp3");
	sound[sCountry2] = LoadSoundMem("Chikuwa2/Theme2.mp3");
	sound[sCountry3] = LoadSoundMem("Chikuwa2/Theme3.mp3");
	sound[sCountry4] = LoadSoundMem("Chikuwa2/Theme4.mp3");
	sound[sTitle] = LoadSoundMem("Chikuwa2/Title.mp3");
	memset(sFlag,false,sEnd);
	memset(loopFlag, false, sEnd);
}

void CMusic::AddSound(SoundList sound){
	sFlag[sound] = true;
}

void CMusic::Loop(SoundList sound) {
	if (loopFlag[sound] == false) {
		PlaySoundMem(this->sound[sound], DX_PLAYTYPE_LOOP);
		loopFlag[sound] = true;
	}
}

void CMusic::StopLoop(SoundList sound) {
	if (loopFlag[sound] == true) {
		StopSoundMem(this->sound[sound]);
		loopFlag[sound] = false;
	}
}

void CMusic::PauseLoop() {
	for (int i = 0; i < sEnd; i++) {
		if (loopFlag[i] == true) {
			StopSoundMem(this->sound[i]);
		}
	}
}

void CMusic::RestartLoop() {
	for (int i = 0; i < sEnd; i++) {
		if (loopFlag[i] == true) {
			PlaySoundMem(this->sound[i], DX_PLAYTYPE_LOOP,false);
		}
	}
}

void CMusic::Play(){
	for(int i = 0;i< sEnd;i++){
		if(sFlag[i] == true){
			PlaySoundMem(sound[i],DX_PLAYTYPE_BACK);
		}
		sFlag[i] = false;
	}

}

void AwakeMusic(){
	music =new CMusic();
}

