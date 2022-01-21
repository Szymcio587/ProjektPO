#ifndef KAMERA_HPP
#define KAMERA_HPP

#include <iostream>

class Kamera {
private:
	bool czy_wlaczona;
	bool czy_widac_zagrozenie;

public:

	Kamera() : czy_wlaczona(true), czy_widac_zagrozenie(false) {};

	void wlacz() {
		czy_wlaczona = true;
	}

	void wylacz() {
		czy_wlaczona = false;
	}

	bool wlaczona() {
		return czy_wlaczona;
	}
};

#endif // !KAMERA_HPP