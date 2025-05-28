#include "../headers/Bar.h"
#include "../headers/Menu.h"

#include <iostream>

int Bar::totalProducts = 0;

Bar::Bar() {
}

Bar::~Bar() {
}

Bar* Bar::instance = nullptr;

Bar* Bar::getInstance() {
	if (instance == nullptr)
		instance = new Bar();
	return instance;
}

std::ostream& operator<<(std::ostream& os, const Bar& bar) {
	os << "Bar products (" << Bar::getTotalProducts() << " products):\n";
	bar.display(os);
	return os;
}

void Bar::display(std::ostream& os) const {
	for (size_t i = 0; i < products.size(); i++) {
		os << i + 1 << ". ";
		products[i]->display(os);
	}
}

void Bar::addProduct(const std::shared_ptr<Product>& product) {
	products.push_back(product);
	totalProducts++;
}

void Bar::applyPromotions() {
	for (auto& produs : products)
		produs->applyPromotion();
}

void Bar::applyMenuPromotions() {
	for (auto& product : products) {
		auto* menu = dynamic_cast<Menu*>(product.get());
		if (menu != nullptr)
			menu->applyPromotion();
	}
}

const std::vector<std::shared_ptr<Product>>& Bar::getProducts() const {
	return products;
}

int Bar::getTotalProducts() {
	return totalProducts;
}
