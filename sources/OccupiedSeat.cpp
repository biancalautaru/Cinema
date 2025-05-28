#include "../headers/OccupiedSeat.h"

OccupiedSeat::OccupiedSeat():
	Exception("Choose seats that aren't already occupied!\n\nEnter the desired seats (separated by spaces): ") {
}

OccupiedSeat::OccupiedSeat(const std::string& message) :
	Exception(message) {
}
