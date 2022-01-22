#include "Pracownik.h"

 Pracownik::Pracownik(std::string i, std::string n, float mamona) : ile_nieprawidlowosci(0) {
	this->imie = i;
	this->nazwisko = n;
	this->wyplata = mamona;
}

 void Pracownik::zglos_problem() {
	this->ile_nieprawidlowosci++;
}

 void Pracownik::rozwiaz_problem() {
	if (this->ile_nieprawidlowosci > 0)
		this->ile_nieprawidlowosci--;
}

 int Pracownik::podaj_ilosc_problemow() {
	return ile_nieprawidlowosci;
}

 void Pracownik::wypisz_dane() {
	std::cout << "Imie: " << this->imie << "\nNazwisko: " << this->nazwisko << "\nWyplata: " << this->wyplata << "\n";
}

 void Pracownik::zmien_wyplate(float nowa_kwota) {
	this->wyplata = nowa_kwota;
}

 std::string Pracownik::zwroc_imie() {
	return this->imie;
}

 std::string Pracownik::zwroc_nazwisko() {
	return this->nazwisko;
}
