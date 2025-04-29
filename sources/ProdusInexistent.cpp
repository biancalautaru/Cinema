#include "../headers/ProdusInexistent.h"

ProdusInexistent::ProdusInexistent() {}

ProdusInexistent::ProdusInexistent(const std::string& mesaj):
	Exceptie(mesaj)
{}