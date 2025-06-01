#ifndef SCREENING_H
#define SCREENING_H

#include <iostream>
#include <set>
#include "Movie.h"
#include "Auditorium.h"

/**
 * @class Screening
 * @brief Represents a scheduled movie screening.
 *
 * A screening includes the movie being shown, the day and time of the showing,
 * the auditorium where it takes place and the occupied seats.
 */
class Screening {
private:
	Movie movie;
	std::string day;
	std::string time;
	Auditorium auditorium;
	std::set<int> occupied;

public:
	Screening();

	~Screening();

	Screening(const Movie& movie, const std::string& day, const std::string& time, const Auditorium& auditorium,
	          const std::set<int>& occupied);

	Screening(const Screening& copy);

	Screening& operator=(const Screening& copy);

	/**
	 * @brief Prints information about the screening.
	 *
	 * Displays the movie title, the day and time of the screening and the auditorium layout
	 * with the occupied seats marked.
	 *
	 * @param os The output stream to write to.
	 * @param screening The Screening object to print.
	 * @return A reference to the output stream.
	 */
	friend std::ostream& operator<<(std::ostream& os, const Screening& screening);

	const Movie& getMovie() const;

	void setDay(const std::string& day_);

	const std::string& getDay() const;

	const std::string& getTime() const;

	const Auditorium& getAuditorium() const;

	void setOccupied(const std::set<int>& occupied_);

	const std::set<int>& getOccupied() const;

	/**
	 * @brief Calculates the number of available seats in the auditorium.
	 * @return The number of available seats.
	 */
	int availableSeats() const;
};

#endif
