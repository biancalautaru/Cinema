#include "../headers/OfertaBuilder.h"

OfertaBuilder::OfertaBuilder() {
	oferta = new Oferta();
}

Oferta* OfertaBuilder::getOferta() {
	return oferta;
}