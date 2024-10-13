// tabliczka_mnozenia.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

int main()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(NULL));

	// deklaracja zmiennych
	string i_dzialania;
	int ile_razy, i, l1, l2, dzialanie, wynik, odp_poprawna = 0, odp_bledna = 0;

	// odbior danych od uzytkownika
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
	printf("\tWitaj w programie \"Tabliczka mnozenia\" v.1.0\n\n");
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	printf("\tIle dzialan chcesz zrobic? ");
	cin >> i_dzialania;
	ile_razy = stoi(i_dzialania);
	system("cls");

	for (i = 1; i < ile_razy + 1; i++)
	{
		l1 = (rand() % 10) + 1;
		l2 = (rand() % 10) + 1;

		dzialanie = l1 * l2;

		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		printf("\tDzialanie numer: %i \n\n", i);
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		printf("\t%i * %i = ", l1, l2);
		cin >> wynik;
		printf("\n\n");
		if (wynik == dzialanie)
		{
			odp_poprawna += 1;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
			printf("\tBrawo wynik poprawny!!!\n\n");
		}
		else
		{
			odp_bledna += 1;
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
			printf("\tNiestety to nie jest poprawna odpowiedz!!!\n\n");
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		// wyniki
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		printf("\tZdobywasz jeden punkt. Obecny wynik:\n");
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
		printf("\t- poprawnych odpowiedzi: %i\n", odp_poprawna);
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		printf("\t- blednych odpowiedzi: %i\n\n", odp_bledna);
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		system("pause");
		system("cls");
	}

	// koniec programu
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
	printf("\tKoniec programu, Twoje wyniki:\n\n");
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	printf("\t - poprawne wyniki: ");
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
	printf("%i\n", odp_poprawna);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	printf("\t - bledne wyniki: ");
	SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	printf("%i\n\n", odp_bledna);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
	printf("\tIlosc wykonanych dzialan: %i\n\n", ile_razy);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	int piecdziesiat_procent = ile_razy / 2;
	int osiemdziesiat_procent = ile_razy / 0.8;
	int sto_procent = odp_poprawna + odp_bledna;

	if (odp_poprawna > piecdziesiat_procent and odp_poprawna < osiemdziesiat_procent)
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		printf("Masz ponad 50 procent poprawnych odpowiedzi, to calkiem niezly wynik, ale musisz jeszcze duzo cwiczyc!!!\n\n");
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}

	if (odp_poprawna >= osiemdziesiat_procent and odp_poprawna < sto_procent)
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
		printf("Brawo!!! to bardzo dobry wynik ale warto jeszcze pocwiczyc!!!\n\n");
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}

	if (odp_poprawna == sto_procent)
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
		printf("Brawo!!! jestes geniuszem!!!\n\n");
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}

	if (odp_poprawna <= piecdziesiat_procent)
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		printf("BUUUUU!!! Twoje wyniki sa bardzo zle, wez sie za nauke!!!\n\n");
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}

	system("pause");
}
