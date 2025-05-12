#ifndef FILM_H
#define FILM_H

#include <iostream>
#include <vector>
#include <string>

class Film {
private:
	std::string nume;
	std::vector<std::string> gen;
	int durata;
	int an;
	std::string regizor;
	std::string rating;
	std::string format;
	double pret;

public:
	Film();
	~Film();

	Film(const std::string& nume, const std::vector<std::string>& gen, const int& durata, const int& an, const std::string& regizor, const std::string& rating, const std::string& format, const double& pret);
	Film(const Film& copie);

	Film& operator=(const Film& copie);
	friend std::ostream& operator<<(std::ostream& os, const Film& film);

	const std::string& getNume() const;
	const std::vector<std::string>& getGen() const;
	int getDurata() const;
	const std::string& getRating() const;
	const std::string& getFormat() const;
	double getPret() const;

	double pretElevi() const;
};

#endif