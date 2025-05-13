#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "OfertaBuilder.h"

class Director {
private:
	OfertaBuilder* oferta_builder;

public:
	Director();

	explicit Director(OfertaBuilder* oferta_builder);

	void setOfertaBuilder(OfertaBuilder* oferta_builder);

	void buildOferta();

	Oferta* getOferta();
};

#endif
