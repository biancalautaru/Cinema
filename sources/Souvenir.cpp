#include "../headers/Souvenir.h"

#include <iomanip>

Souvenir::Souvenir() {
}

Souvenir::~Souvenir() {
}

Souvenir::Souvenir(const std::string& name, double price, const std::string& movieName):
	Product(name, price),
	movieName(movieName) {
}

Souvenir::Souvenir(const Souvenir& copy):
	Product(copy),
	movieName(copy.movieName) {
}

Souvenir& Souvenir::operator=(const Souvenir& copy) {
	Product::operator=(copy);
	movieName = copy.movieName;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Souvenir& Souvenir) {
	Souvenir.display(os);
	return os;
}

void Souvenir::display(std::ostream& os) const {
	os << std::fixed << std::setprecision(2);
	os << this->movieName << " Movie " << name << " - " << price << " lei\n";
}

std::shared_ptr<Product> Souvenir::clone() const {
	return std::make_shared<Souvenir>(*this);
}

void Souvenir::applyPromotion() {
	if (price > 50)
		price *= 0.9;
}
