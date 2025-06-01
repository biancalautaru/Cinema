#include "../headers/Screening.h"

Screening::Screening() {
}

Screening::~Screening() {
}

Screening::Screening(const Movie& movie, const std::string& day, const std::string& time, const Auditorium& auditorium,
                     const std::set<int>& occupied):
	movie(movie),
	day(day),
	time(time),
	auditorium(auditorium),
	occupied(occupied) {
}

Screening::Screening(const Screening& copy):
	movie(copy.movie),
	day(copy.day),
	time(copy.time),
	auditorium(copy.auditorium),
	occupied(copy.occupied) {
}

Screening& Screening::operator=(const Screening& copy) {
	movie = copy.movie;
	day = copy.day;
	time = copy.time;
	auditorium = copy.auditorium;
	occupied = copy.occupied;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Screening& screening) {
	os << screening.movie.getTitle() << "\n";
	os << screening.day << ", " << screening.time << "\n";
	os << "Aud. " << screening.auditorium.getNumber() << "\n";
	const int& rows = screening.auditorium.getRows();
	const int& columns = screening.auditorium.getColumns();
	for (int i = 0; i < 2 * columns - 4; i++)
		os << "-";
	os << " Screen ";
	for (int i = 0; i < 2 * columns - 3; i++)
		os << "-";
	os << "\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (screening.occupied.find(i * columns + j + 1) == screening.occupied.end()) {
				if (i * columns + j + 1 < 10)
					os << " ";
				if (i * columns + j + 1 < 100)
					os << " ";
				os << i * columns + j + 1;
			}
			else
				os << "  X";
			if (j != columns - 1)
				os << " ";
		}
		os << "\n";
	}
	return os;
}

const Movie& Screening::getMovie() const {
	return movie;
}

void Screening::setDay(const std::string& day_) {
	day = day_;
}

const std::string& Screening::getDay() const {
	return day;
}

const std::string& Screening::getTime() const {
	return time;
}

const Auditorium& Screening::getAuditorium() const {
	return auditorium;
}

void Screening::setOccupied(const std::set<int>& occupied_) {
	occupied = occupied_;
}

const std::set<int>& Screening::getOccupied() const {
	return occupied;
}

int Screening::availableSeats() const {
	return auditorium.getRows() * auditorium.getColumns() - occupied.size();
}
