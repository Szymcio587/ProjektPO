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

int main() {
	int wybor;
	char odpowiedz;
	Dystrybutor D1;
	Myjnia M1;
	Klient K1(40, "Tlokowy", "Jan-Krzysztof Duda", true);
	Pracownik P1("Gosia", "Samosia", 7);
	Sklep S1;
	Manager Man;
	Dostawa Dos1("cos", true, P1);

	for (;;) {
		cout << "\n\n1.Tankowanie\n2.Myjnia\n3.Sklep\n4.Dostawa";
		cout << endl << "Witaj! Z czego chcesz skorzystac?" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1: { D1.uruchom_funkcje(&K1);  cout << "Stan konta klienta " << K1.getStanKonta() << endl; } break;
		case 2: { M1.uruchom_funkcje(&K1);  cout << "Stan konta klienta " << K1.getStanKonta() << endl; } break;
		case 3: { P1.obsluz_sklep(S1, &K1);  cout << "Stan konta klienta " << K1.getStanKonta() << endl; } break;
		case 4: { Dos1.zacznij_dostawe(S1); } break;
		}
		cout << "Czy chcesz skorzystac z uslug jeszcze raz? (t/n)";
		cin >> odpowiedz;
		if (odpowiedz == 'n') break;
		else continue;
	}

	return 0;
}