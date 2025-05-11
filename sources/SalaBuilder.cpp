#include "../headers/SalaBuilder.h"

SalaBuilder::SalaBuilder() {}

SalaBuilder::~SalaBuilder() {}

SalaBuilder& SalaBuilder::numar(int numar_) {
	sala.numar = numar_;
	return *this;
}

SalaBuilder& SalaBuilder::randuri(int randuri_) {
	sala.randuri = randuri_;
	return *this;
}

SalaBuilder& SalaBuilder::coloane(int coloane_) {
	sala.coloane = coloane_;
	return *this;
}

Sala SalaBuilder::build() {
	return sala;
}