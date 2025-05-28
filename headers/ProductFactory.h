#ifndef PRODCTFACTORY_H
#define PRODUCTFACTORY_H

#include "Product.h"
#include "Menu.h"

enum ProductType {
	FOOD,
	DRINK,
	MENU,
	SOUVENIR
};

class ProductFactory {
public:
	ProductFactory();

	std::shared_ptr<Product> createProduct(ProductType type, const std::string& name, double price, int quantity);
	std::shared_ptr<Product> createProduct(ProductType type, const std::string& name, double price,
	                                     const std::string& foodName, int weight, const std::string& drinkName,
	                                     int volume, MenuSize size);
	std::shared_ptr<Product> createProduct(ProductType type, const std::string& name, double price,
	                                     const std::string& movieName);
};

#endif
