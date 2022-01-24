#pragma once
#include <string>

class Klient
{
	friend class Sklep;
	friend class Pracownik;
	float stan_konta;
	std::string typ_silnika = "noEngineName";
	std::string dane_osobowe = "noPersonalData";
	bool karta_stalego_klienta = false;
public:
	//void wykorzystajUsluge(Usluga* service);
	float getStanKonta() {
		return stan_konta;
	}

	Klient(float hajs, std::string silnik, std::string dane, bool karta) : stan_konta(hajs), typ_silnika(silnik), dane_osobowe(dane),
		karta_stalego_klienta(karta) {};
	Klient() = default;
	bool zaplac(float);
};
