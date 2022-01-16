#ifndef DOSTAWA_HPP
#define DOSTAWA_HPP

#include <iostream>
#include <string>

class Dostawa {
private:
	std::string produkty;
	Pracownik odbiorca;
	bool czy_kompletna;

public:
	Dostawa(std::string prod, bool poprawnosc, Pracownik odb) : produkty(prod), czy_kompletna(poprawnosc), odbiorca(odb) {};
	Dostawa() = default;
	bool sprawdz_poprawnosc() {
		return czy_kompletna;
	}

	void zglos_nieprawidlowosc() {
		this->odbiorca.zglos_problem();
	}
};

#endif //!DOSTAWA_HPP