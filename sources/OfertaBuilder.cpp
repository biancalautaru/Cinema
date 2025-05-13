#include "../headers/OfertaBuilder.h"

OfertaBuilder::OfertaBuilder() {
	oferta = new Oferta();
}

OfertaBuilder::~OfertaBuilder() {
	delete oferta;
}

Oferta* OfertaBuilder::getOferta() {
	return oferta;
}