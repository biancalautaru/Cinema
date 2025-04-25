#include "../headers/Proiectie.h"

Proiectie::Proiectie() {};

Proiectie::~Proiectie() {};

Proiectie::Proiectie(const Film& film, const std::string& zi, const std::string& ora, const Sala& sala, const std::set<int>& ocupate):
	film(film),
	zi(zi),
	ora(ora),
	sala(sala),
	ocupate(ocupate)
{}

Proiectie::Proiectie(const Proiectie& copie):
	film(copie.film),
	zi(copie.zi),
	ora(copie.ora),
	sala(copie.sala),
	ocupate(copie.ocupate)
{}

Proiectie& Proiectie::operator=(const Proiectie& copie) {
	film = copie.film;
	zi = copie.zi;
	ora = copie.ora;
	sala = copie.sala;
	ocupate = copie.ocupate;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Proiectie& proiectie) {
	os << proiectie.film.getNume() << "\n";
	os << proiectie.zi << ", ora " << proiectie.ora << "\n";
	os << "Sala " << proiectie.sala.getNumar() << "\n";
	const int& randuri = proiectie.sala.getRanduri();
	const int& coloane = proiectie.sala.getColoane();
	for (int i = 0; i < 2 * coloane - 4; i++)
		os << "-";
	os << " Ecran ";
	for (int i = 0; i < 2 * coloane - 4; i++)
		os << "-";
	os << "\n";
	for (int i = 0; i < randuri; i++) {
		for (int j = 0; j < coloane; j++) {
			if (proiectie.ocupate.find(i * coloane + j + 1) == proiectie.ocupate.end()) {
				if (i * coloane + j + 1 < 10)
					os << " ";
				if (i * coloane + j + 1 < 100)
					os << " ";
				os << i * coloane + j + 1;
			}
			else
				os << "  X";
			if (j != coloane - 1)
				os << " ";
		}
		os << "\n";
	}
	return os;
}

const Film& Proiectie::getFilm() const {
	return film;
}

void Proiectie::setZi(const std::string& zi_) {
	zi = zi_;
}

const std::string& Proiectie::getZi() const {
	return zi;
}

const std::string& Proiectie::getOra() const {
	return ora;
}

const Sala& Proiectie::getSala() const {
	return sala;
}

void Proiectie::setOcupate(const std::set<int>& ocupate_) {
	ocupate = ocupate_;
}

const std::set<int>& Proiectie::getOcupate() const {
	return ocupate;
}

int Proiectie::locuriRamase() const {
	return sala.getRanduri() * sala.getColoane() - ocupate.size();
}