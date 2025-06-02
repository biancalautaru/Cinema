#ifndef OFFER_H
#define OFFER_H

#include <iostream>
#include <string>

/**
 * @class Offer
 * @brief Represents a promotional offer based on ticket purchases.
 *
 * The Offer class stores the name of the offer, the number of tickets required and the
 * percentage of the applied discount.
 */
class Offer {
private:
	std::string name;
	int tickets;
	int percentage;

public:
	Offer();

	~Offer();

	Offer(const std::string& name, int tickets, int percentage);

	Offer(const Offer& copy);

	Offer& operator=(const Offer& copy);

	/**
	 * @brief Displays the offer details.
	 *
	 * Prints the name, percentage and the number of required tickets (if any).
	 *
	 * @param os The output stream to write to.
	 */
	void display(std::ostream& os) const;

	void setName(const std::string& name_);

	void setTickets(int tickets_);

	void setPercentage(int percentage_);
};

#endif
