#include "stdafx.h"
#include "Bank.h"
#include "SQLAPI.h"

Bank::Bank()
{
	LoadData();
}


Bank::~Bank()
{}

void Bank::LoadData()
{
	SAConnection con;
	con.Connect("Bank", "sa", "student", SA_SQLServer_Client);
	
	SACommand cmd(&con, "SELECT * FROM Accounts");
	cmd.Execute();

	while (cmd.FetchNext()) //забираем результаты селект-запроса
	{
		Account a(cmd.Field("id").asLong(), 
			cmd.Field("name").asString().GetMultiByteChars(), 
			cmd.Field("date").asString().GetMultiByteChars(), 
			cmd.Field("amount").asDouble(), 
			cmd.Field("perrcent").asDouble());
		v.push_back(a);
	}

	con.Disconnect();
}

void Bank::AddAccount(const Account a)
{
	v.push_back(a);

	//запись данных в базу
	SAConnection con;
	con.Connect("Bank", "sa", "student", SA_SQLServer_Client);
	try
	{
	char buff[1000];
	sprintf_s(buff, 100,
			"INSERT INTO Accounts(name,date,amount,perrcent) VALUES ('%s','%s',%.0f,%.0f)",
			a.name.c_str(), a.date.c_str(), a.amount, a.percent);
	
	SACommand cmd(&con, buff);
	/*SACommand cmd(&con, "INSERT INTO Accounts (name,date,amount,perrcent) VALUES (:1,:2,:3,:4)");
	cmd.Param(1).setAsString() = "q";
	cmd.Param(2).setAsString() = "q";
	cmd.Param(3).setAsDouble() = 1.00;
	cmd.Param(4).setAsDouble() = 1.00;*/
	cmd.Execute();
	
	con.Commit();
	con.Disconnect();
	}
	catch (SAException &x)
	{
		try
		{
			// on error rollback changes
			con.Rollback();
		}
		catch (SAException &)
		{
		}
		// print error message
		printf("%s\n", (const char*)x.ErrText());
	}
}
void Bank::DelAccount(int n) //удаление аккаунта по индексу
{
	auto r = v.begin();
	v.erase(r+n);

}
void Bank::FindByNum(int num)
{
	//for (int i = 0; i<v.size(); i++) //вариант 1
	//{
	//	if (v[i].num == num)
	//	{
	//		std::cout << v[i] << endl;
	//	}
	//}

	auto p = std::find(v.begin(),v.end(),num); //вариант 2
	if (p == v.end())
		cout << "Account was not found" << endl;
	else
		cout << *p;

}
void Bank::FindByName(std::string name)
{
	/*for (int i = 0; i<v.size(); i++)
	{
		if (v[i].name == name)
		{
			std::cout << v[i] << endl;
		}
	}*/

	auto p = v.begin();

	while (p != v.end())
	{
		p = std::find(p, v.end(), name);
		if (p == v.end())
		{
			cout << "Account was not found" << endl;
			break;
		}
		else
			cout << *p << endl;
		p++;
	}
}
void Bank::FindByDate(std::string dateX)
{
	/*for (int i = 0; i<v.size(); i++)
	{
		if (v[i].date == date)
		{
			std::cout << v[i] << endl;
		}
	}*/

	FindDate = dateX;
	auto p = v.begin();;
	while (p != v.end())
	{
		p = std::find_if(p, v.end(), Date);
		if (p == v.end())
		{
			cout << "Account was not found" << endl;
			break;
		}
		else
			cout << *p << endl;
		p++;
	}
}

void Bank::Display()
{
	/*for (int i = 0;i<v.size();i++) //вариант 1
	{
		std::cout << v[i] << endl;
	}*/

	std::ostream_iterator<Account> output(cout, "\n"); //вариант 2. ostream_iterator - поток вывода из вектора
	std::copy(v.begin(), v.end(),output);

}

std::string Bank::FindDate = "";

bool Date(const Account &x)
{
	return (x.date == Bank::FindDate);
}