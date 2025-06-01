#ifndef DAYSCHEDULE_H
#define DAYSCHEDULE_H

#include <iostream>
#include <vector>
#include "Screening.h"

/**
 * @class DaySchedule
 * @brief Represents the schedule for a single day.
 *
 * The DaySchedule class holds a list of screenings. It allows adding new
 * screenings and generating a schedule from available movies and auditoriums.
 */
class DaySchedule {
private:
	std::vector<Screening> day;

	void sortScreenings();

	std::string timeString(const int& hour);

	int nextTime(const int& minutes);

public:
	DaySchedule();
	
	~DaySchedule();

	explicit DaySchedule(const std::vector<Screening>& day);
	
	DaySchedule(const DaySchedule& copy);

	DaySchedule& operator=(const DaySchedule& copy);

	/**
	 * @brief Prints the daily schedule.
	 *
	 * Displays the time, auditorium, movie title and number of available seats for each screening.
	 *
	 * @param os The output stream to write to.
	 * @param schedule The DaySchedule object to print.
	 * @return A reference to the output stream.
	 */
	friend std::ostream& operator<<(std::ostream& os, const DaySchedule& schedule);

	void setDay(const std::vector<Screening>& day_);
	
	const std::vector<Screening>& getDay() const;

	/**
	 * @brief Adds a new screening to the day's schedule.
	 * @param screening The screening to add.
	 */
	void addScreening(const Screening& screening);

	/**
	 * @brief Generates a full day's schedule from a list of movies and auditoriums.
	 *
	 * This method randomly generates screening times and distributes movies across available
	 * auditoriums following a certain set of rules for the age rating of the movie, its format
	 * and the pauses between movies.
	 *
	 * @param moviesAux A list of available movies.
	 * @param auditoriumAux A list of available auditoriums.
	 * @return The generated daily schedule.
	 */
	DaySchedule generate(const std::vector<Movie>& moviesAux, const std::vector<Auditorium>& auditoriumAux);
};

#endif
