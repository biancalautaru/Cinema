#include "../headers/LocOcupat.h"

LocOcupat::LocOcupat():
	Exceptie("Alegeti locuri care nu sunt ocupate deja!\n\nIntroduceti locurile dorite (separate prin spatii): ")
{}

LocOcupat::LocOcupat(const std::string& mesaj) :
	Exceptie(mesaj)
{}