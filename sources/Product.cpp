#include "../headers/Product.h"

#include <iomanip>

Product::Product() {
}

Product::~Product() {
}

Product::Product(const std::string& name, double price):
	name(name),
	price(price) {
}

Product::Product(const Product& copy):
	name(copy.name),
	price(copy.price) {
}

Product& Product::operator=(const Product& copy) {
	name = copy.name;
	price = copy.price;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Product& product) {
	os << std::fixed << std::setprecision(2);
	os << product.name << " - " << product.price << " lei\n";
	return os;
}

const std::string& Product::getName() const {
	return name;
}

double Product::getPrice() const {
	return price;
}
