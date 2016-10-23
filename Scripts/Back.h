#pragma once

#include"Suken.h"
#include"Picture.h"

class CBack{
private:

public:
	void DrawLine();

};

class CButtons{
private:
	CPicture picture;
	bool clickedClose;
	bool clickedSave;
	bool closed;
	bool saved;
	bool saveFin;

public:
	void Awake();
	void DrawButton();
	bool GetClosed();
	bool GetSaved();
};
