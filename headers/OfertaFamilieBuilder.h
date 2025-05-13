#ifndef OFERTAFAMILIE_H
#define OFERTAFAMILIE_H

#include "OfertaBuilder.h"

class OfertaFamilieBuilder : public OfertaBuilder {
private:
	void buildNume() override;
	void buildBilete() override;
	void buildProcent() override;

public:
	OfertaFamilieBuilder();

	void buildOferta() override;
};

#endif
