#ifndef WEEKSCHEDULE_H
#define WEEKSCHEDULE_H

#include <iostream>
#include <vector>
#include "DaySchedule.h"

/**
 * @class WeekSchedule
 * @brief Represents the schedule for each day of the week.
 *
 * The WeekSchedule class holds a list of daily schedules, each paired with a weekday name.
 * Itprovides functionality to add daily schedules and to generate a full week's schedule
 * from available movies and auditoriums.
 */
class WeekSchedule {
private:
	std::vector<std::pair<std::string, DaySchedule>> week;

public:
	WeekSchedule();

	~WeekSchedule();

	explicit WeekSchedule(const std::vector<std::pair<std::string, DaySchedule>>& week);

	WeekSchedule(const WeekSchedule& copy);

	WeekSchedule& operator=(const WeekSchedule& copy);

	/**
	 * @brief Prints the weekly schedule.
	 *
	 * Displays the daily schedule for each day of the week.
	 *
	 * @param os The output stream to write to.
	 * @param schedule The WeekSchedule object to print.
	 * @return A reference to the output stream.
	 */
	friend std::ostream& operator<<(std::ostream& os, const WeekSchedule& schedule);

	void setWeek(const std::vector<std::pair<std::string, DaySchedule>>& week_);

	const std::vector<std::pair<std::string, DaySchedule>>& getWeek() const;

	/**
	 * @brief Adds a new daily schedule to the week's schedule.
	 * @param daySchedule The daily schedule to add.
	 * @return The weekly schedule.
	 */
	WeekSchedule addDay(const std::pair<std::string, DaySchedule>& daySchedule);

	/**
	 * @brief Generates a complete weekly schedule from a list of movies and auditoriums.
	 *
	 * For each day of the week, this method calls the DaySchedule::generate() method
	 * to create the day's schedule.
	 *
	 * @param movies A list of available movies.
	 * @param auditoriums A list of available auditoriums.
	 * @return The generated weekly schedule.
	 */
	WeekSchedule generate(const std::vector<Movie>& movies, const std::vector<Auditorium>& auditoriums);
};

#endif
