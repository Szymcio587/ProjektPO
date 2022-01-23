#include "Klient.h"

using namespace std;

bool Klient::zaplac(float kwota) {
	if (stan_konta >= kwota) {
		stan_konta -= kwota;
		return true;
	}
	
	return false;
}

string Klient::zwroc_silnik() {
	return this->typ_silnika;
}

float Klient::zwroc_hajs() {
	return this->stan_konta;
}