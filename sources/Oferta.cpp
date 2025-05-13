#include "../headers/Oferta.h"

Oferta::Oferta() {}

Oferta::~Oferta() {}

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