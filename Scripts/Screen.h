#pragma once

#include"Suken.h"
#include"Files.h"

class CScreen{
private:
	CFiles file;

public:
	CScreen();
	void SetStage();
	int adjX;//adjust
	int adjY;
	void MoveAdj(int stage);

};
