#ifndef SCREENING_H
#define SCREENING_H

#include <iostream>
#include <set>
#include "Movie.h"
#include "Auditorium.h"

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
	friend std::ostream& operator<<(std::ostream& os, const Screening& screening);

	const Movie& getMovie() const;
	void setDay(const std::string& day_);
	const std::string& getDay() const;
	const std::string& getTime() const;
	const Auditorium& getAuditorium() const;
	void setOccupied(const std::set<int>& occupied_);
	const std::set<int>& getOccupied() const;
	int availableSeats() const;
};

#endif
