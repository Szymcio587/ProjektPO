#pragma once
#include <string>

class Klient
{
	friend class Sklep;
	friend class Pracownik;
	float stan_konta;
	const std::string typ_silnika;
	const std::string dane_osobowe;
	const bool karta_stalego_klienta = false;
public:
	float getStanKonta() {
		return stan_konta;
	}

	Klient(float hajs, std::string silnik, std::string dane, bool karta) : stan_konta(hajs), typ_silnika(silnik), dane_osobowe(dane),
		karta_stalego_klienta(karta) {};
	Klient() : stan_konta(10), typ_silnika("noEngineName"), dane_osobowe("noPersonalData"), karta_stalego_klienta(true) {};
	bool zaplac(float);
	std::string zwroc_silnik();
	float zwroc_hajs();
};