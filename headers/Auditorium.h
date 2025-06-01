#ifndef AUDITORIUM_H
#define AUDITORIUM_H

#include <iostream>

/**
 * @class Auditorium
 * @brief Represents an auditorium in the movie theater.
 *
 * The Auditorium class stores the auditorium number along with the number of rows
 * and columns of seats it contains.
 */
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

	/**
	 * @brief Prints the layout of the auditorium.
	 *
	 * Displays a line representing the screen and a matrix of the seat numbers below it.
	 *
	 * @param os The output stream to write to.
	 * @param auditorium The Auditorium object to print.
	 * @return A reference to the output stream.
	 */
	friend std::ostream& operator<<(std::ostream& os, const Auditorium& auditorium);

	int getNumber() const;

	int getRows() const;

	int getColumns() const;
};

#endif
