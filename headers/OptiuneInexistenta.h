#ifndef OPTIUNEINEXISTENTA_H
#define OPTIUNEINEXISTENTA_H

#include "Exceptie.h"

class OptiuneInexistenta : public Exceptie {
public:
	OptiuneInexistenta();
	explicit OptiuneInexistenta(const std::string& mesaj);
};

#endif
