#pragma once

#include"Suken.h"

enum SoundList {
	sPractice,
	sMarch,
	sHorse,
	sWheel,
	sBoom,
	sCrash,
	sShoot,
	sStab,
	sSlash,
	sBow,
	sSave,
	sLoad,
	sWinner,
	sCountry1,
	sCountry2,
	sCountry3,
	sCountry4,
	sTitle,
	sEnd
};

class CMusic{
private:
	int sound[sEnd];
	bool sFlag[sEnd];
	bool loopFlag[sEnd];

	CMusic();
public:
	void AddSound(SoundList sound);
	void Loop(SoundList sound);
	void StopLoop(SoundList sound);
	void PauseLoop();
	void RestartLoop();
	void Play();

	friend void AwakeMusic();
};

extern CMusic *music;
