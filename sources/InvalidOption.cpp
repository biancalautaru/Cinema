#include "../headers/InvalidOption.h"

InvalidOption::InvalidOption():
	Exception("Enter a number corresponding to an existing option: ") {
}

InvalidOption::InvalidOption(const std::string& message):
	Exception(message) {
}
