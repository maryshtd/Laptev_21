#pragma once

struct Account
{
	int num;
	std::string name;
	std::string date;
	double amount;
	double percent;
public:
	Account();
	~Account();
	Account(int num, std::string name, std::string date,
		double amount, double percent);
	friend std::ostream& operator<<(std::ostream &s, const Account &a);
	int getnum();
	std::string getname();
	std::string getdate();
	double getamount();
	double getpercent();
};
