#include "Klient.h"

using namespace std;

bool Klient::zaplac(float kwota) {
	if (stan_konta >= kwota) {
		stan_konta -= kwota;
		return true;
	}
	
	return false;
}
