#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
private:
	std::string name;
	std::string email;
	std::string phone;

public:
	Client();
	~Client();

	Client(const std::string& name, const std::string& email, const std::string& phone);
	Client(const Client& copy);

	Client& operator=(const Client& copy);
	friend std::ostream& operator<<(std::ostream& os, const Client& client);

	const std::string& getName() const;
};

#endif
