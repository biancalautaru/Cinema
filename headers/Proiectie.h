#ifndef PROIECTIE_H
#define PROIECTIE_H

#include <iostream>
#include <set>
#include "Film.h"
#include "Sala.h"

class Proiectie {
private:
	Film film;
	std::string zi;
	std::string ora;
	Sala sala;
	std::set<int> ocupate;

public:
	Proiectie();
	~Proiectie();

	Proiectie(const Film& film, const std::string& zi, const std::string& ora, const Sala& sala,
	          const std::set<int>& ocupate);
	Proiectie(const Proiectie& copie);

	Proiectie& operator=(const Proiectie& copie);
	friend std::ostream& operator<<(std::ostream& os, const Proiectie& proiectie);

	const Film& getFilm() const;
	void setZi(const std::string& zi_);
	const std::string& getZi() const;
	const std::string& getOra() const;
	const Sala& getSala() const;
	void setOcupate(const std::set<int>& ocupate_);
	const std::set<int>& getOcupate() const;
	int locuriRamase() const;
};

#endif
