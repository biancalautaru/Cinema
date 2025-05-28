#include "../headers/Menu.h"

#include <iomanip>

Menu::Menu() {
};

Menu::~Menu() {
}

Menu::Menu(const std::string& name, double price, const std::string& foodName, int gramaj,
             const std::string& drinkName, int volum, const MenuSize& size):
	Product(name, price),
	foodName(foodName),
	weight(gramaj),
	drinkName(drinkName),
	volume(volum),
	size(size) {
}

Menu::Menu(const Menu& copy):
	Product::Product(copy),
	foodName(copy.foodName),
	weight(copy.weight),
	drinkName(copy.drinkName),
	volume(copy.volume),
	size(copy.size) {
}

Menu& Menu::operator=(const Menu& copy) {
	if (this != &copy) {
		Product::operator=(copy);
		foodName = copy.foodName;
		weight = copy.weight;
		drinkName = copy.drinkName;
		volume = copy.volume;
		size = copy.size;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Menu& menu) {
	menu.display(os);
	return os;
}

void Menu::display(std::ostream& os) const {
	os << std::fixed << std::setprecision(2);
	switch (size) {
	case SMALL:
		os << "Small Menu: ";
		break;
	case MEDIUM:
		os << "Medium Menu: ";
		break;
	case LARGE:
		os << "Large Menu: ";
		break;
	case SPECIAL:
		os << "Special Menu: ";
	}
	os << foodName << " (" << weight << "g), ";
	os << drinkName << " (" << volume << "ml) - ";
	os << price << " lei\n";
}

std::shared_ptr<Product> Menu::clone() const {
	return std::make_shared<Menu>(*this);
}

void Menu::applyPromotion() {
	if (price > 27)
		price *= 0.9;
}
