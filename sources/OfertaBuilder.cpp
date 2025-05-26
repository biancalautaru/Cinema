#include "../headers/OfertaBuilder.h"

OfertaBuilder::OfertaBuilder() {
	oferta = new Oferta();
}

OfertaBuilder::~OfertaBuilder() {
	delete oferta;
}

OfertaBuilder::OfertaBuilder(const OfertaBuilder& copie):
	oferta(copie.oferta) {
}

OfertaBuilder& OfertaBuilder::operator=(const OfertaBuilder& copie) {
	oferta = copie.oferta;
	return *this;
}

Oferta* OfertaBuilder::getOferta() {
	return oferta;
}
