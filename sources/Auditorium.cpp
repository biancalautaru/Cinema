#include "../headers/Auditorium.h"

Auditorium::Auditorium() {
}

Auditorium::~Auditorium() {
}

Auditorium::Auditorium(const int& number, const int& rows, const int& columns):
	number(number),
	rows(rows),
	columns(columns) {
}

Auditorium::Auditorium(const Auditorium& copy):
	number(copy.number),
	rows(copy.rows),
	columns(copy.columns) {
}

Auditorium& Auditorium::operator=(const Auditorium& copy) {
	number = copy.number;
	rows = copy.rows;
	columns = copy.columns;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Auditorium& auditorium) {
	os << "- Auditorium " << auditorium.number << " -\n";
	for (int i = 0; i < 2 * auditorium.columns - 4; i++)
		os << "-";
	os << " Screen ";
	for (int i = 0; i < 2 * auditorium.columns - 5; i++)
		os << "-";
	os << "\n";
	for (int i = 0; i < auditorium.rows; i++) {
		for (int j = 0; j < auditorium.columns; j++) {
			if (i * auditorium.columns + j + 1 < 10)
				os << " ";
			if (i * auditorium.columns + j + 1 < 100)
				os << " ";
			os << i * auditorium.columns + j + 1;
			if (j != auditorium.columns - 1)
				os << " ";
		}
		os << "\n";
	}
	return os;
}

int Auditorium::getNumber() const {
	return number;
}

int Auditorium::getRows() const {
	return rows;
}

int Auditorium::getColumns() const {
	return columns;
}
