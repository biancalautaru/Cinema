#include "../headers/Movie.h"

Movie::Movie() {
}

Movie::~Movie() {
}

Movie::Movie(const std::string& name, const std::vector<std::string>& genre, const int& runtime, const int& year,
           const std::string& director, const std::string& rating, const std::string& format, const double& price):
	name(name),
	genre(genre),
	runtime(runtime),
	year(year),
	director(director),
	rating(rating),
	format(format),
	price(price) {
}

Movie::Movie(const Movie& copy):
	name(copy.name),
	genre(copy.genre),
	runtime(copy.runtime),
	year(copy.year),
	director(copy.director),
	rating(copy.rating),
	format(copy.format),
	price(copy.price) {
}

Movie& Movie::operator=(const Movie& copy) {
	name = copy.name;
	genre = copy.genre;
	runtime = copy.runtime;
	year = copy.year;
	director = copy.director;
	rating = copy.rating;
	format = copy.format;
	price = copy.price;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Movie& movie) {
	os << "Name: " << movie.name << "\n";
	os << "Genre: ";
	for (size_t i = 0; i < movie.genre.size(); i++)
		if (i != movie.genre.size() - 1)
			os << movie.genre[i] << ", ";
		else
			os << movie.genre[i] << "\n";
	os << "Runtime: " << movie.runtime << " minute\n";
	os << "Year: " << movie.year << "\n";
	os << "Director: " << movie.director << "\n";
	os << "Rating: " << movie.rating << "\n";
	os << "Format: " << movie.format << "\n";
	os << "Normal price: " << movie.price << " lei, Student price: " << movie.studentPrice() << " lei\n";
	return os;
}

const std::string& Movie::getName() const {
	return name;
}

const std::vector<std::string>& Movie::getGenre() const {
	return genre;
}

int Movie::getRuntime() const {
	return runtime;
}

const std::string& Movie::getRating() const {
	return rating;
}

const std::string& Movie::getFormat() const {
	return format;
}

double Movie::getPrice() const {
	return price;
}

double Movie::studentPrice() const {
	return price * 0.8;
}
