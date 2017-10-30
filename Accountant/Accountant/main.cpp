#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>
#include <algorithm>
#include "Sort.h"

/*
Program w³asnego autorstwa s³u¿y, który s³u¿y  do sk³adowania rachunków.

Poszczególny rachunek sk³ada siê z:

- Nazwy,
- Kwoty brutto,
- Procentu podatku,
- Daty(numer dnia,numer miesi¹ca, rok)

Kwota netto zostaje obliczona automatycznie

Program posiada mo¿liwoœæ :
- wprowadzenia rachunku
- wyœwietlenia wszystkich pozycji
- usuniêcia konkretnej pozycji
- modyfikacj konkretnego rachunku
- zapisu aktulnej listy rachunków do pliku
- wczytania rachunków z pliku

Uzytkownik w trakcie wykonywania konkretnego dzia³ania mo¿e wróciæ do menu g³ównego.

Program przyjmuje od u¿ytkownika tylko poprawne wartoœci.



Program designed to store bills.

The individual bill consists of:

- Name,
- Gross amount,
- Percent of tax,
- Date (day number, month number, year)

The net amount is calculated automatically



The program has the ability to:

- Add the bill,
- Display all the items,
- Remove specific items,
- Modify particular items,
- Save the current list of bills to a file,
- Loading bills from a file



The user can go back to the main menu while executing a specific action.

The program will only accept the correct values from the user.

*/

int main()
{
	vector <string> options = { "A","B","C","D","E","F","G","H" };

	vector <string> options2 = { "1","2","3","4" };

	string choice;

	string thingname;
	float gross_amount;
	float tax;
	int day;
	int mounth;
	int year;

	int position; //index konkretnego rachunku

	while (true)
	{
		menu1();	//Menus.h

		cout << "Podaj sw\242j wyb\242r" << "\n";

		string_format(choice); //Sort.h

		if (choice.compare("A") == 0)
		{
			/*

			W tym podpunkcie zostaje utworzony nowy rachunek oraz dodany do aktualnej listy

			In this section a new account is created and added to the current list

			*/

			GetLocalTime(&st);

			/*
			Pobranie aktualnego czasu

			Get the current time
			*/

			thingname = thingname_setter();	//function.h

											/*
											Nazw¹ przedmiotu mo¿e byæ Q / q

											Name of the thing may be Q / q
											*/

			gross_amount = gross_amount_setter(); if (gross_amount == -1) { continue; }//function.h
																					   /*
																					   Je¿eli u¿ytkownik chce wróciæ do menu funkcje zwracaj¹ -1

																					   If user want to go back to menu, the functions return -1

																					   */
			tax = tax_setter(); if (tax == -1) { continue; }//function.h

			year = year_setter();  if (year == -1) { continue; }//function.h

			mounth = monuth_setter(); if (mounth == -1) { continue; }//function.h

			day = day_setter(mounth, year); if (day == -1) { continue; }//function.h

			Bill *r1 = new Bill(thingname, gross_amount, tax, day, mounth, year);

			bills.push_back(*r1);

			delete r1;
		}
		else if (choice.compare("B") == 0)
		{
			/*
			- Nastêpuje wyœwietlenie wszystkich pozycji

			- All items are displayed
			*/

			if (empty_list(bills) == true) { continue; }	//function.h

			bill = bills_display_options(bills);	//Sort.h
													/*
													Je¿eli u¿ytkownik chce wróciæ do menu funkcja zwraca -1

													If user want to go back to menu, the function return -1
													*/

			if (bill == -1) { continue; }

		}
		else if (choice.compare("C") == 0)
		{

			/*
			Funkcja umo¿liwia usuniêcie danej pozycji

			Function allows to delete an item
			*/

			if (empty_list(bills) == true) { continue; }	//function.h

			bill = bills_display_options(bills);	//Sort.h
													/*
													Je¿eli u¿ytkownik chce wróciæ do menu funkcja zwraca -1

													If user want to go back to menu, the function return -1
													*/
			if (bill == -1) { continue; }

			/*
			Tryb informuje o usuniêciu danego elementu

			Mode informs of the removal of the item
			*/

			/*
			Wybranie jednego rachunku z aktualnej listy

			Selecting one of the current bills list
			*/
			position = bill_index_select(remove_mode, bills);	//function.h

			if (bill == -1) { continue; }

			bills.erase(bills.begin() + bill);
			//usuniecie odpowiedniej pozycji
		}
		else if (choice.compare("D") == 0)
		{
			/*

			Funkcja pozwala edytowaæ konkretn¹ pozycjê

			This function allows to edit a particular position
			*/

			if (empty_list(bills) == true) { continue; }	//function.h

			bill = bills_display_options(bills);	//Sort.h

													/*
													Je¿eli u¿ytkownik chce wróciæ do menu funkcja zwraca -1

													If user want to go back to menu, the function return -1
													*/

			if (bill == -1) { continue; }

			/*
			Tryb informuje o modyfikacji danego rachunku

			Mode informs about the modification of particular bill

			*/
			position = bill_index_select(modify_mode, bills);	//function.h
			cout << position;

			/*
			Wybranie jednego rachunku z aktualnej listy

			Selecting one of the current bills list


			*/
			if (position == -1) { continue; }
			/*
			Indeks konkretnego rachunku

			Index of particular bill
			*/

			menu3();	//Menus.h

			string_format(temp);	//Sort.h

			while (find(options2.begin(), options2.end(), temp) != options2.end() == false && temp.compare("Q") != 0)
			{
				cout << "\215le podana warto\230\206, spróbuj ponownie" << "\n";

				menu3();	//Menus.h

				string_format(temp);//Sort.h
			}
			/*
			Choice of values to change

			Wybór wartoœci do zmiany
			*/

			if (temp.compare("Q") == 0) { continue; }

			switch (stoi(temp))
				/*

				Zmiana konkretnej wartoœci w danym rachunku

				Change a specific value in a given account

				Je¿eli u¿ytkownik chce wróciæ do menu funkcje zwracaj¹ -1

				If user want to go back to menu, the functions return -1

				*/
			{
			case 1:

				/*
				Nazw¹ przedmiotu mo¿e byæ Q / q

				Name of the thing may be Q / q
				*/
				thingname = thingname_setter();	//function.h
				bills[position].change_thing(thingname); //Class.h

				cout << "Nazwa zosta\210a zmieniona" << "\n";

				break;

			case 2:

				gross_amount = gross_amount_setter(); if (gross_amount == -1) { break; }//function.h

				bills[position].change_gross_amount(gross_amount);	//Class.h

				cout << "Kwota brutto zosta\210a zmieniona" << "\n";

				break;

			case 3:

				tax = tax_setter(); if (tax == -1) { break; }//function.h

				bills[position].change_tax(tax);	//Class.h

				cout << "Procent podatku zosta\210 zmieniony" << "\n";

				break;

			case 4:

				cout << "Czy chcesz zmmieni\206 rok, podaj T/t - tak, N/n - nie, Q/q - powr\242t do menu g\210\242wnego" << "\n";

				string_format(temp2);//Sort.h

				while (temp2.compare("T") != 0 && temp2.compare("N") != 0 && temp2.compare("Q") != 0)
				{
					cout << "\215le wprowadzona warto\230c, podaj T/t - Tak, N/n - Nie, Q/q - powr\242t do menu" << "\n";
					string_format(temp2);//Sort.h
				}
				if (temp2.compare("Q") == 0) { break; }

				if (temp2.compare("T") == 0)
				{
					year = year_setter();  if (year == -1) { break; }//function.h

					bills[position].change_year(year);	//Class.h

					cout << "Rok zosta\210 zmieniony" << "\n";

				}
				cout << "Czy chcesz zmmieni\206 miesi\245c, podaj T/t - tak, N/n - nie, Q/q - powr\242t do menu " << "\n";

				string_format(temp2);	//Sort.h

				while (temp2.compare("T") != 0 && temp2.compare("N") != 0 && temp2.compare("Q") != 0)
				{
					cout << "\215le wprowadzona warto\230c, podaj T/t - Tak, N/n - Nie, Q/q - powr\242t do menu" << "\n";

					string_format(temp2);	//Sort.h
				}
				if (temp2.compare("Q") == 0) { break; }

				if (temp2.compare("T") == 0)
				{
					mounth = monuth_setter(); if (mounth == -1) { break; }	//function.h

					bills[position].change_mounth(monuth_setter());	//Class.h

					cout << "Miesi\245c zosta\210 zmieniony" << "\n";
				}
				cout << "Czy chcesz zmieni\206 dzie\344 , wprowad\253 T/t - tak, N/n -Nie, Q/q - powr\242t do menu" << "\n";

				string_format(temp2);//Sort.h

				while (temp2.compare("T") != 0 && temp2.compare("N") != 0 && temp2.compare("Q") != 0)
				{
					cout << "\215le wprowadzona warto\230c, podaj T/t - Tak, N/n - Nie, Q/q - powr\242t do menu" << "\n";
					string_format(temp2);//Sort.h
				}
				if (temp2.compare("Q") == 0) { break; }

				if (temp2.compare("T") == 0)
				{

					day = day_setter(bills[position].mounth_return(), bills[position].year_return()); if (day == -1) { break; } //function.h
					bills[position].change_day(day);	//Class.h
					cout << "Dzie\344 zosta\210 zmieniony" << "\n";
				}
			}
		}
		else if (choice.compare("E") == 0)
		{
			/*

			Funckja pozwala na zapis danych do wybranego pliku

			Function allows to write data to the selected file

			*/

			if (empty_list(bills) == true) { continue; } //function.h

			cout << "Podaj nazw\251 pliku do kt\242rego chcesz zapisa\206 aktualn\245 zawarto\230\206" << "\n";
			/*
			Nazw¹ pliku mo¿e byæ Q / q

			The filename may be Q / q
			*/
			getline(cin, temp);

			while (temp.length() == 0)
			{
				cout << "Nazwa pliku musi zawiera\206 jakie\230 znaki" << "\n";
				getline(cin, temp);
			}

			file_out.open(temp, ios::out | ios::trunc);		//otwarcie pliku o podanej nazwie


															//nag³ówek listy
			file_out << setfill(' ');
			file_out << setw(3) << left << "LP " << setw(3) << " | ";
			file_out << setw(15) << left << "Nazwa" << setw(3) << " | ";
			file_out << setw(12) << left << "Kwota Brutto" << setw(3) << " | ";
			file_out << setw(12) << left << "Kwota Netto" << setw(3) << " | ";
			file_out << setw(15) << left << "Procent Podatku" << setw(3) << " | ";
			file_out << setw(20) << left << "Data" << "\n";
			file_out << setfill('-');
			file_out << setw(92) << "" << "\n";

			unsigned short i;

			net_sum = 0;
			gross_sum = 0;
			file_out << setfill(' ');
			for (i = 0; i < bills.size(); i++)
			{
				file_out << setw(3) << right << i + 1 << setw(3) << " | ";
				file_out << bills[i];
				gross_sum += bills[i].gross_amount_return();
				net_sum += bills[i].net_amount_return();
			}

			//podsumowanie
			file_out << setfill('-');
			file_out << setw(92) << "" << "\n";
			file_out << setfill(' ');
			file_out << setw(6) << right << " | ";
			file_out << setw(18) << right << " | ";
			file_out << setw(12) << left << gross_sum << setw(3) << " | ";
			file_out << setw(12) << left << net_sum << setw(3) << " | ";
			file_out << setw(18) << right << " | ";

			file_out << "\n";
			file_out.close();

			cout << "Dane zosta\210y zapisane do pliku " << temp << "\n\n";
		}
		else if (choice.compare("F") == 0)
		{
			/*

			Funkcja umo¿liwia odczyt danych z podanego pliku

			Function allows to read data from a specified file

			*/
			while (true)
			{
				cout << "Podaj nazw\251 pliku z kt\242rego chcesz odczyta\206 dane" << "\n";

				cout << "Wielko\230\206 pliku oraz bia\210e znaki maj\245 znaczenie" << "\n";

				getline(cin, temp);

				while (temp.length() == 0)
				{
					cout << "Nazwa pliku musi zawiera\206 jakie\230 znaki" << "\n";

					getline(cin, temp);
				}

				if (fexists(temp) == true)
				{
					/*
					Gdy plik o podanej nazwie istnieje

					When a file with the given name exists
					*/

					file_in.open(temp, ios::in);

					if (file_in.peek() == ifstream::traits_type::eof())
					{
						cout << "Plik istnieje ale jest pusty" << "\n";
						break;
					}
					cout << "Czy chcesz doda\206 dane do aktualnych ,czy nadpisa\206 stare" << " \n";
					cout << "Wprowad\253 D/d - doda\206 , N/n - nadpisa\206, Q/q - powr\242t do menu  " << "\n";

					string_format(temp2);//Sort.h

					while (temp2.compare("D") != 0 && temp2.compare("N") != 0 && temp2.compare("Q") != 0)
					{
						cout << "\215le podana warto\230\206, spr\242buj ponownie" << "\n";

						cout << "Wprowad\253 D/d - doda\206 , N/n - nadpisa\206, Q/q - powr\242t do menu  " << "\n";

						string_format(temp2);//Sort.h
					}

					if (temp2.compare("Q") == 0) { break; }

					if (temp2.compare("N") == 0)
					{
						/*

						Je¿eli u¿ytkownik chce nadpisaæ bie¿¹ce dane lista zostaje wyzerowana

						If the user wants to overwrite the current data, the current list is cleared
						*/
						bills.clear();
					}

					int count = 0;

					while (getline(file_in, temp2))
					{
						if (count == 0 || count == 1)
						{
							/*
							Pominiêce dwóch pierwszych linii

							Skipping the first two lines
							*/
							++count;
							continue;
						}

						if (temp2[0] == '-')
						{
							/*
							Pominiêcie dwóch ostatnich linijek

							Skipping the two latest lines

							*/
							break;
						}

						temp2.erase(remove(temp2.begin(), temp2.end(), '|'), temp2.end());
						/*

						function 'divide_line' doesn't take into account '|'  so all these characters will be removed

						funkcja 'divide_line' nie bierze pod uwagê '|' wiêc wszystkie te znaki zostan¹ usuniête

						*/
						bills.push_back(divide_line(temp2));

					}
					file_in.close();

					cout << "Rachunki zosta\210y wprowadzone" << "\n\n";

					break;
				}
				else
				{
					/*
					Gdy plik o podanej nazwie nie istnieje
					When file with given name does not exist
					*/

					cout << "Podany plik nie istnieje" << "\n";

					cout << "Czy dalej chcesz wczyta\206 nazw\251 pliku, T/t - tak, Q/q - wr\242\206 do menu " << "\n";

					string_format(temp);//Sort.h

					while (temp.compare("T") != 0 && temp.compare("Q") != 0)
					{
						cout << "Czy dalej chcesz wczyta\206 nazw\251 pliku, T/t - tak, Q/q - wr\242\206 do menu " << "\n";

						cout << "Czy dalej chcesz wczyta\206 nazw\251 pliku, T/t - tak, N/n - nie " << "\n";

						string_format(temp);//Sort.h
					}

					if (temp.compare("T") == 0)
					{
						continue;
					}

					cout << "\n";
					break;

				}
			}
		}
		else if (choice.compare("Q") == 0)
		{
			break;
		}
		else
		{
			cout << "\215le podana warto\230\206, spr\242buj ponownie" << "\n";
		}
		cout << "\n";
	}

	cout << "Dzi\251kujemy za skorzystanie z programu " << "\n";
	cout << "Do zobaczenia" << "\n";

	getchar();
	return 0;
}
