#include "../headers/ProductFactory.h"

#include "../headers/Food.h"
#include "../headers/Drink.h"
#include "../headers/Menu.h"
#include "../headers/Souvenir.h"

ProductFactory::ProductFactory() {
}

std::shared_ptr<Product>
ProductFactory::createProduct(ProductType type, const std::string& name, double price, int quantity) {
	if (type == FOOD)
		return std::make_shared<Food>(name, price, quantity);
	if (type == DRINK)
		return std::make_shared<Drink>(name, price, quantity);
	return nullptr;
}

std::shared_ptr<Product> ProductFactory::createProduct(ProductType type, const std::string& name, double price,
                                                    const std::string& foodName, int weight,
                                                    const std::string& drinkName, int volume, MenuSize size) {
	if (type == MENU)
		return std::make_shared<Menu>(name, price, foodName, weight, drinkName, volume, size);
	return nullptr;
}

std::shared_ptr<Product> ProductFactory::createProduct(ProductType type, const std::string& name, double price,
                                                    const std::string& movieName) {
	if (type == SOUVENIR)
		return std::make_shared<Souvenir>(name, price, movieName);
	return nullptr;
}
