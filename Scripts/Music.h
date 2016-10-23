#include"Suken.h"

enum SoundList {
	sPractice,
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
