#include "../headers/Client.h"

#include <iostream>

Client::Client() {
}

Client::~Client() {
}

Client::Client(const std::string& nume, const std::string& email, const std::string& telefon):
	nume(nume),
	email(email),
	telefon(telefon) {
}

Client::Client(const Client& copie):
	nume(copie.nume),
	email(copie.email),
	telefon(copie.telefon) {
}

Client& Client::operator=(const Client& copie) {
	nume = copie.nume;
	email = copie.email;
	telefon = copie.telefon;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Client& client) {
	os << "Nume: " << client.nume << "\n";
	os << "Email: " << client.email << "\n";
	os << "Telefon: " << client.telefon << "\n";
	return os;
}

const std::string& Client::getNume() const {
	return nume;
}
