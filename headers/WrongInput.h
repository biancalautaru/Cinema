#ifndef WRONGINPUT_H
#define WRONGINPUT_H

#include "Exception.h"

class WrongInput : public Exception {
public:
	WrongInput();
	explicit WrongInput(const std::string& message);
};

#endif
