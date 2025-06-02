#include "../headers/Food.h"

#include <iomanip>

Food::Food() {
}

Food::~Food() {
}

Food::Food(const std::string& name, double price, int weight):
	Product(name, price),
	weight(weight) {
}

Food::Food(const Food& copy):
	Product(copy),
	weight(copy.weight) {
}

Food& Food::operator=(const Food& copy) {
	Product::operator=(copy);
	weight = copy.weight;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Food& food) {
	food.display(os);
	return os;
}

void Food::display(std::ostream& os) const {
	os << std::fixed << std::setprecision(2);
	os << name << " (" << this->weight << "g) - " << price << " lei\n";
}

std::shared_ptr<Product> Food::clone() const {
	return std::make_shared<Food>(*this);
}

void Food::applyDiscount() {
	if (price > 20)
		price *= 0.9;
}

int Food::getWeight() const {
	return weight;
}
