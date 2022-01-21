#pragma once

#include <iostream>
#include <string>

#include "Pracownik.hpp"
#include "Manager.hpp"
#include "Dostawa.hpp"
#include "Kamera.hpp"
#include "System_ochrony.hpp"

using namespace std;



void uruchom_program() {
	Manager m;
	m.dodaj_pracownika("Marcin", "Wilczak", 420);
	m.dodaj_pracownika("Aleksander", "Turocha", 2137);
	m.dodaj_pracownika("Wiotrek", "Pojton", 6969);
	m.zdaj_raport();
}

int main() {

	uruchom_program();

	return 0;
}