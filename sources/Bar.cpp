#include "../headers/Bar.h"
#include "../headers/Menu.h"

#include <iostream>

int Bar::totalProducts = 0;

Bar::Bar() {
}

Bar::~Bar() {
}

std::shared_ptr<Bar> Bar::instance = nullptr;

std::shared_ptr<Bar> Bar::getInstance() {
	if (instance == nullptr)
		instance = std::make_shared<Bar>();
	return instance;
}

std::ostream& operator<<(std::ostream& os, const Bar& bar) {
	bar.display(os);
	return os;
}

void Bar::display(std::ostream& os) const {
	os << "Bar products (" << Bar::getTotalProducts() << " products):\n";
	for (size_t i = 0; i < products.size(); i++) {
		os << i + 1 << ". ";
		products[i]->display(os);
	}
}

void Bar::addProduct(const std::shared_ptr<Product>& product) {
	products.push_back(product);
	totalProducts++;
}

void Bar::applyDiscounts() {
	for (auto& product : products)
		product->applyDiscount();
}

void Bar::applyMenuDiscounts() {
	for (auto& product : products)
		if (std::dynamic_pointer_cast<std::shared_ptr<Menu>>(product) != nullptr)
			product->applyDiscount();
}

const std::vector<std::shared_ptr<Product>>& Bar::getProducts() const {
	return products;
}

int Bar::getTotalProducts() {
	return totalProducts;
}
