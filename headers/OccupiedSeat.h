#ifndef OCCUPIEDSEAT_H
#define OCCUPIEDSEAT_H

#include "Exception.h"

class OccupiedSeat : public Exception {
public:
	OccupiedSeat();
	explicit OccupiedSeat(const std::string& message);
};

#endif
