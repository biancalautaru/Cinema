#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <vector>
#include <string>

class Movie {
private:
	std::string name;
	std::vector<std::string> genre;
	int runtime;
	int year;
	std::string director;
	std::string rating;
	std::string format;
	double price;

public:
	Movie();
	~Movie();

	Movie(const std::string& name, const std::vector<std::string>& genre, const int& runtime, const int& year,
	     const std::string& director, const std::string& rating, const std::string& format, const double& price);
	Movie(const Movie& copy);

	Movie& operator=(const Movie& copy);
	friend std::ostream& operator<<(std::ostream& os, const Movie& movie);

	const std::string& getName() const;
	const std::vector<std::string>& getGenre() const;
	int getRuntime() const;
	const std::string& getRating() const;
	const std::string& getFormat() const;
	double getPrice() const;

	double studentPrice() const;
};

#endif
