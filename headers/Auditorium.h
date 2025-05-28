#ifndef AUDITORIUM_H
#define AUDITORIUM_H

#include <iostream>

class Auditorium {
private:
	int number;
	int rows;
	int columns;

public:
	Auditorium();
	~Auditorium();

	Auditorium(const int& number, const int& rows, const int& columns);
	Auditorium(const Auditorium& copy);

	Auditorium& operator=(const Auditorium& copy);
	friend std::ostream& operator<<(std::ostream& os, const Auditorium& auditorium);

	int getNumber() const;
	int getRows() const;
	int getColumns() const;
};

#endif
