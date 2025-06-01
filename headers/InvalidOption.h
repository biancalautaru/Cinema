#ifndef INVALIDOPTION_H
#define INVALIDOPTION_H

#include "Exception.h"

/**
 * @class InvalidOption
 * @brief Represents an exception thrown when the user selects an invalid option
 * from the menu.
 *
 * The InvalidOption class inherits from the Exception class and is used to
 * indicate that an unrecognized option was provided by the user.
 */
class InvalidOption : public Exception {
public:
	InvalidOption();

	explicit InvalidOption(const std::string& message);
};

#endif
