#include "../headers/Rezervare.h"

Rezervare::Rezervare() {};

Rezervare::~Rezervare() {};

Rezervare::Rezervare(const Client& client, const Proiectie& proiectie, const std::vector<int>& locuri, const int& elevi):
	client(client),
	proiectie(proiectie),
	locuri(locuri),
	elevi(elevi)
{}

Rezervare::Rezervare(const Rezervare& copie):
	client(copie.client),
	proiectie(copie.proiectie),
	locuri(copie.locuri),
	elevi(copie.elevi)
{}

Rezervare& Rezervare::operator=(const Rezervare& copie) {
	client = copie.client;
	proiectie = copie.proiectie;
	locuri = copie.locuri;
	elevi = copie.elevi;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Rezervare& rezervare) {
	os << rezervare.client;
	os << "Film: \"" << rezervare.proiectie.getFilm().getNume() << "\", ";
	os << rezervare.proiectie.getZi() << ", Ora " << rezervare.proiectie.getOra() << ", Sala " << rezervare.proiectie.getSala().getNumar() << "\n";
	os << "Locuri: ";
	for (size_t i = 0; i < rezervare.locuri.size(); i++) {
		os << rezervare.locuri[i];
		if (i != rezervare.locuri.size() - 1)
			os << ", ";
	}
	os << "\n";
	os << "Numar elevi: " << rezervare.elevi << "\n";
	os << "Pret: " << rezervare.pretRezervare() << " lei\n";
	return os;
}

void Rezervare::setClient(const Client& client_) {
	client = client_;
}

const Client& Rezervare::getClient() const {
	return client;
}

void Rezervare::setProiectie(const Proiectie& proiectie_) {
	proiectie = proiectie_;
}

const Proiectie& Rezervare::getProiectie() const {
	return proiectie;
}

void Rezervare::setLocuri(const std::vector<int>& locuri_) {
	locuri = locuri_;
}

const std::vector<int>& Rezervare::getLocuri() const {
	return locuri;
}

void Rezervare::setElevi(const int elevi_) {
	elevi = elevi_;
}

int Rezervare::getElevi() const {
	return elevi;
}

float Rezervare::pretRezervare() const {
	return (locuri.size() - elevi) * proiectie.getFilm().getPret() + elevi * proiectie.getFilm().pretElevi();
}