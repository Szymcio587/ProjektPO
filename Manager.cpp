#include "Manager.h"

 void Manager::dodaj_pracownika(std::string i, std::string n, float mamona) {
	if (pracownicy < ILOSC_PRACOWNIKOW) {
		Pracownik* nowy = new Pracownik(i, n, mamona);
		osoby_zatrudnione[pracownicy++] = nowy;
	}

}

 void Manager::usun_pracownika() {
	if (pracownicy > 0) {
		//delete [] osoby_zatrudnione[pracownicy--];
	}
}

Manager::~Manager() {
	delete[] osoby_zatrudnione;
}

int Manager::podaj_liosc_problemow() {
	int ilosc_problemow = 0;
	for (int q = 0; q < pracownicy; q++) {
		ilosc_problemow += osoby_zatrudnione[q]->podaj_ilosc_problemow();
	}
	return ilosc_problemow;
}

void Manager::zdaj_raport() {
	for (int q = 0; q < pracownicy; q++) {
		osoby_zatrudnione[q]->wypisz_dane();
	}

	std::cout << "Aktualna ilosc usterek do rozwiazania wynosi: " << this->podaj_liosc_problemow() << "\n";
}

void Manager::zlec_rozwiazanie_problemu(std::string imie_p, std::string nazw_p) {
	for (int q = 0; q < pracownicy; q++) {
		if (osoby_zatrudnione[q]->zwroc_imie() == imie_p && osoby_zatrudnione[q]->zwroc_nazwisko() == nazw_p &&
			osoby_zatrudnione[q]->podaj_ilosc_problemow()) {
			osoby_zatrudnione[q]->rozwiaz_problem();
			break;
		}
	}
}
