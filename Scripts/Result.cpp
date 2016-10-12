#include"DxLib.h"
#include"Suken.h"
#include"Result.h"
#include"General.h"

void CResult::Awake(int winner){
	picture.LoadResultPic();

	lastOne = winner;
}

void CResult::DrawResult(){
	DrawGraph(0, 0, picture.result, true);

	DrawGraph(425, 275, picture.lFlag[lastOne], true);
}
