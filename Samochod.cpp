#include "Samochod.h"

Samochod::Samochod(string imie, string nazwisko, int cena, int liczba_drzwi) {
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->cena = cena;
	this->liczba_drzwi = liczba_drzwi;
};
Samochod::Samochod(int cena, int liczba_drzwi) {
	this->imie = "";
	this->nazwisko = "";
	this->cena = cena;
	this->liczba_drzwi = liczba_drzwi;
};
Samochod::~Samochod() {
	cout << "Desturktor klasy Samochod!\n";
};
void Samochod::ustaw_cene(int cena) {
	this->cena = cena;
};
void Samochod::ustaw_liczbeDrzwi(int liczba_drzwi) {
	this->liczba_drzwi = liczba_drzwi;
};
int Samochod::zwroc_cene() {
	return this->cena;
};
int Samochod::zwroc_liczbeDrzwi() {
	return this->liczba_drzwi;
};
void Samochod::zmien_wlasciciela(string imie, string nazwisko) {
	this->imie = imie;
	this->nazwisko = nazwisko;
};
double Samochod::podatek() {
	double podatek = (this->cena * 0.02);
	return podatek;
};