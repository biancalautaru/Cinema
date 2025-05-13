#include "../headers/Exceptie.h"

Exceptie::Exceptie() = default;

Exceptie::Exceptie(const std::string& mesaj):
	mesaj(mesaj)
{}

const char* Exceptie::what() const noexcept {
	return mesaj.c_str();
}