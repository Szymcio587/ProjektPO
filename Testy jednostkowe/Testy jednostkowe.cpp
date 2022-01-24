

#include "pch.h"
#include "CppUnitTest.h"

#include "Dystrybutor.cpp"
#include "Tankowanie.cpp"
#include "Kamera.cpp"
#include "Klient.cpp"
#include "Pracownik.cpp"
#include "sklep.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testyjednostkowe
{
	TEST_CLASS(Testyjednostkowe)
	{
	public:
		Kamera testowa;
		TEST_METHOD(TestMethod1)
		{
			Assert::IsTrue(testowa.wlaczona());
		}
		TEST_METHOD(TestMethod2)
		{
			testowa.wylacz();
			Assert::IsFalse(testowa.wlaczona());
		}
		TEST_METHOD(TestMethod3)
		{
			testowa.wlacz();
			Assert::IsTrue(testowa.wlaczona());
		}
		Klient k1 = []()
		{
			Klient k1(25, "Diesel", "Jan-Krzysztof Duda", true);
			return k1;
		}();
		TEST_METHOD(TestMethod5)
		{
			Assert::AreEqual(k1.getStanKonta(),(float)25);
		}
		TEST_METHOD(TestMethod6)
		{
			Assert::IsFalse(k1.zaplac(30));
		}
		TEST_METHOD(TestMethod7)
		{
			Assert::IsTrue(k1.zaplac(20));
		}
		Pracownik p1 = []()
		{
			Pracownik p1("Gosia", "Samosia", 7);
			return p1;
		}();
		TEST_METHOD(TestMethod9)
		{
			srand(time(NULL));
			for (int i = 0;i < rand();i++)
			{
				Assert::AreEqual(p1.podaj_ilosc_problemow(), i);
				p1.zglos_problem();
			}
		}
		TEST_METHOD(TestMethod10)
		{
			for (int i = p1.podaj_ilosc_problemow();i > 0;i--)
			{
				Assert::AreEqual(p1.podaj_ilosc_problemow(), i);
				p1.rozwiaz_problem();
			}
		}
		TEST_METHOD(TestMethod11)
		{
			Sklep s1;
			s1.ustawTowary(32, 18, 13);
			Assert::AreEqual(s1.ilosc()[0], 52);
			Assert::AreEqual(s1.ilosc()[1], 68);
			Assert::AreEqual(s1.ilosc()[2], 28);
		}

	};
}
