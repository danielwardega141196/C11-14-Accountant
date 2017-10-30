#ifndef Accountant_function_H
#define Accountant_function_H
#include "Menus.h"
#include "Class.h"

SYSTEMTIME st;

bool empty_list(const vector <Bill> r)
{
	/*
	Funkcja zwraca -1 je¿eli lista rachunków jest pusta lub 1 gdy zawiera jakiœ rachunek
	The function returns -1 if the list of bills is empty or 1 when contains a bill
	*/
	if (r.size() == 0)
	{
		cout << "Aktualnie nie zosta\210y wprowadzone \276adne rachunki" << "\n";
		cout << "Nast\251puje powr\242t do menu g\210\242wnego" << "\n\n";
		return true;
	}
	return false;
}
bool is_positive_float(const string s)
{

	/*
	Funkcja sprawdza czy dany string jest typu float i czy jego wartoœæ jest wiêksza b¹dŸ równa zero
	Zwraca true - je¿eli dany string jest typu float i jest wiêkszy b¹dŸ równy zero

	Function check that if given string is float and float is greater than or equal to zero.
	Return true - if given string is float and float is greater than or equal to zero, false - if not
	*/
	unsigned short i;

	unsigned short dot_counter = 0;

	for (i = 0; i < s.length(); i++)
	{
		if (s[i] == '.')
		{
			++dot_counter;
		}
		if (dot_counter == 2)
		{
			/*
			Float mo¿e zawieraæ tylko 1 kropkê
			Float can contain only 1 dot
			*/
			return false;
		}
		if (isdigit(s[i]) == false && s[i] != '.')
		{
			return false;
		}
	}
	return true;
}

void string_format(string &s, bool g = true, bool e = true, bool t = true)
{
	/*
	Funckja umozliwia :
	- wprowadzenie wartoœci - g
	- usuniêcie spacji - e
	- zmianê ca³ego tekstu na du¿e litery - t

	Function allows to :
	- enter values - g
	- remove spaces - e
	- change all text to uppercase - t
	*/

	if (g == true)
	{
		/*
		Wczytanie wartoœci do podanego string
		Loading values to specified string
		*/
		getline(cin, s);
	}
	if (e == true)
	{
		/*
		Usuniêcie spacji
		Removing spaces
		*/
		s.erase(remove(s.begin(), s.end(), ' '), s.end());
	}
	if (t == true)
	{
		/*
		Zamiana na du¿e litery
		Conversion to uppercase
		*/
		transform(s.begin(), s.end(), s.begin(), ::toupper);
	}
}
string thingname_setter()
{
	/*
	Funkcja ustala nazwê dla danej pozycji
	Zwraca prwid³ow¹ nazwê dla danej pozycji
	Nazwa nie moe byæ d³u¿sza ni¿ 15 znaków

	Function sets the name of the item
	Return correct name of the item
	The name can not be longer than 15 characters
	*/

	string thing;
	cout << "Podaj nazw\251 przedmiotu " << "\n";

	getline(cin, thing);

	while (thing.length() == 0)
	{
		cout << "Przedmiot musi posiadac nazw\251" << "\n";
		cout << "Wprowad\253 jego nazw\251" << "\n";
		getline(cin, thing);
	}

	if (thing.length() > 15)
	{
		/*
		Usuniêcie zbêdnych liter
		Removing unnecessary letters
		*/
		thing.erase(15, thing.length());
	}
	return thing;
}
///////////////////////////////////////
float gross_amount_setter()
{
	/*
	Funkcja ustala kwotê dla danej pozycji, kwota musi byæ wiêksza lub równa zero
	Zwraca:
	Poprawn¹ kwotê przedmiotu zaokr¹glon¹ do 2 miejsc po przecinku(float) lub -1 je¿eli u¿ytkownik chce wróciæ do menu


	Function sets the value of the item, the value must be greater than or equal to zero
	Return:
	Correct value of the item rounded to 2 decimal places(float) or -1 if user wants to go back to the menu
	*/

	string amount_s;

	while (true)
	{
		cout << "Wprowad\253 kwot\251 brutto przedmiotu, wci\230nij Q/q - aby wr\242ci\206 do menu" << "\n";
		getline(cin, amount_s);
		if (amount_s.length() == 0)
		{
			cout << "Nie podano ¿adnej kwoty" << "\n";
			cout << "Wprowad\253 kwot\251 brutto przedmiotu, wci\230nij Q/q - aby wr\242ci\206 do menu" << "\n";
			continue;
		}

		string_format(amount_s, false, true, true);
		/*
		Usuniêcie spacji i zamiana tekstu na du¿e litery
		Removing spaces and changing text to uppercase
		*/

		if (amount_s.compare("Q") == 0)
		{
			/*
			U¿ytkownik chce powróciæ do menu g³ównego
			The user wants to return to the main menu
			*/
			return -1;
		}
		if (is_positive_float(amount_s) == false)
		{
			cout << "Podana warto\230\206 nie jest liczb\245 nieujemn\245" << "\n";
			continue;
		}
		else
		{
			return stof(amount_s);
		}
	}
}
///////////////////////////////
float tax_setter()
{
	/*
	Funkcja ustala odpowiedni procent podatku dla danego przedmiotu od 0 do 100 %
	Zwraca:
	Prawid³owy procent podatku zaokr¹glony do dwóch miejsc po przecinku(float) lub -1 je¿eli u¿ytkownik chce wróciæ do menu

	Function sets the appropriate percentage of tax for the item from 0 to 100 %
	Return:
	Correct percentage of tax rounded to 2 decimal places(float) or -1 if user wants to go back to the menu

	*/
	string tax;

	while (true)
	{
		cout << "Podaj procent podatku(od 0 do 100) lub wci\230nij Q/q aby wr\242ci\206 do menu" << "\n";
		getline(cin, tax);
		if (tax.length() == 0)
		{
			cout << "Nie podano \276adnej warto\230ci" << "\n";
			continue;
		}
		string_format(tax, false, true, true);
		/*
		Usuniêcie spacji i zamiana tekstu na du¿e litery
		Removing spaces and changing text to uppercase
		*/
		if (tax.compare("Q") == 0)
		{
			/*
			U¿ytkownik chce powróciæ do menu g³ównego
			The user wants to return to the main menu
			*/
			return -1;
		}
		if (is_positive_float(tax) == false || stof(tax) > 100)
		{
			cout << "Podano nieprawid\210ow\245 warto\230\206" << "\n";
			continue;
		}
		return stof(tax);
	}
}
/////////////////////////////////
int year_setter()
{
	/*
	Funkcja ustala odpowiedni rok dla danej pozycji, rok powinien byæ pomiêdzy 1900 a 2100
	Zwraca:
	Poprawny rok lub -1 je¿eli u¿ytkownik chce wróciæ do menu
	Je¿eli u¿ytkownik wciœnie tylko Enter, ustawiony zostanie aktualny rok

	Function sets the appropriate year for the item, the year should be between 1900 and 2100
	Return:
	Correct year or -1 if user wants to go back to the menu
	If user press only Enter, current year will be set
	*/

	string year;
	while (true)
	{
		cout << "Podaj rok, wci\230nij tylko Enter aby wprowadzi\206 akualny, Q/q aby wr\242ci\206 do menu" << "\n";

		cout << "Rok musi by\206 pomi\251dzy 1900 a 2100" << "\n";

		getline(cin, year);

		if (year.length() == 0)
		{
			/*
			When user wants to set the current year
			Kiedy u¿ytkownik chce ustaliæ aktualny rok
			*/
			return st.wYear;
		}
		string_format(year, false, true, true);
		/*
		Usuniêcie spacji i zamiana tekstu na du¿e litery
		Removing spaces and changing text to uppercase
		*/
		if (year.compare("Q") == 0)
		{
			/*
			U¿ytkownik chce powróciæ do menu g³ównego
			The user wants to return to the main menu
			*/
			return -1;
		}

		if (all_of(year.begin(), year.end(), ::isdigit) && stoi(year) >= 1900 && stoi(year) <= 2100)
		{
			/*
			Appropriate year
			Poprawny rok
			*/
			return stoi(year);
		}
		cout << "\215le podana warto\230\206, spr\242bjuj ponownie" << "\n";
	}
}
int monuth_setter()
{
	/*
	Funckja ustala w³aœciwy numer miesi¹ca od 1 do 12
	Zwraca:
	W³aœciwy numer miesi¹ca lub -1 gdy u¿ytkownik chce wróciæ do menu
	Je¿eli u¿ytkownik wciœnie tylko Enter, zwrócony zostanie aktualny numer miesi¹ca
	U¿ytkownik mo¿e wprowadziæ wartoœæ od 1 do 12.

	Function sets the appropriate mounth number from 1 to 12
	Return:
	Correct mounth number or -1 if user wants to go back to the menu
	If user press only Enter, current mounth will be set
	User can enter value from 1 to 12
	*/
	string mounth;

	while (true)
	{
		cout << "Podaj numer miesi\245ca 1 - 12, wci\230nij Enter aby wprowadzi\206 aktualny, Q/q - aby wr\242ci\206 do menu" << "\n";
		getline(cin, mounth);
		if (mounth.length() == 0)
		{
			/*
			When user wants to set the current mounth
			Kiedy u¿ytkownik chce ustaliæ aktualny miesi¹c
			*/
			return st.wMonth;
		}

		string_format(mounth, false, true, true);
		/*
		Usuniêcie spacji i zamiana tekstu na du¿e litery
		Removing spaces and changing text to uppercase
		*/
		if (mounth.compare("Q") == 0)
		{
			/*
			U¿ytkownik chce powróciæ do menu g³ównego
			The user wants to return to the main menu
			*/
			return -1;
		}
		if (all_of(mounth.begin(), mounth.end(), ::isdigit) == true && stoi(mounth) >= 1 && stoi(mounth) <= 12)
		{
			/*
			Odpowiedni numer miesi¹ca
			Appropriate mounth number
			*/
			return stoi(mounth);
		}
		cout << "\215le podana warto\230\206, spr\242bjuj ponownie" << "\n";
	}
}
int day_setter(const int m, const int y)
{
	/*
	Funckja ustala w³aœciwy dzieñ
	Funckja bierze pod uwagê liczbê dni ka¿dego miesi¹ca oraz 29 Luty roku przestêpnego
	Zwraca:
	W³aœciwy numer dnia lub -1 je¿eli u¿ytkownik chce wróciæ do menu
	Je¿eli u¿ytkownik wciœnie tylko Enter, ustawiony zostanie aktualny dzieñ


	Function sets the appropriate day number
	The function takes into account the number of days of each month and 29 February in the leap year
	Return:
	Correct day number or -1 if user wants to go back to the menu
	If user press only Enter, current day will be set
	*/
	string day;

	int days_of_mounth;

	while (true)
	{
		cout << "Rok: " << y << " Miesi\245c: " << mounth_name[m - 1] << "\n";
		cout << "Podaj numer dnia, wci\230nij Enter aby wprowadzi\206 aktualny dzie\344, Q/q - aby wr\242ci\206 do menu" << "\n";
		getline(cin, day);

		if (day.length() == 0)
		{
			/*
			When user wants to set the current day
			Kiedy u¿ytkownik chce ustaliæ aktualny dzieñ
			*/
			return st.wDay;
		}
		string_format(day, false, true, true);
		/*
		Usuniêcie spacji i zamiana tekstu na du¿e litery
		Removing spaces and changing text to uppercase
		*/
		if (day.compare("Q") == 0)
		{
			/*
			U¿ytkownik chce powróciæ do menu g³ównego
			The user wants to return to the main menu
			*/
			return -1;
		}
		if ((m == 2) && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
			/*
			Warunki dla roku przestêpnego
			Leap year conditions
			*/
		{
			days_of_mounth = mounth_length[m - 1] + 1;
		}
		else
		{
			days_of_mounth = mounth_length[m - 1];
		}
		if (all_of(day.begin(), day.end(), ::isdigit) == true && stoi(day) >= 1 && stoi(day) <= days_of_mounth)
		{
			/*
			Odpowiedni numer dnia
			Appropriate day number
			*/
			return stoi(day);
		}
		cout << "\215le podana warto\230\206, spr\242bjuj ponownie" << "\n";
	}
}
//////////////////////////////////////////////////
int searchmonthindex(const string m)
{
	/*
	Funkcja zwraca numer podanego miesi¹ca od 1 do 12 lub -1 gdy zosta³a podana z³a wartoœæ
	The function returns the number of the given month from 1 to 12 or -1 when the value is incorrect
	*/
	unsigned short i;
	for (i = 1; i <= 12; i++)
	{
		if (mounth_name[i] == m) { return i; }
	}
	return -1;
}
///////////////////////////////////////////////
Bill divide_line(string line)
{
	/*
	Funckja dzieli liniê z pliku na pojedyncze wed³ug spacji wartoœci i zwraca nowy objekt klasy Bill

	Function divides lines from a file into individual values and creates an object of the Bill class
	*/

	string thingname;

	float gross_amount;
	float tax;
	int day;
	int mounth;
	int year;

	int counter = 0;
	istringstream iss(line);
	/*
	Pojedyncza linia rozdzielona spacjami
	Single line split by space
	*/

	string templine;
	while (iss)
	{
		iss >> templine;

		/*
		Przypisanie ka¿dego z elementów
		Assignment of each item
		*/

		switch (counter)
		{
		case 1:
			/*
			Zaczynamy od 1 poniewa¿ nie bierzemy liczby porz¹dkowej pod uwagê
			We start from 1 because we do not take the ordinal number into account
			*/
			thingname = templine;
			break;
		case 2:
			gross_amount = stof(templine);
			break;
		case 3:
			break;
		case 4:
			tax = stof(templine);
			break;
		case 5:
			day = stoi(templine);
			break;
		case 6:
			mounth = searchmonthindex(templine);
			break;
		case 7:
			year = stoi(templine);
			break;
			/*
			W tym miejscu funkcja zakoñczy dzia³anie, gdy¿ nie ma dalszych wartoœci
			At this point, the function will exit because there are no more values
			*/

		default:
			break;
		}
		++counter;
	}

	Bill r2 = Bill(thingname, gross_amount, tax, day, mounth, year);
	return r2;
}
//////////////////////////////////////////////////

enum mod_rem
{
	/*
	Tryby operacji na istniej¹cych ju¿ rachunkach
	remove_mode - usuniêcie danego rachunku
	modify_mode - modyfikacja konkretnej pozycji w danycmm rachunku
	*/

	remove_mode,
	modify_mode,
};

int bill_index_select(mod_rem mr, const vector <Bill> b)
{
	/*
	Funkcja ustala prawid³owy numer dla jednego z rachunków w bie¿¹cej liœcie lub wskazuje na powrót do menu

	The function sets the correct number of one of the bills in the current list or indicates return to menu
	*/

	string info1;
	string info2;
	string choice1;
	string choice2;
	if (mr == remove_mode)
	{
		info1 = "Czy chcesz usun\245\206 ten rachunek\nT/t - tak, Q/q - Powr\242t do menu";
		info2 = "Podaj numer rachunku, kt\242ry chcesz usun\245\206, wci\230nij Q/q - aby wr\242ci\206 do menu";
	}
	else
	{
		info1 = "Czy chcesz edytowa\206 ten rachunek\nT/t - tak, Q/q - Powr\242t do menu";
		info2 = "Podaj numer rachunku, kt\242ry chcesz zmodyfikowa\206 , wci\230nij Q/q - aby wr\242ci\206 do menu";
	}
	if (b.size() == 1)
	{
		while (true)
		{
			cout << info1 << "\n";
			getline(cin, choice1);
			if (choice1.length() == 0)
			{
				cout << "Nie podano \276adnej warto\230ci" << "\n";
				continue;
			}
			string_format(choice1, false, true, true);

			if (choice1.compare("Q") == 0) { return -1; }
			/*
			U¿ytkownik chce powróciæ do menu g³ównego
			The user wants to return to the main menu
			*/
			if (choice1.compare("T") == 0)
			{
				cout << "Czy chcesz usun¹æ t¹ pozycjê, wciœnij T/t aby usun¹æ rachunek, Q/q - aby powróciæ do menu" << "\n";
				string_format(choice2);
				while (choice2.compare("T") != 0 && choice2.compare("Q") != 0)
				{
					cout << "\215le podana warto\230\206, spróbuj ponownie" << "\n";
					cout << "Czy chcesz usun¹æ t¹ pozycjê, wciœnij T/t aby usun¹æ rachunek, Q/q - aby powróciæ do menu" << "\n";
					string_format(choice2);
				}
				if (choice2.compare("Q") == 0)
				{
					/*
					U¿ytkownik chce powróciæ do menu g³ównego
					The user wants to return to the main menu
					*/
					return -1;
				}
				return 0;
			}
			cout << "\215le podana warto\230\206, spr\242buj ponownie" << "\n";
		}
	}
	else
	{
		while (true)
		{
			cout << info2 << "\n";
			getline(cin, choice1);

			if (choice1.length() == 0)
			{
				cout << "Nie podano \276adnej warto\230ci" << "\n";
				continue;
			}
			string_format(choice1, false, true, true);
			//usuniêcie spacji i zamiana na du¿e litery

			if (choice1.compare("Q") == 0) { return -1; }
			//u¿ytkownik chce powróciæ do menu g³ównego

			if (all_of(choice1.begin(), choice1.end(), ::isdigit) == true && stoul(choice1) >= 1 && stoul(choice1) <= b.size())
			{
				cout << "Czy chcesz usun¹æ t¹ pozycjê, wciœnij T/t aby usun¹æ rachunek, Q/q - aby powróciæ do menu" << endl;

				string_format(choice2);
				while (choice2.compare("T") != 0 && choice2.compare("Q") != 0)
				{
					cout << "\215le podana warto\230\206, spróbuj ponownie" << "\n";
					cout << "Czy chcesz usun¹æ t¹ pozycjê, wciœnij T/t aby usun¹æ rachunek, Q/q - aby powróciæ do menu" << endl;
					string_format(choice2);
				}
				if (choice2.compare("Q") == 0)
				{
					/*
					U¿ytkownik chce powróciæ do menu g³ównego
					The user wants to return to the main menu
					*/
					return -1;
				}
				return stoul(choice1) - 1;
			}
			//numer rachunku z listy 

			cout << "\215le podana warto\230\206, spr\242buj ponownie" << "\n";
		}
	}
}
bool fexists(const string filename)
{
	/*
	Funckja sprawdza czy istnieje plik o podanej nazwie

	Zwraca true je¿eli istnieje lub false je¿eli nie

	This function checks if the given file exists

	Return true if file exist or false if file doesn't exist
	*/

	ifstream ifile(filename);

	return (bool)ifile;
}
#endif
