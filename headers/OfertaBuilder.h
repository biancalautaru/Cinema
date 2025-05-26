#ifndef OFERTABUILDER_H
#define OFERTABUILDER_H

#include "Oferta.h"

class OfertaBuilder {
protected:
	Oferta* oferta;

	virtual void buildNume() = 0;
	virtual void buildBilete() = 0;
	virtual void buildProcent() = 0;

public:
	OfertaBuilder();
	virtual ~OfertaBuilder();

	OfertaBuilder(const OfertaBuilder& copie);
	OfertaBuilder& operator=(const OfertaBuilder& copie);

	virtual void buildOferta() = 0;

	Oferta* getOferta();
};

#endif
