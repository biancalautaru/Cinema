#include "../headers/Film.h"

Film::Film() {};

Film::~Film() {};

Film::Film(const std::string& nume, const std::vector<std::string>& gen, const int& durata, const int& an, const std::string& regizor, const std::string& rating, const std::string& format, const double& pret):
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

const std::string& Film::getNume() const {
	return nume;
}

const std::vector<std::string>& Film::getGen() const {
	return gen;
}

int Film::getDurata() const {
	return durata;
}

const std::string& Film::getRating() const {
	return rating;
}

const std::string& Film::getFormat() const {
	return format;
}

double Film::getPret() const {
	return pret;
}

double Film::pretElevi() const {
	return pret * 0.8;
}