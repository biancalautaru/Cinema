#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <vector>
#include <string>

/**
 * @class Movie
 * @brief Represents a movie and stores the information related to it.
 *
 * The Movie class contains detailed information about a movie, including its title,
 * genre list, runtime, release year, director, age rating, format and price.
 */
class Movie {
private:
	std::string title;
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

	Movie(const std::string& title, const std::vector<std::string>& genre, const int& runtime, const int& year,
	     const std::string& director, const std::string& rating, const std::string& format, const double& price);

	Movie(const Movie& copy);

	Movie& operator=(const Movie& copy);

	/**
	 * @brief Prints information about the movie.
	 *
	 * Displays the movie title, year, genre list, runtime, release year, director, age rating, format,
	 * normal price and student price in a readable form.
	 *
	 * @param os The output stream to write to.
	 * @param movie The Movie object to print.
	 * @return A reference to the output stream.
	 */
	friend std::ostream& operator<<(std::ostream& os, const Movie& movie);

	const std::string& getTitle() const;

	const std::vector<std::string>& getGenre() const;

	int getRuntime() const;

	const std::string& getRating() const;

	const std::string& getFormat() const;

	double getPrice() const;

	/**
	 * @brief Gets the reduced price that students benefit from.
	 * @return The student price.
	 */
	double studentPrice() const;
};

#endif
