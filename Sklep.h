#pragma once
#include "Pracownik.h"
#include <string>

class Sklep {
    friend class Pracownik;
private:
    std::string towary[3] = { "Ciastko","Kawa","Hotdog" };
    float koszty_produktow[3] = { 1.99, 3.99, 5.60 };
    int ilosc_towaru[3] = { 20,50,15 };
    int godziny_otwarcia[2] = { 7,22 };
    bool otwarcie = true;
public:
    void ustaw_towary(int, int, int);
    void wyswietl_ilosc();
    int* ilosc();
};
