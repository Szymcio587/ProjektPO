#include "Dostawa.h"

using namespace std;

 bool Dostawa::sprawdz_poprawnosc() {
	return czy_kompletna;
}

 void Dostawa::zglos_nieprawidlowosc() {
	if (!this->czy_kompletna)
		this->odbiorca.zglos_problem();
}

 void Dostawa::zacznij_dostawe(Sklep sklep) {
	 cout << "Realizacja dostawy..." << endl;
	 dodaj_produkty(sklep);
 }

 void Dostawa::dodaj_produkty(Sklep sklep) {
	 sklep.ustaw_towary(10, 20, 30);
	 cout << "Dostawa zostala przyjeta. Do sklepu zostalo dodane: " << 10 << " kaw, " << 20 << " hot-dogow i " << 30 << " ciastek." << endl;
	 cout << "Aktualny stan sklepu:" << endl;
	 sklep.wyswietl_ilosc();
 }
