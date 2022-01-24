#include "Myjnia.h"

#include<iostream>

using namespace std;

void Myjnia::uzupelnij_detergenty() {		//funkcja odpowiedzialna za uzupelnienie detergentow
	this->detergenty = 80;
}

bool Myjnia::platnosc(bool znizka, int wybor, Klient* k) {					//sprawdza czy klienta stac na usluge
	if (!k->zaplac(cena_uslugi[wybor - 1] * (1 - static_cast<float>(znizka) * 0.05f))) {
		cout << "Niestety, nie stac Cie na ta usluge" << endl;
		return false;
	}
	else if (znizka)
		cout << "*Naliczono rabat dla stalego klienta*" << endl;
	cout << "*Wykorzystanie api banku do platnoœci bezgotowkowych*" << endl;
	return true;

}

void Myjnia::wydaj_fakture(int nip) {		//wydanie faktury w zaleznosci od preferencji
	if (nip == 0)
		cout << "*Myjnia drukuje paragon*" << endl;
	else
		cout << "*Myjnia drukuje fakture o numerze NIP " << nip << "*" << endl;

}

bool Myjnia::obsluga_awarii() {			//jezeli jest za malo detergentow wyrzuc blad
	if (detergenty < 5) return false;
	else return true;
}

int Myjnia::wybierz_usluge() {				//funkcja obslugujaca wybranie uslugi przez klienta
	cout << "Wybierz program mycia:" << endl;
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << " - " << dostepne_funkcje[i] << " - " << cena_uslugi[i] << " zl" << endl;
	}
	int wybor;
	cin >> wybor;

	return wybor;
}

void Myjnia::uruchom_funkcje(Klient* k) {		/*odpowiedzialna za caly program uzywany w myjni, obsluguje awarie, uzupelnia detergenty
												pozwala uzytkownikowi na wybranie odpowiedniego trybu mycia, wydanie faktury, zaplacenie
												oraz skorzystanie z karty stalego klienta co pozwoli naliczyc znizke, w przypadku potrzeby
												wydania faktury, zapyta o numer nip. W zaleznosci od wybranego trybu nalicza odpowiednia
												oplate i wybiera odpowiedni czas mycia oraz ilosc uzytych detergentow*/
	cout << "Witaj na myjni!" << endl;
	if (!this->obsluga_awarii()) {
		this->uzupelnij_detergenty();
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

		bool czy_stac = platnosc(staly_klient, wybor, k);

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
			default:
				break;
			}
		}

	}

}