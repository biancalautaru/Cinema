#include "../headers/Offer.h"

Offer::Offer() {
}

Offer::~Offer() {
}

Offer::Offer(const std::string& name, int tickets, int percentage):
	name(name),
	tickets(tickets),
	percentage(percentage) {
}

Offer::Offer(const Offer& copy):
	name(copy.name),
	tickets(copy.tickets),
	percentage(copy.percentage) {
}

Offer& Offer::operator=(const Offer& copy) {
	name = copy.name;
	tickets = copy.tickets;
	percentage = copy.percentage;
	return *this;
}

void Offer::display(std::ostream& os) const {
	os << name << " - " << percentage << "% off";
	if (tickets == -1)
		os << "\n";
	else
		os << " - " << tickets << " tickets\n";
}

void Offer::setName(const std::string& name_) {
	name = name_;
}

void Offer::setTickets(int tickets_) {
	tickets = tickets_;
}

void Offer::setPercentage(int percentage_) {
	percentage = percentage_;
}