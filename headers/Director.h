#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "OfertaBuilder.h"

class Director {
private:
	OfertaBuilder* ofertaBuilder;

public:
	Director();

	void setOfertaBuilder(OfertaBuilder* ofertaBuilder);

	void buildOferta();

	Oferta* getOferta();
};

#endif
