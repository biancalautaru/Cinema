#include "../headers/Sala.h"

Sala::Sala() = default;

Sala::~Sala() = default;

Sala::Sala(const int numar, const int randuri, const int coloane):
	numar(numar),
	randuri(randuri),
	coloane(coloane)
{}

Sala::Sala(const Sala& copie):
	numar(copie.numar),
	randuri(copie.randuri),
	coloane(copie.coloane)
{}

Sala& Sala::operator=(const Sala& copie) {
	numar = copie.numar;
	randuri = copie.randuri;
	coloane = copie.coloane;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Sala& sala) {
	os << "- Sala " << sala.numar << " -\n";
	for (int i = 0; i < 2 * sala.coloane - 4; i++)
		os << "-";
	os << " Ecran ";
	for (int i = 0; i < 2 * sala.coloane - 4; i++)
		os << "-";
	os << "\n";
	for (int i = 0; i < sala.randuri; i++) {
		for (int j = 0; j < sala.coloane; j++) {
			if (i * sala.coloane + j + 1 < 10)
				os << " ";
			if (i * sala.coloane + j + 1 < 100)
				os << " ";
			os << i * sala.coloane + j + 1;
			if (j != sala.coloane - 1)
				os << " ";
		}
		os << "\n";
	}
	return os;
}

void Sala::setNumar(const int numar_) {
	numar = numar_;
}

int Sala::getNumar() const {
	return numar;
}

void Sala::setRanduri(const int randuri_) {
	randuri = randuri_;
}

int Sala::getRanduri() const {
	return randuri;
}

void Sala::setColoane(const int coloane_) {
	coloane = coloane_;
}

int Sala::getColoane() const {
	return coloane;
}