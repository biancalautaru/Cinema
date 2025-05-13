#include "../headers/Mancare.h"

#include <iomanip>

Mancare::Mancare() {}

Mancare::~Mancare() {}

Mancare::Mancare(const std::string& nume, double pret, int gramaj):
	Produs(nume, pret),
	gramaj(gramaj)
{}

Mancare::Mancare(const Mancare& copie):
	Produs(copie),
	gramaj(copie.gramaj)
{}

Mancare& Mancare::operator=(const Mancare& copie) {
	Produs::operator=(copie);
	gramaj = copie.gramaj;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Mancare& mancare) {
	mancare.afisare(os);
	return os;
}

void Mancare::afisare(std::ostream& os) const {
	os << std::fixed << std::setprecision(2);
	os << nume << " (" << this->gramaj << "g) - " << pret << " lei\n";
}

std::shared_ptr<Produs> Mancare::clone() const {
	return std::make_shared<Mancare>(*this);
}

void Mancare::aplicaPromotie() {
	if (pret > 20)
		pret *= 0.9;
}

int Mancare::getGramaj() const {
	return gramaj;
}