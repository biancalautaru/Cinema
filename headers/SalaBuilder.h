#ifndef SALABUILDER_H
#define SALABUILDER_H

#include "Sala.h"

class SalaBuilder {
private:
	Sala sala;

public:
	SalaBuilder();
	~SalaBuilder();

	SalaBuilder& numar(int numar_);
	SalaBuilder& randuri(int randuri_);
	SalaBuilder& coloane(int coloane_);

	Sala build();
};

#endif
