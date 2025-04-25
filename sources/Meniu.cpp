#include "../headers/Meniu.h"

#include <iomanip>

Meniu::Meniu() {}

Meniu::~Meniu() {}

Meniu::Meniu(const std::string& nume, double pret, const std::shared_ptr<Produs>& mancare, const std::shared_ptr<Produs>& bautura, const MarimeMeniu& marime):
	Produs(nume, pret),
	mancare(std::dynamic_pointer_cast<Mancare>(mancare)),
	bautura(std::dynamic_pointer_cast<Bautura>(bautura)),
	marime(marime)
{}

Meniu::Meniu(const Meniu& copie):
	Produs::Produs(copie),
	mancare(copie.mancare),
	bautura(copie.bautura),
	marime(copie.marime)
{}

Meniu& Meniu::operator=(const Meniu& copie) {
	Produs::operator=(copie);
	mancare = copie.mancare;
	bautura = copie.bautura;
	marime = copie.marime;
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
	os << mancare->getNume() << " (" << mancare->getGramaj() << "g), ";
	os << bautura->getNume() << " (" << bautura->getVolum() << " ml) - ";
	os << pret << " lei\n";
}

std::shared_ptr<Produs> Meniu::clone() {
	return std::make_shared<Meniu>(*this);
}

void Meniu::aplicaPromotie() {
	if (pret > 27)
		pret *= 0.9;
}