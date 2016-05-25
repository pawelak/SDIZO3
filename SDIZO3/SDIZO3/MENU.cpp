#include "stdafx.h"
#include "MENU.h"
#include "Data.h"
#include "Knapsack.h"
#include "TravellingSalesman.h"



MENU::MENU()
{
}


MENU::~MENU()
{
}

void MENU::MENU1()
{
	co = 0;
	do
	{
		cout << " \nWybierz opcje: " << endl;
		cout << " 1. Generuj dane" << endl;
		cout << " 2. Problem plecakowy " << endl;
		cout << " 3. Problem komiwojazera " << endl;

		cin >> co;
		switch (co)
		{
		case 1:
		{
			MENUGenerate();
			break;
		}
		case 2:
		{
			MENUK();
			break;
		}
		case 3:
		{
			MENUTS();
			break;
		}
		default:
			cout << "Niema takiej komendy" << endl;
			MENU1();
			break;
		}
	} while (co != 0);
}


void MENU::MENUGenerate()
{
	co = 0;
	do
	{
		cout << " \nWybierz opcje: " << endl;
		cout << " 1. Generuj dane dla problemu komiwojazera" << endl;
		cout << " 2. Generuj dane dla problemu plecakowego" << endl;
		cout << " 0. Exit " << endl;

		cin >> co;
		switch (co)
		{
		case 1:
		{
			int ile;
			bool a = 0;
			do
			{
				cout << "Podaj ilosc miast: ";
				cin >> ile;
				if (ile > 0) a = 1;
			} while (!a);

			Data d;
			d.generateFileTS(ile);
			break;
		}
		case 2:
		{
			int ile,c;

			cout << "Podaj ilosc itemow i pojemnosc plecaka: ";
			cin >> ile >> c;


			Data d;
			d.generateFileK(ile,c);
			break;
		}
		case 0:
		{
			MENU1();
			break;
		}
		default:
			cout << "Niema takiej komendy" << endl;
			MENUGenerate();
			break;
		}
	} while (co != 0);
}



void MENU::MENUK()
{
	string adr;
	do
	{
		cout << "Podaj nazwe pliku: (jesli widzisz to poraz kolejny to plik nie zostal znaleziony)";
		cin >> adr;
		std::ifstream file;
		file.open(adr);
		if (file.is_open())break;
		file.close();
	} while (true);
	Knapsack k(adr);

	int  co = 0;
	do
	{
		cout << " \Co chcesz? " << endl;
		cout << " 1. Plecak przeglad zlupelny" << endl;
		cout << " 2. Plecak dynamiczny " << endl;
		cout << " 0. Exit " << endl;

		cin >> co;
		switch (co)
		{
		case 1:
		{
			k.bruteForce(0);
			k.showResultB();
			break;
		}
		case 2:
		{
			k.dynamic();
			k.showResultG();
			break;
		}
		case 0:
		{
			MENU1();
			break;
		}
		default:
			cout << "Niema takiej komendy" << endl;
			MENUK();
			break;
		}
	} while (co != 0);
}



void MENU::MENUTS()
{
	string adr;
	bool a = 0;
	do
	{
		cout << "Podaj nazwe pliku: (jesli widzisz to poraz kolejny to plik nie zostal znaleziony)";
		cin >> adr;
		std::ifstream file;
		file.open(adr);
		if (file.is_open())a = 1;
		file.close();
	} while (!a);
	TravellingSalesman ts(adr);

	int  co = 0;
	do
	{
		cout << " \nWybierz opcje " << endl;
		cout << " 1. Komiwojazer bruteforce" << endl;
		cout << " 2.  Komiwojazer zachlany" << endl;
		cout << " 0. Exit " << endl;

		cin >> co;
		switch (co)
		{
		case 1:
		{
			ts.bruteForce(0);
			ts.showResultB();
			break;
		}
		case 2:
		{
			ts.greedy();
			ts.showResultG();
			break;
		}
		case 0:
		{
			MENU1();
			break;
		}
		default:
			cout << "Niema takiej komendy" << endl;
			MENUTS();
			break;
		}
	} while (co != 0);
}