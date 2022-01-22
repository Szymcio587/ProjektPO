#pragma once
#include <string>

class Klient
{
	friend class Sklep;
	friend class Pracownik;
	float stanKonta = 10.0;
	std::string typSilnika = "noEngineName";
	std::string daneOsobowe = "noPersonalData";
	bool kartaStalegoKlienta = false;
public:
	//void wykorzystajUsluge(Usluga* service);
	float getStanKonta() {
		return stanKonta;
	}
};
