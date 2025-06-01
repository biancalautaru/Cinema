#ifndef WRONGINPUT_H
#define WRONGINPUT_H

#include "Exception.h"

/**
 * @class WrongInput
 * @brief Represents an exception thrown when the user's input cannot be
 * interpreted correctly.
 *
 * The WrongInput class inherits from the Exception class and is used to indicate
 * that the user has provided unprocessable input within the current context.
 */
class WrongInput : public Exception {
public:
	WrongInput();

	explicit WrongInput(const std::string& message);
};

#endif
