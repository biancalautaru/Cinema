#include "../headers/Director.h"

Director::Director() {}

void Director::setOfertaBuilder(OfertaBuilder* ofertaBuilder) {
	this->ofertaBuilder = ofertaBuilder;
}

void Director::buildOferta() {
	ofertaBuilder->buildOferta();
}

Oferta* Director::getOferta() {
	return ofertaBuilder->getOferta();
}