// laptev_21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Account.h"
#include "Bank.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Bank Alfa;
	Account a(3, "Petrov", "21-10-2016", 3, 5);
	Alfa.AddAccount(a);
	Alfa.Display();
	
	//Alfa.DelAccount(3);
	//Alfa.Display();
	
	//Alfa.FindByNum(2);

	/*cout << "----------------------------------"<<endl;
	Alfa.FindByName("Ivanov");

	cout << "----------------------------------" << endl;
	Alfa.FindByDate("01-02-2016");*/
    return 0;
}

