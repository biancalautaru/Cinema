#include "../headers/Bautura.h"

#include <iomanip>

Bautura::Bautura() {}

Bautura::~Bautura() {}

Bautura::Bautura(const std::string&nume, double pret, int volum):
	Produs(nume, pret),
	volum(volum)
{}

Bautura::Bautura(const Bautura& copie):
	Produs(copie),
	volum(copie.volum)
{}

Bautura& Bautura::operator=(const Bautura& copie) {
	Produs::operator=(copie);
	volum = copie.volum;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bautura& bautura) {
	bautura.afisare(os);
	return os;
}

void Bautura::afisare(std::ostream& os) const {
	os << std::fixed << std::setprecision(2);
	os << nume << " (" << volum << "ml) - " << pret << " lei\n";
}

std::shared_ptr<Produs> Bautura::clone() {
	return std::make_shared<Bautura>(*this);
}

void Bautura::aplicaPromotie() {
	if (pret > 10)
		pret *= 0.9;
}

void Bautura::setVolum(int volum_) {
	volum = volum_;
}

int Bautura::getVolum() const {
	return volum;
}