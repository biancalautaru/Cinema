#ifndef DAYSCHEDULE_H
#define DAYSCHEDULE_H

#include <iostream>
#include <vector>
#include "Screening.h"

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
	friend std::ostream& operator<<(std::ostream& os, const DaySchedule& schedule);

	void setDay(const std::vector<Screening>& day_);
	const std::vector<Screening>& getDay() const;

	void addScreening(const Screening& screening);
	DaySchedule generate(const std::vector<Movie>& moviesAux, const std::vector<Auditorium>& auditoriumAux);
};

#endif
