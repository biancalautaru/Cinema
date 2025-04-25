#include "../headers/Rezervare.h"

#include <iomanip>

Rezervare::Rezervare() {};

Rezervare::~Rezervare() {};

Rezervare::Rezervare(const Client& client, const Proiectie& proiectie, const std::vector<int>& locuri, const int& elevi, const std::vector<std::shared_ptr<Produs>>& produse):
	client(client),
	proiectie(proiectie),
	locuri(locuri),
	elevi(elevi),
	produse(produse)
{}

Rezervare::Rezervare(const Rezervare& copie):
	client(copie.client),
	proiectie(copie.proiectie),
	locuri(copie.locuri),
	elevi(copie.elevi),
	produse(copie.produse)
{}

Rezervare& Rezervare::operator=(const Rezervare& copie) {
	client = copie.client;
	proiectie = copie.proiectie;
	locuri = copie.locuri;
	elevi = copie.elevi;
	produse = copie.produse;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Rezervare& rezervare) {
	rezervare.afisareRezervare(os);
	rezervare.afisareProduse(os);
	return os;
}

void Rezervare::afisareRezervare(std::ostream& os) const {
	os << std::fixed << std::setprecision(2);
	os << client;
	os << "Film: \"" << proiectie.getFilm().getNume() << "\", ";
	os << proiectie.getZi() << ", Ora " << proiectie.getOra() << ", Sala " << proiectie.getSala().getNumar() << "\n";
	os << "Locuri: ";
	for (size_t i = 0; i < locuri.size(); i++) {
		os << locuri[i];
		if (i != locuri.size() - 1)
			os << ", ";
	}
	os << "\n";
	os << "Numar elevi: " << elevi << "\n";
	os << "Pret: " << pretRezervare() << " lei\n";
}

void Rezervare::afisareProduse(std::ostream& os) const {
	for (auto produs : produse)
		produs->afisare(os);
}

void Rezervare::citireProduse(std::istream& is, std::ostream &os, const Bar& bar) {
	bar.afisare(std::cout);
	os << "\n";
	std::string linie;
	os << "Introduceti numerele corespunzatoare produselor dorite, separate prin spatii:\n";
	std::getline(is, linie);
	for (size_t i = 0; i < linie.size(); i++)
		if (isdigit(linie[i])) {
			int nr = 0;
			int j;
			for (j = i; isdigit(linie[j]); j++)
				nr = nr * 10 + linie[j] - '0';
			i = j - 1;
			nr--;
			adaugaProdus(bar.getProduse()[nr]);
		}
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

void Rezervare::adaugaProdus(const std::shared_ptr<Produs>& produs) {
	produse.push_back(produs);
}