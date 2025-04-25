#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
private:
	std::string	nume;
	std::string	email;
	std::string	telefon;

public:
	Client();
	~Client();

	Client(const std::string& nume, const std::string& email, const std::string& telefon);
	Client(const Client& copie);

	Client& operator=(const Client& copie);
	friend std::ostream& operator<<(std::ostream& os, const Client& client);

	const std::string& getNume() const;
};

#endif