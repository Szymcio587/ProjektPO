#pragma once
#include "Klient.h"

class Dystrybutor
{
private:
	const std::string typy_silnikow[4] = { "Tlokowy", "Odrzutowy", "Jonowy", "Wielopaliwowy" };
	int litry_dostepnego_paliwa[3] = { 100, 100, 100 };
	const float ceny_za_litr[3] = { 5.85, 2.77, 2.19 };

public:
	bool platnosc(bool, int, Klient*, int);
	void wydaj_fakture(int);
	int wybierz_usluge(Klient);

	bool obsluga_awarii(int, int);
	void uruchom_funkcje(Klient*);
	void odmierzaj_czas(int);
	void dodaj_paliwo(int);
};
