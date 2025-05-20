#ifndef PRODUSFACTORY_H
#define PRODUSFACTORY_H

#include "Produs.h"
#include "Meniu.h"

enum TipProdus {
	MANCARE,
	BAUTURA,
	MENIU,
	SUVENIR
};

class ProdusFactory {
public:
	ProdusFactory();

	std::shared_ptr<Produs> createProdus(TipProdus tip, const std::string& nume, double pret, int cantitate);
	std::shared_ptr<Produs> createProdus(TipProdus tip, const std::string& nume, double pret, const std::string& nume_mancare, int gramaj, const std::string& nume_bautura, int volum, MarimeMeniu marime);
	std::shared_ptr<Produs> createProdus(TipProdus tip, const std::string& nume, double pret, const std::string& nume_film);
};

#endif
