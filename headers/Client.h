#ifndef CLIENT_H
#define CLIENT_H

#include <string>

/**
 * @class Client
 * @brief Represents a client of the movie theater.
 *
 * The Client class contains the name, email and phone number of a person.
 */
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

	/**
	 * @brief Prints information about a client.
	 *
	 * Displays the client's name, email and phone number.
	 *
	 * @param os The output stream to write to.
	 * @param client The Client object to print.
	 * @return A reference to the output stream.
	 */
	friend std::ostream& operator<<(std::ostream& os, const Client& client);
};

#endif
