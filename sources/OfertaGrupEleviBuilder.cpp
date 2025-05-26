#include "../headers/OfertaGrupEleviBuilder.h"

OfertaGrupEleviBuilder::OfertaGrupEleviBuilder() {
}

void OfertaGrupEleviBuilder::buildNume() {
	oferta->setNume("Oferta Grup Elevi");
}

void OfertaGrupEleviBuilder::buildBilete() {
	oferta->setBilete(4);
}

void OfertaGrupEleviBuilder::buildProcent() {
	oferta->setProcent(30);
}

void OfertaGrupEleviBuilder::buildOferta() {
	buildNume();
	buildBilete();
	buildProcent();
}
