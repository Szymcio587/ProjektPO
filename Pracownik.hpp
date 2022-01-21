#ifndef PRACOWNIK_HPP
#define PRACOWNIK_HPP

#include <iostream>
#include <string>

class Pracownik {
private:
	float nadgodziny;
	std::string imie, nazwisko;
	float wyplata;
	int ile_nieprawidlowosci;

public:
	Pracownik(std::string i, std::string n, float mamona) : ile_nieprawidlowosci(0) {
		this->imie = i;
		this->nazwisko = n;
		this->wyplata = mamona;
	};
	Pracownik() = default;
	~Pracownik() = default;

	void zglos_problem() {
		this->ile_nieprawidlowosci++;
	}

	void rozwiaz_problem() {
		if(this->ile_nieprawidlowosci > 0)
		this->ile_nieprawidlowosci--;
	}

	int podaj_ilosc_problemow() {
		return ile_nieprawidlowosci;
	}

	void wypisz_dane() {
		std::cout << "Imie: " << this->imie << "\nNazwisko: " << this->nazwisko << "\nWyplata: " << this->wyplata << "\n";
	}

	void zmien_wyplate(float nowa_kwota) {
		this->wyplata = nowa_kwota;
	}

	string zwroc_imie() {
		return this->imie;
	}

	string zwroc_nazwisko() {
		return this->nazwisko;
	}

};

#endif // !PRACOWNIK_HPP