#ifndef Accountant_Sort_H
#define Accountant_Sort_H

#include "function.h"
enum sortingmode
{
	/*
	Tryby wy�wietlania

	Display modes
	*/

	alphabet_mode,
	amount_mode,
	data_mode,
};
enum min_max
{
	/*
	Kolejno�� wy�wietlania

	Przy trybie minimum najmiejsze warto�ci s� wy�wietlane na poczatku
	Przy trybie maximum najwi�ksze warto�ci s� wy�wietlane na poczatku


	Display order

	At minimum mode the smallest values will be displayed at the beginning
	At maximum mode the greatest values will be displayed at the beginning
	*/

	minimum,
	maximum,
};

bool RuleAlfabeat(const Bill r1, const Bill& r2)
{
	/*
	Regu�a Sortowania:

	Zwraca true je�eli pierwsza warto�� jest mniejsza w porz�dku alfabetycnym
	Zwraca false je�eli druga warto�� jest mniejsza w porz�dku alfabetycznym

	Sorting rule:

	Returns true if the first value is lower in alphabetical order
	Returns false if the second value is lower in alphabetical order

	*/
	return r1.thing_return() < r2.thing_return();
}

bool RuleAmount(const Bill r1, const Bill r2)
{
	/*
	Regu�a sortowania:

	Zwraca true je�eli pierwsza warto�c jest mniejsza pod wzgl�dem kwoty
	Zwraca false je�eli druga warto�� jest mniejsza pod wzgl�dem kwoty

	Sorting rule:

	Returns true if the first value is smaller in terms of the amount
	Returns false if the second value is smaller in terms of the amount

	*/

	return r1.gross_amount_return() < r2.gross_amount_return();
}

bool RuleDay(const Bill r1, const Bill r2)
{
	/*
	Regu�a Sortowania:

	Zwraca true je�eli pierwszy numer dnia jest mniejszy od drugiego
	Zwraca false je�eli drugi numer dnia jest mniejszy od pierwszego

	Sorting rule:

	Returns true if the first day number is less than the second
	Returns false if the second day number is less than the first
	*/
	return r1.day_return() < r2.day_return();
}

bool RuleMounth(const Bill r1, const Bill r2)
{
	/*
	Regu�a Sortowania:

	Zwraca true je�eli pierwszy numer miesi�ca jest mniejszy od drugiego
	Zwraca false je�eli drugi numer miesi�ca jest mniejszy ni� pierwszy

	Sorting rule:

	Returns true if the first mounth number is less than the second
	Returns false if the second mounth number is less than the first
	*/

	return r1.mounth_return() < r2.mounth_return();
}

bool RuleYear(const Bill r1, const Bill r2)
{
	/*
	Zasady sortowania:

	Zwraca true je�eli pierwszy rok jest mniejszy ni� drugi
	Zwraca false je�eli drugi rok jest mniejszy ni� pierwszy

	Sorting rule:

	Returns true if the first year is less than the second
	Returns false if the second year is less than the first

	*/

	return r1.year_return() < r2.year_return();
}

void sortchoice(sortingmode a, min_max b, vector<Bill> &r)
{
	/*
	Funkcja sortuj�ca wed�ug konkretnego trybu
	Sort function by specific mode
	*/

	if (a == alphabet_mode)
	{
		sort(r.begin(), r.end(), RuleAlfabeat);
	}
	else if (a == data_mode)
	{
		sort(r.begin(), r.end(), RuleDay);
		sort(r.begin(), r.end(), RuleMounth);
		sort(r.begin(), r.end(), RuleYear);
	}

	else
	{
		sort(r.begin(), r.end(), RuleAmount);
	}
	if (b == maximum)
	{
		reverse(r.begin(), r.end());
	}
}
void display_bills(const vector <Bill> b)
{
	/*
	Funkcja wy�wietlaj�ca bie��c� list� rachunk�w oraz sum� kwot brutto i netto

	Function displaying the current list of bills and the sum of gross and net amounts
	*/

	cout << "\n";
	cout << "Lista rachunk\242w: " << "\n";

	cout << setfill(' ');
	cout << setw(3) << left << "LP " << setw(3) << " | ";
	cout << setw(15) << left << "Nazwa" << setw(3) << " | ";
	cout << setw(12) << left << "Kwota Brutto" << setw(3) << " | ";
	cout << setw(12) << left << "Kwota Netto" << setw(3) << " | ";
	cout << setw(15) << left << "Procent Podatku" << setw(3) << " | ";
	cout << setw(20) << left << "Data" << "\n";
	cout << setfill('-');
	cout << setw(92) << "" << "\n";

	unsigned short i;
	net_sum = 0;
	gross_sum = 0;

	cout << setfill(' ');
	for (i = 0; i < b.size(); i++)
	{
		cout << setw(3) << right << i + 1 << setw(3) << " | ";
		cout << b[i];
		gross_sum += b[i].gross_amount_return();
		net_sum += b[i].net_amount_return();
	}

	cout << setfill('-');
	cout << setw(92) << "" << "\n";
	cout << setfill(' ');
	cout << setw(6) << right << " | ";
	cout << setw(18) << right << " | ";
	cout << setw(12) << left << gross_sum << setw(3) << " | ";
	cout << setw(12) << left << net_sum << setw(3) << " | ";
	cout << setw(18) << right << " | ";

	cout << "\n\n";
}
void selection(vector<Bill> &r)
{
	/*
	Funcja umo�liwia wyb�r trybu sortowania i kolejno�� wy�wietlania

	Function allows to select the sort mode and display order
	*/

	string choice1;	//wyb�r kolejno�ci wy�wietlania
	string choice2;	//wy�wietlanie od najmniejszych b�d� najwi�kszych warto�ci
	while (true)
	{
		menu2();
		string_format(choice1);
		if (choice1.compare("1") == 0)
		{
			cout << "W jakiej kolejno\230ci wy\230wietli\206 rachunki:" << "\n";
			cout << "A/a - Od pocz\245tku alfabetu, B/b - od ko\344ca alfabetu, Q/q - Powr\242t do menu" << "\n";

			string_format(choice2);

			while (choice2.compare("A") != 0 && choice2.compare("B") != 0 && choice2.compare("Q") != 0)
			{
				cout << "\215le podana warto\230\206, spr\242buj ponownie" << "\n";

				cout << "W jakiej kolejno\230ci wy\230wietli\206 rachunki:" << "\n";

				cout << "A/a - Od pocz\245tku alfabetu, B/b - od ko\344ca alfabetu, Q/q - Powr\242t do menu" << "\n";

				string_format(choice2);
			}
			if (choice2.compare("A") == 0)
			{
				sortchoice(alphabet_mode, minimum, r);
				//kolejno�� alfabetyczna od A do Z
			}
			else if (choice2.compare("B") == 0)
			{
				sortchoice(alphabet_mode, maximum, r);
				//kolejno��  alfabetyczna od Z do A
			}
			break;
		}
		if (choice1.compare("2") == 0)
		{
			cout << "W jakiej kolejno\230ci wy\230wietli\206 rachunki:" << "\n";
			cout << "A/a - Najta\344sze, B/b - Najdro\276sze, Q/q - Powr\242t do menu" << "\n";
			string_format(choice2);

			while (choice2.compare("A") != 0 && choice2.compare("B") != 0 && choice2.compare("Q") != 0)
			{
				cout << "\215le podana warto\230\206, spr\242buj ponownie" << "\n";
				cout << "W jakiej kolejno\230ci wy\230wietli\206 rachunki:" << "\n";
				cout << "A/a - Najta\344sze, B/b - Najdro\276sze, Q/q - Powr\242t do menu" << "\n";
				string_format(choice2);
			}
			if (choice2.compare("A") == 0)
			{
				sortchoice(amount_mode, minimum, r);
				//wy�wietlanie wed�ug kwoty od najta�szych do najdro�szych
			}
			else if (choice2.compare("B") == 0)
			{
				sortchoice(amount_mode, maximum, r);
				//wy�wietlanie wed�ug kwoty od najdro�szych do najta�szych
			}
			break;
		}

		if (choice1.compare("3") == 0)
		{
			cout << "W jakiej kolejno\230ci wy\230wietli\206 rachunki" << "\n";
			cout << "A/a - Najstarsze, B/b - Najm\210odsze, Q/q - Powr\242t do menu" << "\n";
			string_format(choice2);

			while (choice2.compare("A") != 0 && choice2.compare("B") != 0 && choice2.compare("Q") != 0)
			{
				cout << "\215le podana warto\230\206, spr\242buj ponownie" << "\n";
				cout << "W jakiej kolejno\230ci wy\230wietli\206 rachunki:" << "\n";
				cout << "A/a - Najstarsze, B/b - Najm\210odsze, Q/q - Powr\242t do menu" << "\n";
				string_format(choice2);
			}
			if (choice2.compare("A") == 0)
			{
				sortchoice(data_mode, minimum, r);
				//wy�wietlanie wed�ug daty, od najstarszych do najm�odszych
			}
			else if (choice2.compare("B") == 0)
			{
				sortchoice(data_mode, maximum, r);
				//wy�wietlanie wed�ug daty, od najm�odszych do najstarszych 
			}
			break;
		}
		if (choice1.compare("Q") == 0)
		{
			cout << "Nast\251puje powr\242t do menu g\210\242wnego" << "\n\n";
			break;
		}
		cout << "\215le podana warto\230\206, spr\242buj ponownie" << "\n";
	}
}

int bills_display_options(vector <Bill> &r)
{
	string choice1;
	/*
	Funckja wy�wietla rachunki, mo�na r�wnie� wr�ci� do menu

	Funkcja zwraca 1 gdy rachunki zosta�y wy�wietlone, lub -1 je�eli u�ytkownik chce wr�ci� do menu


	Function displays the bills, you can also go back to main menu

	The function returns 1 when bills were displayed, or -1 if the user wants to go back to the menu
	*/
	if (r.size() == 1)
	{
		display_bills(r);
		return 1;
	}

	cout << "Czy chcesz posortowa\206 rachunki, T/t - tak, N/n - nie, Q/q - Powr\242t do menu g\210\242wnego" << " \n ";
	string_format(choice1);

	while (choice1.compare("T") != 0 && choice1.compare("N") != 0 && choice1.compare("Q") != 0)
	{
		cout << "\215le podana warto\230\206, spr\242buj ponownie" << "\n";
		cout << "Czy chcesz posortowa\206 rachunki N/n - nie, T/t - tak, Q/q - Powr\242t do menu g\210\242wnego" << "\n";
		string_format(choice1);
	}

	if (choice1.compare("Q") == 0) { return -1; }
	//u�ytkownik chce powr�ci� do menu g��wnego
	if (choice1.compare("T") == 0)
	{
		selection(r);
		display_bills(r);
		return  1;
	}
	display_bills(r);

	return 1;
}
///////////////////////////////
#endif 
