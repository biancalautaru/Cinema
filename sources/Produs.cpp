#include "../headers/Produs.h"

#include <iomanip>

Produs::Produs() {}

Produs::~Produs() {}

Produs::Produs(const std::string& nume, double pret):
	nume(nume),
	pret(pret)
{}

Produs::Produs(const Produs& copie):
	nume(copie.nume),
	pret(copie.pret)
{}

Produs& Produs::operator=(const Produs& copie) {
	nume = copie.nume;
	pret = copie.pret;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Produs& produs) {
	os << std::fixed << std::setprecision(2);
	os << produs.nume << " - " << produs.pret << " lei\n";
	return os;
}

const std::string& Produs::getNume() const {
	return nume;
}

double Produs::getPret() const {
	return pret;
}