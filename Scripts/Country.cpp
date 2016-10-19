#include"DxLib.h"
#include"Suken.h"
#include"Country.h"
#include"General.h"

void CCountry::Awake(){
	money=100;
}

void CCountry::Pay(int num){
	money-=num;
}

void CCountry::Income(int num){
	money+=num;
}

bool CCountry::CanPay(int require){
	if(money>=require){
		return true;
	}else{
		return false;
	}
}

void CCountry::ShowMoney(int num){
	DrawFormatString(870,25+num*25,YELLOW,"%d",money);
}

void CCountry::GameOver(){
	for(int i=1;i<=UNIT_NUM;i++){
		unit[i].Setunit();
	}
} 
