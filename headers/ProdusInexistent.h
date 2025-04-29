#ifndef PRODUSINEXISTENT_H
#define PRODUSINEXISTENT_H

#include "Exceptie.h"

class ProdusInexistent : public Exceptie {
public:
	ProdusInexistent();
	explicit ProdusInexistent(const std::string& mesaj);
};

#endif
