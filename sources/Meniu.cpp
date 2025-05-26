#include "../headers/Meniu.h"

#include <iomanip>

Meniu::Meniu() {
};

Meniu::~Meniu() {
}

Meniu::Meniu(const std::string& nume, double pret, const std::string& nume_mancare, int gramaj,
             const std::string& nume_bautura, int volum, const MarimeMeniu& marime):
	Produs(nume, pret),
	nume_mancare(nume_mancare),
	gramaj(gramaj),
	nume_bautura(nume_bautura),
	volum(volum),
	marime(marime) {
}

Meniu::Meniu(const Meniu& copie):
	Produs::Produs(copie),
	nume_mancare(copie.nume_mancare),
	gramaj(copie.gramaj),
	nume_bautura(copie.nume_bautura),
	volum(copie.volum),
	marime(copie.marime) {
}

Meniu& Meniu::operator=(const Meniu& copie) {
	if (this != &copie) {
		Produs::operator=(copie);
		nume_mancare = copie.nume_mancare;
		gramaj = copie.gramaj;
		nume_bautura = copie.nume_bautura;
		volum = copie.volum;
		marime = copie.marime;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Meniu& meniu) {
	meniu.afisare(os);
	return os;
}

void Meniu::afisare(std::ostream& os) const {
	os << std::fixed << std::setprecision(2);
	switch (marime) {
	case MIC:
		os << "Meniu Mic: ";
		break;
	case MEDIU:
		os << "Meniu Mediu: ";
		break;
	case MARE:
		os << "Meniu Mare: ";
		break;
	case SPECIAL:
		os << "Meniu Special: ";
	}
	os << nume_mancare << " (" << gramaj << "g), ";
	os << nume_bautura << " (" << volum << "ml) - ";
	os << pret << " lei\n";
}

std::shared_ptr<Produs> Meniu::clone() const {
	return std::make_shared<Meniu>(*this);
}

void Meniu::aplicaPromotie() {
	if (pret > 27)
		pret *= 0.9;
}
