#include "../headers/Exceptie.h"

Exceptie::Exceptie() {}

Exceptie::Exceptie(const std::string& mesaj):
	mesaj(mesaj)
{}

const char* Exceptie::what() const noexcept {
	return mesaj.c_str();
}

OptiuneInexistenta::OptiuneInexistenta():
	Exceptie("Introduceti numarul corespunzator unei optiuni existente: ")
{}

OptiuneInexistenta::OptiuneInexistenta(const std::string& mesaj):
	Exceptie(mesaj)
{}

InputGresit::InputGresit():
	Exceptie("Introduceti numere separate prin spatii: ") {}

InputGresit::InputGresit(const std::string& mesaj) :
	Exceptie(mesaj)
{}

LocOcupat::LocOcupat():
	Exceptie("Alegeti locuri care nu sunt ocupate deja!\n\n")
{}

LocOcupat::LocOcupat(const std::string& mesaj) :
	Exceptie(mesaj)
{}

ProdusInexistent::ProdusInexistent():
	Exceptie("Introduceti numere corespunzatoare produselor existente: ")
{}

ProdusInexistent::ProdusInexistent(const std::string& mesaj):
	Exceptie(mesaj)
{}