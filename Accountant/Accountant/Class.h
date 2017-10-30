#ifndef Accountant_Class_H
#define Accountant_Class_H
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;
/*

Klasa reprezentuj¹ca poszczególny rachunek

Metody umo¿liwiaj¹ zmianê lub zwrócenie poszczególnych parametrów

This class represents a particular bill

Methods allow to change a particular parameter or return a parameter

*/
float rounded(float v)
{
	/*
	Funkcja zaokr¹glaj¹ca liczbê do 2 miejsc po przecinku
	Zwraca zaokr¹glon¹ wartoœæ

	Function rounding number to 2 decimal places
	Returns a rounded value
	*/
	stringstream tmp;
	tmp << setprecision(2) << fixed << v;
	return stof(tmp.str());
}
class Bill
{
private:
	int _day;
	int _mounth;
	int _year;
	char * _thingname;
	float _net_amount;
	float _gross_amount;
	float _tax;
public:
	//konstruktor - constructor
	Bill(const string  tn, float ga, float t, int d, int m, int y) : _tax(t), _day(d), _mounth(m), _year(y)
	{
		_gross_amount = rounded(ga);
		_net_amount = rounded(ga / (1 + _tax / 100));
		_thingname = new char[tn.length() + 1];
		/*
		dynamiczny przydzia³ pamiêci
		dynamic memory allocation
		*/
		strcpy(_thingname, tn.c_str());
	}
	/*
	Program jest tak skonstruowany ¿e konstruktor domyœlny nie jest potrzebny
	Program is designed so that the default constructor is not needed
	*/

	//Destruktor - Destructor
	~Bill()
	{
	}

	////////////////////////////////////////////////
	char * thing_return() const
	{
		return _thingname;
	}

	float gross_amount_return() const
	{
		return _gross_amount;
	}

	float net_amount_return() const
	{
		return _net_amount;
	}

	float tax_return() const
	{
		return _tax;
	}
	int day_return() const
	{
		return _day;
	}
	int mounth_return() const
	{
		return _mounth;
	}
	int year_return() const
	{
		return _year;
	}

	//////////////////////////////////////////////
	void change_thing(const string new_thingname)
	{
		delete[] _thingname;
		_thingname = new char[new_thingname.length() + 1];
		strcpy(_thingname, new_thingname.c_str());
	}
	void change_gross_amount(const float new_gross_amount)
	{
		_gross_amount = rounded(new_gross_amount);
		_net_amount = rounded(_gross_amount / (1 + _tax / 100));
	}
	void change_tax(const float new_tax)
	{
		_tax = new_tax;
		_net_amount = rounded(_gross_amount / (1 + _tax / 100));
	}
	void change_day(const int new_day)
	{
		_day = new_day;
	}
	void change_mounth(const int new_mounth)
	{
		_mounth = new_mounth;
	}
	void change_year(const int new_year)
	{
		_year = new_year;
	}

	////////////////////////////////////////////////////////////
	friend ostream & operator<<(ostream & os, const Bill & st)
	{
		/*
		Reprezentacja klasy dopasowana do formatu wyœwietlania
		Class representation matched to the display format
		*/

		os << setfill(' ');
		os << setw(15) << left << st._thingname << setw(3) << " | ";
		os << setw(12) << left << st._gross_amount << setw(3) << " | ";
		os << setw(12) << left << st._net_amount << setw(3) << " | ";
		os << setw(15) << st._tax << setw(3) << " | ";
		os << setw(2) << right << st._day << setw(1) << " ";
		os << mounth_name[st._mounth - 1] << " " << st._year << "\n";

		return os;
	}
};
vector <Bill> bills;
#endif 
