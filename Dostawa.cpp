#include "Dostawa.h"

 bool Dostawa::sprawdz_poprawnosc() {
	return czy_kompletna;
}

 void Dostawa::zglos_nieprawidlowosc() {
	if (!this->czy_kompletna)
		this->odbiorca.zglos_problem();
}
