#include "../headers/Suvenir.h"

#include <iomanip>

Suvenir::Suvenir() {}

Suvenir::~Suvenir() {}

Suvenir::Suvenir(const std::string& nume, double pret, const std::string& nume_film):
	Produs(nume, pret),
	nume_film(nume_film)
{}

Suvenir::Suvenir(const Suvenir& copie):
	Produs(copie),
	nume_film(copie.nume_film)
{}

Suvenir& Suvenir::operator=(const Suvenir& copie) {
	Produs::operator=(copie);
	nume_film = copie.nume_film;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Suvenir& suvenir) {
	suvenir.afisare(os);
	return os;
}

void Suvenir::afisare(std::ostream& os) const {
	os << std::fixed << std::setprecision(2);
	os << nume << " film " << this->nume_film << " - " << pret << " lei\n";
}

std::shared_ptr<Produs> Suvenir::clone() const {
	return std::make_shared<Suvenir>(*this);
}

void Suvenir::aplicaPromotie() {
	if (pret > 50)
		pret *= 0.9;
}