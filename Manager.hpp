#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <iostream>
#include <string>

#define ILOSC_PRACOWNIKOW 5

class Manager {
private:
	std::string imie, nazwisko;
	int godziny_pracy = 8, pracownicy;
	float wyplata;
	Pracownik** osoby_zatrudnione = new Pracownik * [ILOSC_PRACOWNIKOW];
	System_ochrony ochrona;

public:
	Manager(std::string i, std::string n, float mamona) :imie(i), nazwisko(n), pracownicy(0), wyplata(mamona) {};
	Manager() = default;

	void dodaj_pracownika(std::string i, std::string n, float mamona) {
		if (pracownicy < ILOSC_PRACOWNIKOW) {
			Pracownik* nowy = new Pracownik(i, n, mamona);
			osoby_zatrudnione[pracownicy++] = nowy;
		}

	}

	void usun_pracownika() {
		if (pracownicy > 0) {
			//delete [] osoby_zatrudnione[pracownicy--];
		}
	}

	~Manager() {
		delete[] osoby_zatrudnione;
	}

	int podaj_liosc_problemow() {
		int ilosc_problemow = 0;
		for (int q = 0; q < pracownicy; q++) {
			ilosc_problemow += osoby_zatrudnione[q]->podaj_ilosc_problemow();
		}
		return ilosc_problemow;
	}

	void zdaj_raport() {
		for (int q = 0; q < pracownicy; q++) {
			osoby_zatrudnione[q]->wypisz_dane();
		}

		std::cout << "Aktualna ilosc usterek do rozwiazania wynosi: " << this->podaj_liosc_problemow() << "\n";
	}

	void zlec_rozwiazanie_problemu(string imie_p, string nazw_p) {
		for (int q = 0; q < pracownicy; q++) {
			if (osoby_zatrudnione[q]->zwroc_imie() == imie_p && osoby_zatrudnione[q]->zwroc_nazwisko() == nazw_p &&
				osoby_zatrudnione[q]->podaj_ilosc_problemow()) {
				osoby_zatrudnione[q]->rozwiaz_problem();
				break;
			}
		}
	}
};

#endif // !MANAGER_HPP