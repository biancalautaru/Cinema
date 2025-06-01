#ifndef OCCUPIEDSEAT_H
#define OCCUPIEDSEAT_H

#include "Exception.h"

/**
 * @class OccupiedSeat
 * @brief Represents an exception thrown when the user inputs a wrong seat number
 * when making a reservation.
 *
 * The OccupiedSeat class inherits from the Exception class and is used to indicate
 * that the user provided a seat number that doesn't exist in the selected auditorium.
 */
class OccupiedSeat : public Exception {
public:
	OccupiedSeat();

	explicit OccupiedSeat(const std::string& message);
};

#endif
