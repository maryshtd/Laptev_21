// laptev_21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Account.h"
#include "Bank.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Bank Alfa;
	/*Account a(3, "Petrov", "21-10-2016", 3, 5);
	Alfa.AddAccount(a);*/
	Alfa.Display();
	
	//Alfa.DelAccount(3);
	//Alfa.Display();
	
	cout << "SEARCH BY NUM RESULTS" << endl;
	cout << "-----------------------------------" << endl;
	Alfa.FindByNum(2);
	cout << "\nSEARCH BY NAME RESULTS" << endl;
	cout << "----------------------------------"<<endl;
	
	Alfa.FindByName("Petrov");
	cout << "\nSEARCH BY DATE RESULTS" << endl;
	cout << "----------------------------------" << endl;
	Alfa.FindByDate("18.10.2016");
    return 0;
}

