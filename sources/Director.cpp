#include "../headers/Director.h"

Director::Director() {}

void Director::setOfertaBuilder(OfertaBuilder* oferta_builder_) {
	oferta_builder = oferta_builder_;
}

Director::Director(OfertaBuilder* oferta_builder):
	oferta_builder(oferta_builder)
{}

void Director::buildOferta() {
	oferta_builder->buildOferta();
}

Oferta* Director::getOferta() {
	return oferta_builder->getOferta();
}