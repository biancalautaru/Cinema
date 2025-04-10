#ifndef REZERVARE_H
#define REZERVARE_H

#include "Client.h"
#include "Proiectie.h"

class Rezervare {
private:
	Client client;
	Proiectie proiectie;
	std::vector<int> locuri;
	int elevi;

public:
	Rezervare();
	~Rezervare();

	Rezervare(const Client& client, const Proiectie& proiectie, const std::vector<int>& locuri, const int& elevi);
	Rezervare(const Rezervare& copie);

	Rezervare& operator=(const Rezervare& copie);
	friend std::ostream& operator<<(std::ostream& os, const Rezervare& rezervare);

	void setClient(const Client& client_);
	const Client& getClient() const;
	void setProiectie(const Proiectie& proiectie_);
	const Proiectie& getProiectie() const;
	void setLocuri(const std::vector<int>& locuri_);
	const std::vector<int>& getLocuri() const;
	void setElevi(const int elevi_);
	int getElevi() const;

	float pretRezervare() const;
};

#endif