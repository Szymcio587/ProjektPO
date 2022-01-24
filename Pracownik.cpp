#include "Pracownik.h"
#include "Klient.h"

using namespace std;

 Pracownik::Pracownik(std::string i, std::string n, float mamona) : ile_nieprawidlowosci(0) {
	this->imie = i;
	this->nazwisko = n;
	this->wyplata = mamona;
}

 void Pracownik::zglos_problem() {
	this->ile_nieprawidlowosci++;
}

 void Pracownik::rozwiaz_problem() {
	if (this->ile_nieprawidlowosci > 0)
		this->ile_nieprawidlowosci--;
}

 int Pracownik::podaj_ilosc_problemow() {
	return ile_nieprawidlowosci;
}

 void Pracownik::wypisz_dane() {
	std::cout << "Imie: " << this->imie << "\nNazwisko: " << this->nazwisko << "\nWyplata: " << this->wyplata << "\n";
}

 void Pracownik::zmien_wyplate(float nowa_kwota) {
	this->wyplata = nowa_kwota;
}

 std::string Pracownik::zwroc_imie() {
	return this->imie;
}

 std::string Pracownik::zwroc_nazwisko() {
	return this->nazwisko;
}

 void Pracownik::obsluz_sklep(Sklep sklep, Klient* kupujacy)
 {
     int aktualna_godzina = 8;
     int akcja;

     if (aktualna_godzina > sklep.godziny_otwarcia[0] && aktualna_godzina < sklep.godziny_otwarcia[1]) {
         cout << "Jaka akcje chcesz wykonac?" << endl;
         cout << "1 - Kup produkt" << endl;
         cout << "2 - Wyswietl dostepne towary" << endl;
         if (sklep.otwarcie == true)
         {
             cout << "3 - Zamknij sklepik" << endl;

         }
         else
             cout << "3 - Otworz sklepik" << endl;
         cout << "4 - Wyjdz z terminala" << endl;
         cin >> akcja;
         switch (akcja)
         {
         case 1:
         { int produkt;
         cout << "Ktory produkt chcesz kupic: " << endl;
         cout << "1 - " << sklep.towary[0] << endl;
         cout << "2 - " << sklep.towary[1] << endl;
         cout << "3 - " << sklep.towary[2] << endl;
         cin >> produkt;
         if (produkt == 1) {
             cout << "Kupiono " << sklep.towary[0] << endl;
             kupujacy->stan_konta -= sklep.koszty_produktow[0];
         }
         else if (produkt == 2) {
             cout << "Kupiono " << sklep.towary[1] << endl;
             kupujacy->stan_konta -= sklep.koszty_produktow[1];
         }


         else if (produkt == 3) {
             cout << "Kupiono " << sklep.towary[2] << endl;
             kupujacy->stan_konta -= sklep.koszty_produktow[2];
         }


         else
             cout << "Wybrano zly numer towaru" << endl;
         }
         break;

         case 2:
             cout << "Dostepne towary: " << endl;
             cout << sklep.towary[0] << endl;
             cout << sklep.towary[1] << endl;
             cout << sklep.towary[2] << endl;
             break;

         case 3:
             if (sklep.otwarcie == false) {
                 sklep.otwarcie = true;
             }
             else
             {
                 sklep.otwarcie = false;
             }
             break;

         default:
             cout << "Podano zly numer akcji" << endl;
             break;
         }

     }
 }
