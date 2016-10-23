#include"Music.h"

CMusic *music;

CMusic::CMusic(){
	sound[sPractice] = LoadSoundMem("Kawachi2/keyopen.mp3");
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

