#ifndef SALABUILDER_H
#define SALABUILDER_H

#include "Sala.h"

class SalaBuilder {
private:
	Sala sala;

public:
	SalaBuilder();
	~SalaBuilder();

	SalaBuilder& numar(int numar);
	SalaBuilder& randuri(int randuri);
	SalaBuilder& coloane(int coloane);

	Sala build();
};

#endif
