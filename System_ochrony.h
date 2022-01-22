#pragma once
#include <iostream>
#include <string>

#include "Kamera.h"
#include "Pracownik.h"

#define ILOSC_KAMER 10

class System_ochrony {
private:
	Kamera* monitoring = new Kamera[ILOSC_KAMER];
	Pracownik ochroniarz;
public:

};
