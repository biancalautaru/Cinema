#include "../headers/OfertaFamilieBuilder.h"

OfertaFamilieBuilder::OfertaFamilieBuilder() {
}

void OfertaFamilieBuilder::buildNume() {
	oferta->setNume("Oferta Familie");
}

void OfertaFamilieBuilder::buildBilete() {
	oferta->setBilete(-1);
}

void OfertaFamilieBuilder::buildProcent() {
	oferta->setProcent(20);
}

void OfertaFamilieBuilder::buildOferta() {
	buildNume();
	buildBilete();
	buildProcent();
}
