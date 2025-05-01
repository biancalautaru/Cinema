#ifndef INPUTGRESIT_H
#define INPUTGRESIT_H

#include "Exceptie.h"

class InputGresit : public Exceptie {
public:
	InputGresit();
	explicit InputGresit(const std::string& mesaj);
};

#endif
