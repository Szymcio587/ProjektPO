#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <iostream>
#include <string>

#define ILOSC_PRACOWNIKOW 3

class Manager {
protected:
	std::string imie, nazwisko;
	int godziny_pracy = 8, pracownicy;
	float wyplata;
	Pracownik** osoby_zatrudnione = new Pracownik * [ILOSC_PRACOWNIKOW];

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
			//delete osoby_zatrudnione[pracownicy--];
		}
	}

	~Manager() {
		delete[] osoby_zatrudnione;
	}

	int podaj_liosc_problemow() {
		int ilosc_problemow = 0;
		for (int q = 0; q < pracownicy; q++) {
			ilosc_problemow += osoby_zatrudnione[q].podaj_ilosc_problemow();
		}
		return ilosc_problemow;
	}

	void zdaj_raport() {
		for (int q = 0; q < pracownicy; q++) {
			osoby_zatrudnione[q]->wypisz_dane();
		}

		std::cout << "Aktualna ilosc usterek do rozwiazania wynosi: " << this->podaj_liosc_problemow() << "\n";
	}
};

#endif // !MANAGER_HPP