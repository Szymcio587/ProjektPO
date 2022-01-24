#include "Sklep.h"
#include <iostream>

using namespace std;

void Sklep::ustaw_towary(int a, int b, int c)
{
	ilosc_towaru[0] += a;
	ilosc_towaru[1] += b;
	ilosc_towaru[2] += c;
}
void Sklep::wyswietl_ilosc()
{
	cout << ilosc_towaru[0] << " kawy" << endl;
	cout << ilosc_towaru[1] << " hot-dogow" << endl;
	cout << ilosc_towaru[2] << " ciastek" << endl;
}