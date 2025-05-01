#include "../headers/LocOcupat.h"

LocOcupat::LocOcupat():
	Exceptie("Alegeti locuri care nu sunt ocupate deja!\n\n")
{}

LocOcupat::LocOcupat(const std::string& mesaj) :
	Exceptie(mesaj)
{}