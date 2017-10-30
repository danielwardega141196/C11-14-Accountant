#ifndef Accountant_Menus_H
#define Accountant_Menus_H

#define Mounth
#define Size 20

using namespace std;

int mounth_length[Mounth] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
const char* mounth_name[Mounth] = { "Stycze\344","Luty","Marzec","Kwiecie\344","Maj","Czerwiec","Lipiec","Sierpie\344","Wrzesie\344","Pa\253dziernik","Listopad","Grudzie\344" };
/*
string thingname;
float gross_amount;
float tax;
int day;
int mounth;
int year;

*/

/*
Zmienne u¿ywane przy wype³nianiu pól klasy

Variables used to fill class fields
*/

float net_sum;
float gross_sum;
/*
Zmiennie u¿ywane w funkcjach do obliczania sum netto i brutto

Variable used in functions to calculate net and gross sums
*/
string temp;
string temp2;

/*
Zmienne tymczasowe do przechowywania wyborów u¿ytkownika
Temporary variables to store user choices
*/
int bill;
/*
Zmienna której wartoœæ wynosi -1 gdy u¿ytkownik chce wróciæ do menu podczas sortowania rachunków

A variable whose value is -1 when user want to go back to the menu when sorting bills
*/
ofstream file_out;
ifstream file_in;

void menu1()
{
	/*

	Funkcja wyœwietla menu g³ówne

	The function displays the main menu

	*/
	cout << "Podaj co chcesz zrobi\206 " << "\n";

	cout << "A/a - Dodanie nowego rachunku " << "\n";
	cout << "B/b - Wy\230wietlenie rachunk\242w " << "\n";
	cout << "C/c - Usuni\251cie konkretnego rachunku" << "\n";
	cout << "D/d - Modyfikcja danego rachunku " << "\n";
	cout << "E/e - Zapis aktulnego stanu do pliku" << "\n";
	cout << "F/f - Dodanie/nadpisanie danych z pliku" << "\n";
	cout << "Q/q - Wyj\230cie z programu " << "\n";
}

void menu2()
{
	/*
	Wybór kolejnoœci wyœwietlania

	Selecting the display order
	*/
	cout << "Wed\210ug jakiej kolejno\230ci wy\230wietli\206 rachunki" << "\n";
	cout << "Wci\230nij 1 - aby wy\230wietli\206 rachunki w kolejno\230ci alfabetycznej" << "\n";
	cout << "Wci\230nij 2 - aby wy\230wietli\206 rachunki wed\210ug kwoty" << "\n";
	cout << "Wci\230nij 3 - aby wy\230wietli\206 rachunki wed\210ug daty" << "\n";
	cout << "Wci\230nij Q/q - aby wr\242ci\206 do menu" << "\n";

}
void menu3()
{
	/*

	Zmiana danej wartoœci konkretnego rachunku

	Change of the specific value of particukar bill

	*/
	cout << "Kt\242ry element chcesz zmieni\206" << "\n";
	cout << "Wci\230nij 1 - aby zmieni\206 nazw\251" << "\n";
	cout << "Wci\230nij 2 - aby zmieni\206 kwot\251 brutto" << "\n";
	cout << "Wci\230nij 3 - aby zmieni\206 procent podatku" << "\n";
	cout << "Wci\230nij 4 - aby zmieni\206 dat\251" << "\n";
	cout << "Wci\230nij Q/q - aby wr\242ci\206 do menu" << "\n";
}
#endif 
