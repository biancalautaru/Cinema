#include "../headers/DaySchedule.h"

#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>

DaySchedule::DaySchedule() {
}

DaySchedule::~DaySchedule() {
}

DaySchedule::DaySchedule(const std::vector<Screening>& day):
	day(day) {
	sortScreenings();
}

DaySchedule::DaySchedule(const DaySchedule& copy):
	day(copy.day) {
}

DaySchedule& DaySchedule::operator=(const DaySchedule& copy) {
	day = copy.day;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const DaySchedule& schedule) {
	for (size_t i = 0; i < schedule.day.size(); i++) {
		const Screening& screening = schedule.day[i];
		os << screening.getTime() << " | ";
		os << "Aud. " << screening.getAuditorium().getNumber() << " | ";
		os << screening.getMovie().getTitle() << " | ";
		const int& seats = screening.availableSeats();
		if (seats == 1)
			os << seats << " seat available";
		else
			os << seats << " seats available";
		os << "\n";
	}
	return os;
}

void DaySchedule::setDay(const std::vector<Screening>& day_) {
	day = day_;
	sortScreenings();
}

const std::vector<Screening>& DaySchedule::getDay() const {
	return day;
}

void DaySchedule::sortScreenings() {
	std::sort(day.begin(), day.end(), [](const Screening& s1, const Screening& s2) {
		return s1.getTime() < s2.getTime();
	});
}

std::string DaySchedule::timeString(const int& hour) {
	std::string hourStr(5, ' ');
	hourStr[0] = '0' + hour / 60 / 10;
	hourStr[1] = '0' + hour / 60 % 10;
	hourStr[2] = ':';
	hourStr[3] = '0' + hour % 60 / 10;
	hourStr[4] = '0' + hour % 60 % 10;
	return hourStr;
}

int DaySchedule::nextTime(const int& minutes) {
	int min = minutes % 60;
	if (min == 0 || min == 15 || min == 30 || min == 45)
		return minutes + 30;
	if (min < 15)
		return minutes + 15 - min + 30;
	if (min < 30)
		return minutes + 30 - min + 30;
	if (min < 45)
		return minutes + 45 - min + 30;
	return minutes + 60 - min + 30;
}

void DaySchedule::addScreening(const Screening& screening) {
	day.push_back(screening);
	sortScreenings();
}

DaySchedule DaySchedule::generate(const std::vector<Movie>& movieAux, const std::vector<Auditorium>& auditoriumAux) {
	std::vector<Movie> movies = movieAux;
	std::vector<Auditorium> auditoriums = auditoriumAux;
	long long seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(movies.begin(), movies.end(), std::default_random_engine(seed));
	std::shuffle(auditoriums.begin(), auditoriums.end(), std::default_random_engine(seed));

	std::vector<int> moviesAG, moviesIM, movies3D, moviesOther;
	for (size_t i = 0; i < movies.size(); i++)
		if (movies[i].getRating() == "AG")
			moviesAG.push_back(i);
		else if (movies[i].getRating() == "IM-18")
			moviesIM.push_back(i);
		else if (movies[i].getFormat() == "3D")
			movies3D.push_back(i);
		else
			moviesOther.push_back(i);

	DaySchedule schedule;
	std::vector<int> times;

	int start = 720;
	for (size_t i = 0; i < auditoriums.size(); i++)
		times.push_back(start);

	for (size_t i = 0; i < moviesAG.size(); i++)
		for (size_t j = 0; j < times.size(); j++) {
			int end = nextTime(times[j] + movies[moviesAG[i]].getRuntime());
			if (end <= 960) {
				Screening screening(movies[moviesAG[i]], "", timeString(times[j]), auditoriums[j], {});
				times[j] = end;
				schedule.addScreening(screening);
				break;
			}
		}

	for (size_t i = 0; i < movies3D.size(); i++)
		for (size_t j = 0; j < times.size(); j++) {
			int end = nextTime(times[j] + movies[movies3D[i]].getRuntime());
			if (end <= 1410) {
				Screening screening(movies[movies3D[i]], "", timeString(times[j]), auditoriums[j], {});
				times[j] = end;
				schedule.addScreening(screening);
				break;
			}
		}

	start = 960;
	for (size_t i = 0; i < auditoriums.size(); i++)
		if (times[i] < start)
			times[i] = start;

	for (size_t i = 0; i < moviesOther.size(); i++)
		for (size_t j = 0; j < times.size(); j++) {
			int end = nextTime(times[j] + movies[moviesOther[i]].getRuntime());
			if (end <= 1410) {
				Screening screening(movies[moviesOther[i]], "", timeString(times[j]), auditoriums[j], {});
				times[j] = end;
				schedule.addScreening(screening);
				break;
			}
		}

	start = 1200;
	for (size_t i = 0; i < auditoriums.size(); i++)
		if (times[i] < start)
			times[i] = start;

	for (size_t i = 0; i < moviesIM.size(); i++)
		for (size_t j = 0; j < times.size(); j++) {
			int end = nextTime(times[j] + movies[moviesIM[i]].getRuntime());
			if (end <= 1470) {
				Screening screening(movies[moviesIM[i]], "", timeString(times[j]), auditoriums[j], {});
				times[j] = end;
				schedule.addScreening(screening);
				break;
			}
		}

	return schedule;
}
