#ifndef OFERTAGRUPELEVI_H
#define OFERTAGRUPELEVI_H

#include "OfertaBuilder.h"

class OfertaGrupEleviBuilder : public OfertaBuilder {
private:
	void buildNume() override;
	void buildBilete() override;
	void buildProcent() override;

public:
	OfertaGrupEleviBuilder();

	void buildOferta() override;
};

#endif
