#include "../headers/InputGresit.h"

InputGresit::InputGresit():
	Exceptie("Introduceti numere separate prin spatii: ") {}

InputGresit::InputGresit(const std::string& mesaj) :
	Exceptie(mesaj)
{}