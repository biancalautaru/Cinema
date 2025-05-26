#ifndef PROGRAMZI_H
#define PROGRAMZI_H

#include <iostream>
#include <vector>
#include "Proiectie.h"

class ProgramZi {
private:
	std::vector<Proiectie> zi;

	void sortareProiectii();

	std::string oraString(const int& ora);

	int urmatoareaOra(const int& ora);

public:
	ProgramZi();
	~ProgramZi();

	explicit ProgramZi(const std::vector<Proiectie>& zi);
	ProgramZi(const ProgramZi& copie);

	ProgramZi& operator=(const ProgramZi& copie);
	friend std::ostream& operator<<(std::ostream& os, const ProgramZi& program);

	void setZi(const std::vector<Proiectie>& zi_);
	const std::vector<Proiectie>& getZi() const;

	void adaugaProiectie(const Proiectie& proiectie);
	ProgramZi generare(const std::vector<Film>& filme_aux, const std::vector<Sala>& sali_aux);
};

#endif
