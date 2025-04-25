#include "../headers/Produs.h"

#include <iomanip>

int Produs::totalProduse = 0;

Produs::Produs() {
	totalProduse++;
}

Produs::~Produs() {}

Produs::Produs(const std::string& nume, float pret):
	nume(nume),
	pret(pret) {
	totalProduse++;
}

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

void Produs::setNume(const std::string& nume_) {
	nume = nume_;
}

const std::string& Produs::getNume() const {
	return nume;
}

void Produs::setPret(float pret_) {
	pret = pret_;
}

float Produs::getPret() const {
	return pret;
}