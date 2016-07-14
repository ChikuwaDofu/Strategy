#pragma once

#include"Suken.h"
#include"Unit.h"

class CCountry{
private:

public:
	CUnit unit[UNIT_NUM+1];
	void Pay(int num);
	bool CanPay(int require);
	void Income(int num);
	int money;
	void Awake();
	void ShowMoney(int num);

};
