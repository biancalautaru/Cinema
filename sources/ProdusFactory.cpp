#include "../headers/ProdusFactory.h"

#include "../headers/Mancare.h"
#include "../headers/Bautura.h"
#include "../headers/Meniu.h"
#include "../headers/Suvenir.h"

ProdusFactory::ProdusFactory() {}

std::shared_ptr<Produs> ProdusFactory::createProdus(TipProdus tip, const std::string& nume, double pret, int cantitate) {
	if (tip == MANCARE)
		return std::make_shared<Mancare>(nume, pret, cantitate);
	if (tip == BAUTURA)
		return std::make_shared<Bautura>(nume, pret, cantitate);
	return nullptr;
}

std::shared_ptr<Produs> ProdusFactory::createProdus(TipProdus tip, const std::string& nume, double pret, const std::string& nume_mancare, int gramaj, const std::string& nume_bautura, int volum, MarimeMeniu marime) {
	if (tip == MENIU)
		return std::make_shared<Meniu>(nume, pret, nume_mancare, gramaj, nume_bautura, volum, marime);
	return nullptr;
}

std::shared_ptr<Produs> ProdusFactory::createProdus(TipProdus tip, const std::string& nume, double pret, const std::string& nume_film) {
	if (tip == SUVENIR)
		return std::make_shared<Suvenir>(nume, pret, nume_film);
	return nullptr;
}