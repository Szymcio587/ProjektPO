#include "Dystrybutor.h"

#include<iostream>

using namespace std;

void Dystrybutor::dodaj_paliwo(int typ) {
	this->litry_dostepnego_paliwa[typ] += 100;
}

bool Dystrybutor::platnosc(bool znizka, int wybor, Klient* k, int litry) {
	if (!k->zaplac(litry * (ceny_za_litr[wybor - 1] * (1 - static_cast<float>(znizka) * 0.05f)))) {
		cout << "Niestety, nie stac Cie na ta usluge" << endl;
		return false;
	}
	else if (znizka)
		cout << "*Naliczono rabat dla stalego klienta*" << endl;
	cout << "*Wykorzystanie api banku do platnoœci bezgotowkowych*" << endl;
	return true;
}

void Dystrybutor::wydaj_fakture(int nip) {
	if (nip == 0)
		cout << "*Myjnia drukuje paragon*" << endl;
	else
		cout << "*Myjnia drukuje fakture o numerze NIP " << nip << "*" << endl;
}

bool Dystrybutor::obsluga_awarii(int wymagane, int typ) {
	if (litry_dostepnego_paliwa[typ] < wymagane) return false;
	else return true;
}

int Dystrybutor::wybierz_usluge(Klient k) {
	int wybor;

	if (k.zwroc_silnik() == "Tlokowy") wybor = 1;
	else if (k.zwroc_silnik() == "Odrzutowy") wybor = 2;
	else if (k.zwroc_silnik() == "Jonowy") wybor = 3;
	else if (k.zwroc_silnik() == "Wielopaliwowy") {
		cout << "Wybierz jakie paliwo chcesz kupic:" << endl;
		for (int i = 0; i < 3; i++) {
			cout << i + 1 << " - " << typy_silnikow[i] << " - " << ceny_za_litr[i] << " zl" << endl;
		}
		cin >> wybor;
	}
	else {
		cout << "Nieobslugiwany typ silnika, niestety nie mozemy kontynuowac transakcji" << endl;
		wybor = 0;
	}
	return wybor;
}

void Dystrybutor::uruchom_funkcje(Klient* k) {
	int ilosc_paliwa, wybor = wybierz_usluge(*k);
	if (wybor) {
		cout << "Witaj na dystrybutorze!" << endl << "Powiedz prosze, ile LITROW paliwa chcesz zatankowac" << endl;
		cin >> ilosc_paliwa;
		if (!this->obsluga_awarii(ilosc_paliwa, wybor)) {
			this->dodaj_paliwo(wybor);
			cout << "Brak wystarczajacej ilosci paliwa, nie mozna skorzystac z dystrybutora, przepraszamy!" << endl;
			return;
		}
		else {

			cout << "Czy posiadasz karte stalego klienta? (t/n)" << endl;
			bool staly_klient = false;

			char decyzja;
			cin >> decyzja;

			if (decyzja == 't') staly_klient = true;

			bool czy_stac = platnosc(staly_klient, wybor, k, ilosc_paliwa);

			if (czy_stac) {
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

				wydaj_fakture(nrNip);

				litry_dostepnego_paliwa[wybor] -= ilosc_paliwa;

				switch (wybor)
				{
				case 1:
					cout << "*Zatankowano paliwo dla silnika typu tlokowego*" << endl;
					//wypisywanie czasu zbyt dlugo trwa
					break;

				case 2:
					cout << "*Zatankowano paliwo dla silnika typu odrzutowego*" << endl;
					//wypisywanie czasu zbyt dlugo trwa
					break;

				case 3:
					cout << "*Zatankowano paliwo dla silnika typu jonowego*" << endl;
					//wypisywanie czasu zbyt dlugo trwa
					break;
				default:
					break;
				}
			}

		}
	}

}