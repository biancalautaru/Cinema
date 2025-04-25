#ifndef REZERVARE_H
#define REZERVARE_H

#include <memory>

#include "Client.h"
#include "Proiectie.h"
#include "Produs.h"
#include "Bar.h"

class Rezervare {
private:
	Client client;
	Proiectie proiectie;
	std::vector<int> locuri;
	int elevi;
	std::vector<std::shared_ptr<Produs>> produse;

public:
	Rezervare();
	~Rezervare();

	Rezervare(const Client& client, const Proiectie& proiectie, const std::vector<int>& locuri, const int& elevi, const std::vector<std::shared_ptr<Produs>>& produse);
	Rezervare(const Rezervare& copie);

	Rezervare& operator=(const Rezervare& copie);
	friend std::ostream& operator<<(std::ostream& os, const Rezervare& rezervare);
	void afisareRezervare(std::ostream& os) const;
	void afisareProduse(std::ostream& os) const;
	void citireProduse(std::istream& is, std::ostream& os, const Bar& bar);

	void setClient(const Client& client_);
	void setProiectie(const Proiectie& proiectie_);
	const Proiectie& getProiectie() const;
	void setLocuri(const std::vector<int>& locuri_);
	void setElevi(const int elevi_);

	void adaugaProdus(const std::shared_ptr<Produs>& produs);
	double pretRezervare() const;
	double pretTotal() const;
};

#endif