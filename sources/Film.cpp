#include "../headers/Film.h"

Film::Film() {};

Film::~Film() {};

Film::Film(const std::string& nume, const std::vector<std::string>& gen, const int durata, const int an, const std::string& regizor, const std::string& rating, const std::string& format, const double pret):
	nume(nume),
	gen(gen),
	durata(durata),
	an(an),
	regizor(regizor),
	rating(rating),
	format(format),
	pret(pret)
{}

Film::Film(const Film& copie):
	nume(copie.nume),
	gen(copie.gen),
	durata(copie.durata),
	an(copie.an),
	regizor(copie.regizor),
	rating(copie.rating),
	format(copie.format),
	pret(copie.pret)
{}

Film& Film::operator=(const Film& copie) {
	nume = copie.nume;
	gen = copie.gen;
	durata = copie.durata;
	an = copie.an;
	regizor = copie.regizor;
	rating = copie.rating;
	format = copie.format;
	pret = copie.pret;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Film& film) {
	os << "Nume: " << film.nume << "\n";
	os << "Gen: ";
	for (size_t i = 0; i < film.gen.size(); i++)
		if (i != film.gen.size() - 1)
			os << film.gen[i] << ", ";
		else
			os << film.gen[i] << "\n";
	os << "Durata: " << film.durata << " minute\n";
	os << "An lansare: " << film.an << "\n";
	os << "Regizor: " << film.regizor << "\n";
	os << "Rating: " << film.rating << "\n";
	os << "Format: " << film.format << "\n";
	os << "Pret normal: " << film.pret << " lei, Pret elevi: " << film.pretElevi() << " lei\n";
	return os;
}

void Film::setNume(const std::string& nume_) {
	nume = nume_;
}

const std::string& Film::getNume() const {
	return nume;
}

void Film::setGen(const std::vector<std::string>& gen_) {
	gen = gen_;
}

const std::vector<std::string>& Film::getGen() const {
	return gen;
}

void Film::setDurata(const int durata_) {
	durata = durata_;
}

int Film::getDurata() const {
	return durata;
}

void Film::setAn(const int an_) {
	an = an_;
}

int Film::getAn() const {
	return an;
}

void Film::setRegizor(const std::string& regizor_) {
	regizor = regizor_;
}

const std::string& Film::getRegizor() const {
	return regizor;
}

void Film::setRating(const std::string& rating_) {
	rating = rating_;
}

const std::string& Film::getRating() const {
	return rating;
}

void Film::setFormat(const std::string& format_) {
	format = format_;
}

const std::string& Film::getFormat() const {
	return format;
}

void Film::setPret(const double pret_) {
	pret = pret_;
}

double Film::getPret() const {
	return pret;
}

double Film::pretElevi() const {
	return pret * 0.8;
}