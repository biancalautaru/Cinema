#include "../headers/Drink.h"

#include <iomanip>

Drink::Drink() {
}

Drink::~Drink() {
}

Drink::Drink(const std::string& name, double price, int volume):
	Product(name, price),
	volume(volume) {
}

Drink::Drink(const Drink& copy):
	Product(copy),
	volume(copy.volume) {
}

Drink& Drink::operator=(const Drink& copy) {
	Product::operator=(copy);
	volume = copy.volume;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Drink& drink) {
	drink.display(os);
	return os;
}

void Drink::display(std::ostream& os) const {
	os << std::fixed << std::setprecision(2);
	os << name << " (" << volume << "ml) - " << price << " lei\n";
}

std::shared_ptr<Product> Drink::clone() const {
	return std::make_shared<Drink>(*this);
}

void Drink::applyDiscount() {
	if (price > 10)
		price *= 0.9;
}

int Drink::getVolume() const {
	return volume;
}
