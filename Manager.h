#pragma once
#include <iostream>
#include <string>

#include "Pracownik.h"
#include "System_ochrony.h"

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

	int dodaj_pracownika(std::string i, std::string n, float mamona);
	void usun_pracownika();

	~Manager();

	int podaj_liosc_problemow();

	void zdaj_raport();
	void zlec_rozwiazanie_problemu(std::string imie_p, std::string nazw_p);
};

