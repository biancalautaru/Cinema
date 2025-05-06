#include "../headers/ProdusInexistent.h"

ProdusInexistent::ProdusInexistent():
	Exceptie("Introduceti numere corespunzatoare produselor existente: ")
{}

ProdusInexistent::ProdusInexistent(const std::string& mesaj):
	Exceptie(mesaj)
{}