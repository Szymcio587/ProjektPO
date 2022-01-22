#pragma once
#include "Pracownik.h"
using namespace std;

class Myjnia {
private:
	float detergenty = 80;
	string dostepne_funkcje[3] = { "Podstawowy","Rozszerzony","Premium" };
	double cena_uslugi[3] = { 15.70, 22.40, 29.99 };
	int time_limit[3] = { 300, 480, 600 };

public:
	void platnosc(bool);
	void wydaj_fakture(int);
	int wybierz_usluge();

	bool obsluga_awarii();
	void uruchom_funkcje();
	void odmierzaj_czas(int);
};

