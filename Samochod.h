#pragma once

#include <iostream>
#include <string>

using namespace std;
class Samochod
{
	int liczba_drzwi;
	int cena;
	string imie;
	string nazwisko;
public:
	Samochod(string imie, string nazwisko, int cena, int liczba_drzwi=4);
	Samochod(int cena, int liczba_drzwi=5);
	~Samochod();
	void ustaw_cene(int cena);
	void ustaw_liczbeDrzwi(int liczba_drzwi);
	int zwroc_cene();
	int zwroc_liczbeDrzwi();
	void zmien_wlasciciela(string imie, string nazwisko);
	double podatek();
	friend void operator<< (ostream& wyj, Samochod& samochod);
	friend int operator++ (Samochod& samochod);
};

