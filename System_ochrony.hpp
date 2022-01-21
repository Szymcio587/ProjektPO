#ifndef SYSTEM_OCHRONY_HPP
#define SYSTEM_OCHRONY_HPP

#include <iostream>
#include <string>

#define ILOSC_KAMER 10

class System_ochrony {
private:
	Kamera* monitoring = new Kamera[ILOSC_KAMER];
	Pracownik ochroniarz;
public:

};

#endif // !SYSTEM_OCHRONY_HPP