#include "../headers/Oferta.h"

Oferta::Oferta() {
}

Oferta::~Oferta() {
}

Oferta::Oferta(const std::string& nume, int bilete, int procent):
	nume(nume),
	bilete(bilete),
	procent(procent) {
}

Oferta::Oferta(const Oferta& copie):
	nume(copie.nume),
	bilete(copie.bilete),
	procent(copie.procent) {
}

Oferta& Oferta::operator=(const Oferta& copie) {
	nume = copie.nume;
	bilete = copie.bilete;
	procent = copie.procent;
	return *this;
}

void Oferta::setNume(const std::string& nume_) {
	nume = nume_;
}

void Oferta::setBilete(int bilete_) {
	bilete = bilete_;
}

void Oferta::setProcent(int procent_) {
	procent = procent_;
}

void Oferta::afisare(std::ostream& os) const {
	os << nume << " - " << procent << "% reducere";
	if (bilete == -1)
		os << "\n";
	else
		os << " - " << bilete << " bilete\n";
}
