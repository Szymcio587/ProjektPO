#pragma once
#include <iostream>
#include "Sklep.h"
#include "Klient.h"

class Pracownik {
	friend class Sklep;
	friend class Klient;
private:
	float nadgodziny;
	std::string imie, nazwisko;
	float wyplata;
	int ile_nieprawidlowosci;

public:
	Pracownik(std::string i, std::string n, float mamona);;
	Pracownik() = default;
	~Pracownik() = default;

	void zglos_problem();
	void rozwiaz_problem();

	int podaj_ilosc_problemow();

	void wypisz_dane();
	void zmien_wyplate(float nowa_kwota);

	std::string zwroc_imie();
	std::string zwroc_nazwisko();

	void obsluz_sklep(Sklep sklep, Klient* kupujacy);
};