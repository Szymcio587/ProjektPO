#pragma once
#include <iostream>

class Kamera {
private:
	bool czy_wlaczona;
	bool czy_widac_zagrozenie;

public:

	Kamera() : czy_wlaczona(true), czy_widac_zagrozenie(false) {};

	void wlacz();
	void wylacz();

	bool wlaczona();
};
