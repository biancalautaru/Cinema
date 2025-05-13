#include "../headers/Rezervare.h"
#include "../headers/InputGresit.h"
#include "../headers/ProdusInexistent.h"

#include <iomanip>

Rezervare::Rezervare() {}

Rezervare::~Rezervare() {}

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
	for (const auto& produs : produse)
		produs->afisare(os);
}

void Rezervare::citireProduse(std::istream& is, std::ostream &os, const Bar* bar) {
	bar->afisare(os);
	os << "\n";

	os << "Introduceti numerele corespunzatoare produselor dorite, separate prin spatii: ";
	std::vector<int> nr_produse;
	std::string linie;
	while (true) {
		try {
			while (true) {
				std::getline(is, linie);
				try {
					for (size_t i = 0; i < linie.size(); i++)
						if (!isdigit(linie[i]) && linie[i] != ' ')
							throw InputGresit();
					break;
				}
				catch (const InputGresit& e) {
					std::cout << e.what();
				}
			}

			nr_produse.clear();
			for (size_t i = 0; i < linie.size(); i++)
				if (isdigit(linie[i])) {
					int nr = 0;
					size_t j;
					for (j = i; isdigit(linie[j]); j++)
						nr = nr * 10 + linie[j] - '0';
					i = j - 1;
					nr--;
					nr_produse.push_back(nr);
				}

			for (auto nr : nr_produse)
				if (nr < 0 || nr > static_cast<int>(bar->getProduse().size()) - 1)
					throw ProdusInexistent();
			break;
		}
		catch (const ProdusInexistent& e) {
			std::cout << e.what();
		}
	}

	for (auto nr : nr_produse)
		adaugaProdus(bar->getProduse()[nr]);
}

void Rezervare::setClient(const Client& client_) {
	client = client_;
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

void Rezervare::setElevi(const int elevi_) {
	elevi = elevi_;
}

void Rezervare::adaugaProdus(const std::shared_ptr<Produs>& produs) {
	produse.push_back(produs);
}

double Rezervare::pretRezervare() const {
	return (locuri.size() - elevi) * proiectie.getFilm().getPret() + elevi * proiectie.getFilm().pretElevi();
}

double Rezervare::pretTotal() const {
	double total = pretRezervare();
	for (const auto& produs : produse)
		total += produs->getPret();
	return total;
}