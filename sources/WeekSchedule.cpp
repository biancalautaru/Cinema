#include "../headers/WeekSchedule.h"

WeekSchedule::WeekSchedule() {
}

WeekSchedule::~WeekSchedule() {
}

WeekSchedule::WeekSchedule(const std::vector<std::pair<std::string, DaySchedule>>& week):
	week(week) {
}

WeekSchedule::WeekSchedule(const WeekSchedule& copy):
	week(copy.week) {
}

WeekSchedule& WeekSchedule::operator=(const WeekSchedule& copy) {
	week = copy.week;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const WeekSchedule& schedule) {
	for (size_t i = 0; i < schedule.week.size(); i++)
		os << "- " << schedule.week[i].first << " -\n" << schedule.week[i].second << "\n";
	return os;
}

void WeekSchedule::setWeek(const std::vector<std::pair<std::string, DaySchedule>>& week_) {
	week = week_;
}

const std::vector<std::pair<std::string, DaySchedule>>& WeekSchedule::getWeek() const {
	return week;
}

WeekSchedule WeekSchedule::addDay(const std::pair<std::string, DaySchedule>& daySchedule) {
	week.push_back(daySchedule);
	WeekSchedule schedule;
	schedule.setWeek(week);
	return schedule;
}

WeekSchedule WeekSchedule::generate(const std::vector<Movie>& movies, const std::vector<Auditorium>& auditoriums) {
	WeekSchedule schedule;
	for (int i = 0; i < 7; i++) {
		std::string day;
		switch (i) {
		case 0: day = "Monday";
			break;
		case 1: day = "Tuesday";
			break;
		case 2: day = "Wednesday";
			break;
		case 3: day = "Thursday";
			break;
		case 4: day = "Friday";
			break;
		case 5: day = "Saturday";
			break;
		default: day = "Sunday";
		}
		DaySchedule daySchedule;
		daySchedule = daySchedule.generate(movies, auditoriums);
		std::vector<Screening> screenings = daySchedule.getDay();
		for (size_t j = 0; j < screenings.size(); j++)
			screenings[j].setDay(day);
		daySchedule.setDay(screenings);
		schedule.addDay({day, daySchedule});
	}
	return schedule;
}
