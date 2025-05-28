#include "../headers/Client.h"

#include <iostream>

Client::Client() {
}

Client::~Client() {
}

Client::Client(const std::string& name, const std::string& email, const std::string& phone):
	name(name),
	email(email),
	phone(phone) {
}

Client::Client(const Client& copy):
	name(copy.name),
	email(copy.email),
	phone(copy.phone) {
}

Client& Client::operator=(const Client& copy) {
	name = copy.name;
	email = copy.email;
	phone = copy.phone;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Client& client) {
	os << "Name: " << client.name << "\n";
	os << "Email: " << client.email << "\n";
	os << "Phone: " << client.phone << "\n";
	return os;
}

const std::string& Client::getName() const {
	return name;
}
