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
	float pret;

public:
	Film();
	~Film();

	Film(const std::string& nume, const std::vector<std::string>& gen, const int durata, const int an, const std::string& regizor, const std::string& rating, const std::string& format, const float pret);
	Film(const Film& copie);

	Film& operator=(const Film& copie);
	friend std::ostream& operator<<(std::ostream& os, const Film& film);

	void setNume(const std::string& nume_);
	const std::string& getNume() const;
	void setGen(const std::vector<std::string>& gen_);
	const std::vector<std::string>& getGen() const;
	void setDurata(const int durata_);
	int getDurata() const;
	void setAn(const int an_);
	int getAn() const;
	void setRegizor(const std::string& regizor_);
	const std::string& getRegizor() const;
	void setRating(const std::string& rating_);
	const std::string& getRating() const;
	void setFormat(const std::string& format_);
	const std::string& getFormat() const;
	void setPret(const float pret_);
	float getPret() const;

	float pretElevi() const;
};

#endif