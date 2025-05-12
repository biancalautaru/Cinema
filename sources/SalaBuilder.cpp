#include "../headers/SalaBuilder.h"

SalaBuilder::SalaBuilder() {}

SalaBuilder::~SalaBuilder() {}

SalaBuilder& SalaBuilder::numar(int numar) {
	sala.numar = numar;
	return *this;
}

SalaBuilder& SalaBuilder::randuri(int randuri) {
	sala.randuri = randuri;
	return *this;
}

SalaBuilder& SalaBuilder::coloane(int coloane) {
	sala.coloane = coloane;
	return *this;
}

Sala SalaBuilder::build() {
	return sala;
}