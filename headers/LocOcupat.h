#ifndef LOCOCUPAT_H
#define LOCOCUPAT_H

#include "Exceptie.h"

class LocOcupat : public Exceptie {
public:
	LocOcupat();
	explicit LocOcupat(const std::string& mesaj);
};

#endif
