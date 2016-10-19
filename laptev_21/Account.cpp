#include "stdafx.h"
#include "Account.h"


Account::Account()
{
	num = 0;
	name = "undefined";
	date = "undefined";
	amount = 0;
	percent = 0;
}


Account::~Account()
{}

Account::Account(int num, std::string name, std::string date,
	double amount, double percent)
{
	this->num = num;
	this->name = name;
	this->date = date;
	this->amount = amount;
	this->percent = percent;
}

std::ostream& operator <<(std::ostream& s, const Account &a)
{
	s << "Номер счета: " << a.num << "\nФИО: " << a.name << "\nДата открытия: " << a.date << "\nСумма на счете: " << a.amount << "\nПроцент: " << a.percent << endl;
	return s;
}

int Account::getnum()
{
	return num;
}
std::string Account::getname()
{
	return name;
}
std::string Account::getdate()
{
	return date;
}
double Account::getamount()
{
	return amount;
}
double Account::getpercent()
{
	return percent;
}