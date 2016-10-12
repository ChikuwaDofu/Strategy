#pragma once

#include"Suken.h"
#include "Picture.h"

class CResult{
private:
	CPicture picture;
	int lastOne;

public:
	void Awake(int winner);
	void DrawResult();

};
