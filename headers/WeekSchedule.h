#ifndef WEEKSCHEDULE_H
#define WEEKSCHEDULE_H

#include <iostream>
#include <vector>
#include "DaySchedule.h"

class WeekSchedule {
private:
	std::vector<std::pair<std::string, DaySchedule>> week;

public:
	WeekSchedule();
	~WeekSchedule();

	explicit WeekSchedule(const std::vector<std::pair<std::string, DaySchedule>>& week);
	WeekSchedule(const WeekSchedule& copy);

	WeekSchedule& operator=(const WeekSchedule& copy);
	friend std::ostream& operator<<(std::ostream& os, const WeekSchedule& schedule);

	void setWeek(const std::vector<std::pair<std::string, DaySchedule>>& week_);
	const std::vector<std::pair<std::string, DaySchedule>>& getWeek() const;

	WeekSchedule addDay(const std::pair<std::string, DaySchedule>& daySchedule);
	WeekSchedule generate(const std::vector<Movie>& movies, const std::vector<Auditorium>& auditoriums);
};

#endif
