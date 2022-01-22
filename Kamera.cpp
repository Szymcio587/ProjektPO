#include "Kamera.h"

 void Kamera::wlacz() {
	czy_wlaczona = true;
}

 void Kamera::wylacz() {
	czy_wlaczona = false;
}

 bool Kamera::wlaczona() {
	return czy_wlaczona;
}
