#include "../headers/OptiuneInexistenta.h"

OptiuneInexistenta::OptiuneInexistenta():
	Exceptie("Introduceti numarul corespunzator unei optiuni existente: ")
{}

OptiuneInexistenta::OptiuneInexistenta(const std::string& mesaj):
	Exceptie(mesaj)
{}