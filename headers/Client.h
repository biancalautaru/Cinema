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

	void setNume(const std::string& nume_);
	const std::string& getNume() const;
	void setEmail(const std::string& email_);
	const std::string& getEmail() const;
	void setTelefon(const std::string& telefon_);
	const std::string& getTelefon() const;
};

#endif