#pragma once
#include <iostream>
#include <string>

#include "Pracownik.h"

class Dostawa {
private:
	std::string produkty;
	Pracownik odbiorca;
	bool czy_kompletna;

public:
	Dostawa(std::string prod, bool poprawnosc, Pracownik odb) : produkty(prod), czy_kompletna(poprawnosc), odbiorca(odb) {};
	Dostawa() = default;
	bool sprawdz_poprawnosc();

	void zglos_nieprawidlowosc();
};

