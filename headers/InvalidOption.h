#ifndef INVALIDOPTION_H
#define INVALIDOPTION_H

#include "Exception.h"

class InvalidOption : public Exception {
public:
	InvalidOption();
	explicit InvalidOption(const std::string& message);
};

#endif
