#include "Myjnia.h"

#include<iostream>
using namespace std;

void Myjnia::platnosc(bool znizka) {
	if (znizka)
		cout << "*Naliczono rabat dla stalego klienta*" << endl;
	cout << "*Wykorzystanie api banku do platnoœci bezgotowkowych*" << endl;

}

void Myjnia::wydaj_fakture(int nip) {
	if (nip == 0)
		cout << "*Myjnia drukuje paragon*" << endl;
	else
		cout << "*Myjnia drukuje fakture o numerze NIP " << nip << "*" << endl;

}

bool Myjnia::obsluga_awarii() {
	if (detergenty < 5) return false;
	else return true;
}

int Myjnia::wybierz_usluge() {
	cout << "Wybierz program mycia:" << endl;
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << " - " << dostepne_funkcje[i] << " - " << cena_uslugi[i] << " zl" << endl;
	}
	int wybor = 0;
	cin >> wybor;

	return wybor;
}

void Myjnia::uruchom_funkcje() {
	cout << "Witaj na myjni!" << endl;
	if (!this->obsluga_awarii()) {
		cout << "Poziom detergentów zbyt niski, nie mozna skorzystac z myjni, przepraszamy!" << endl;
		return;
	}
	else {

		int wybor = wybierz_usluge();

		cout << "Czy posiadasz karte stalego klienta? (t/n)" << endl;
		bool staly_klient = false;

		char decyzja;
		cin >> decyzja;

		if (decyzja == 't') staly_klient = true;

		cout << "Czy chcesz otrzymac fakture? (t/n)" << endl;
		cin >> decyzja;

		int nrNip = 0;

		switch (decyzja)
		{
		case 't':
			cout << "Podaj numer NIP: ";
			cin >> nrNip;
			break;

		case 'n':
			break;

		default:
			break;
		}

		platnosc(staly_klient);
		wydaj_fakture(nrNip);

		switch (wybor)
		{
		case 1:
			detergenty -= 2;
			cout << "*Myjnia wykonuje mycie Podstawowe*" << endl;
			//wypisywanie czasu zbyt dlugo trwa
			break;

		case 2:
			detergenty -= 3;
			cout << "*Myjnia wykonuje mycie Rozszerzone*" << endl;
			//wypisywanie czasu zbyt dlugo trwa
			break;

		case 3:
			detergenty -= 5;
			cout << "*Myjnia wykonuje mycie Premium*" << endl;
			//wypisywanie czasu zbyt dlugo trwa
			break;
		case 4:

			return;

		default:
			break;
		}
	}

}