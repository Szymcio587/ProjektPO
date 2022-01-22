#pragma once
#include <iostream>
#include <string>

#include "Pracownik.h"
#include "Manager.h"
#include "Dostawa.h"
#include "Kamera.h"
#include "System_ochrony.h"
#include "Dystrybutor.h"
#include "Klient.h"
#include "Tankowanie.h"
#include "Sklep.h"
#include "Myjnia.h"

using namespace std;

void uruchom_program() {
	Manager m;
	m.dodaj_pracownika("Marcin", "Wilczak", 420);
	m.dodaj_pracownika("Aleksander", "Turocha", 2137);
	m.dodaj_pracownika("Wiotrek", "Pojton", 6969);
	m.zdaj_raport();
}

int main() {
	uruchom_program();
	int wybor;
	char odpowiedz;
	Dystrybutor D1;
	Myjnia M1;
	Klient K1;
	Pracownik P1("Gosia", "Samosia", 7);
	Sklep S1;
	Manager Man;
	Dostawa Dos1("cos", true, P1);

	for (;;) {
		cout << "\n\n1.Tankowanie\n2.Myjnia\n3.Sklep\n4.Dostawa\n5.Tryb menadzera";
		cout << endl << "Witaj! Z czego chcesz skorzystac?" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:  break;
		case 2: M1.uruchom_funkcje(); break;
		case 3:  break;
		case 4:  break;
		case 5:	 break;
		case 6: break;
		}
		cout << "Czy chcesz skorzystac z uslug jeszcze raz? (t/n)";
		cin >> odpowiedz;
		if (odpowiedz == 'n') break;
		else continue;
	}

	return 0;
}