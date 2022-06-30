#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <string>

#include "Samochod.h"

using namespace std;

void operator<< (ostream& wyj, Samochod& samochod) {
	cout << "Cena: " << samochod.zwroc_cene() << "\n";
	cout << "Liczba drzwi: " << samochod.zwroc_liczbeDrzwi() << "\n";
	cout << "Podatek: " << samochod.podatek() << "\n";
};

int operator++ (Samochod& samochod) {
	int cena = samochod.zwroc_cene() + 1000;
	samochod.ustaw_cene(cena);
	return cena;
}

template <class A, int size>
class Tablica {
	A* tab = new A[size];
public:
	~Tablica(){
		delete [] this->tab;
		cout << "Desturktor klasy Tablica!\n";
	}
	void set(int pozycja, A wartosc) {
		this->tab[pozycja] = wartosc;
	};
	A get(int pozycja) {
		return this->tab[pozycja];
	};
};

template<int size>
class Tablica<bool, size> {
	bool* tab = new bool[size];
public:
	Tablica() {
		for (int i = 0; i < size; i++)
			tab[i] = false;
	}
	~Tablica() {
		delete[] this->tab;
		cout << "Desturktor klasy Tablica!\n";
	}
	void set(int pozycja, bool wartosc) {
		this->tab[pozycja] = wartosc;
	};
	bool get(int pozycja) {
		return this->tab[pozycja];
	};
	int count() {
		int counter = 0;
		for (int i = 0; i < size; i++) {
			if (tab[i])
				counter++;
		}
		return counter;
	};
};

int main()
{
	Samochod s1("Jakub", "Chodzinski", 15000, 5);
	Samochod s2("Remigiusz", "Wojak", 13500);
	Samochod s3(20000);

	cout << "Na ocene 3.0:\n\n";
	cout << "s1:\n";
	cout << "Cena: " << s1.zwroc_cene() << "\n";
	cout << "Liczba drzwi: " << s1.zwroc_liczbeDrzwi() << "\n";
	cout << "Podatek: " << s1.podatek() << "\n";
	cout << "\n";
	s1.ustaw_cene(40000);
	s1.ustaw_liczbeDrzwi(4);
	s1.zmien_wlasciciela("Dominik", "Chmielowski");
	cout << "Cena: " << s1.zwroc_cene() << "\n";
	cout << "Liczba drzwi: " << s1.zwroc_liczbeDrzwi() << "\n";
	cout << "Podatek: " << s1.podatek() << "\n";

	cout << "\n----------\n\n";

	cout << "s2:\n";
	cout << "Cena: " << s2.zwroc_cene() << "\n";
	cout << "Liczba drzwi: " << s2.zwroc_liczbeDrzwi() << "\n";
	cout << "Podatek: " << s2.podatek() << "\n";

	cout << "\n----------\n\n";

	cout << "s3:\n";
	cout << "Cena: " << s3.zwroc_cene() << "\n";
	cout << "Liczba drzwi: " << s3.zwroc_liczbeDrzwi() << "\n";
	cout << "Podatek: " << s3.podatek() << "\n";

	cout << "\n----------\n\n";

	cout << "Na ocene 4.0:\n\n";
	cout << s1;
	++s1;
	cout << s1;
	cout << "\n----------\n\n";
	cout << s2;
	++s2;
	cout << s2;
	cout << "\n----------\n\n";
	cout << s3;
	++s3;
	cout << s3;

	cout << "\n";

	vector<Samochod> samochody;
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		string imie = "Imie ";
		imie.append(to_string(i + 1));
		string nazwisko = "Nazwisko ";
		nazwisko.append(to_string(i + 1));
		int cena = (rand() % 49000) + 1000;
		int liczba_drzwi = (rand() % 3) + 2;

		Samochod samochod(imie, nazwisko, cena, liczba_drzwi);
		samochody.push_back(samochod);
	}

	for (auto i : samochody) {
		cout << "Cena: " << i.zwroc_cene() << "\n";
		cout << "Liczba drzwi: " << i.zwroc_liczbeDrzwi() << "\n";
		cout << "Podatek: " << i.podatek() << "\n";
		cout << "\n";
	}

	cout << "\n----------\n\n";

	cout << "Na ocene 5.0:\n\n";
	Tablica<int, 10> tab1;
	Tablica<bool, 15> tab2;
	tab1.set(1, 9999);
	cout << "Wartosc tab1 na pozycji 1: " << tab1.get(1) << "\n";
	tab2.set(1, true);
	tab2.set(3, true);
	tab2.set(5, true);
	tab2.set(7, true);
	tab2.set(9, true);
	cout << "\n";
	cout << "Wartosc tab2 na pozycji 1: " << tab2.get(1) << "\n";
	cout << "Wartosc tab2 na pozycji 3: " << tab2.get(3) << "\n";
	cout << "Wartosc tab2 na pozycji 5: " << tab2.get(5) << "\n";
	cout << "Wartosc tab2 na pozycji 7: " << tab2.get(7) << "\n";
	cout << "Wartosc tab2 na pozycji 9: " << tab2.get(9) << "\n";
	cout << "Liczba wartosci true w tab2: " << tab2.count() << "\n";

	cout << "\n----------\n\n";
};