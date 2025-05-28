#ifndef OFFER_H
#define OFFER_H

#include <iostream>
#include <string>

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

	void setName(const std::string& name_);
	void setTickets(int tickets_);
	void setPercentage(int percentage_);

	void display(std::ostream& os) const;
};

#endif
