#pragma once

#include "Pracownik.h"
#include "Klient.h"

class Myjnia {
private:
	float detergenty = 80;
	const const std::string dostepne_funkcje[3] = { "Podstawowy","Rozszerzony","Premium" };
	const double cena_uslugi[3] = { 15.70, 22.40, 29.99 };
	const int time_limit[3] = { 300, 480, 600 };

public:
	bool platnosc(bool, int, Klient*);
	void wydaj_fakture(int);
	int wybierz_usluge();

	bool obsluga_awarii();
	void uruchom_funkcje(Klient*);
	void odmierzaj_czas(int);
	void uzupelnij_detergenty();
};

