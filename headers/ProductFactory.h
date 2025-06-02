#ifndef PRODUCTFACTORY_H
#define PRODUCTFACTORY_H

#include "Product.h"
#include "Menu.h"

/**
 * @enum ProductType
 * Defines product types.
 */
enum ProductType {
	FOOD,
	DRINK,
	MENU,
	SOUVENIR
};

/**
 * @class ProductFactory
 * @brief Factory class for creating Product objects.
 *
 * The ProductFactory class implements the Factory design pattern to simplify the creation
 * of products without exposing the instantiation logic to the user.
 */
class ProductFactory {
public:
	ProductFactory();

	/**
	 * @brief Creates a food or drink item.
	 *
	 * Depending on the type of the product (FOOD or DRINK), this method creates an object
	 * with the given name, price and weight or volume.
	 *
	 * @param type The type of product to create (FOOD or DRINK).
	 * @param name The product's name.
	 * @param price The product's price.
	 * @param quantity The weight (for FOOD) or volume (for DRINK).
	 * @return A pointer to the created product.
	 */
	std::shared_ptr<Product> createProduct(ProductType type, const std::string& name, double price, int quantity);

	/**
	 * @brief Creates a menu.
	 *
	 * Creates a menu that includes food and drink details along with the menu size.
	 *
	 * @param type Must be MENU.
	 * @param name The menu's name.
	 * @param price The menu's price.
	 * @param foodName The food item's name.
	 * @param weight The food item's weight.
	 * @param drinkName The drink's name.
	 * @param volume The dink's volume.
	 * @param size The menu's size.
	 * @return A pointer to the created product.
	 */
	std::shared_ptr<Product> createProduct(ProductType type, const std::string& name, double price,
	                                     const std::string& foodName, int weight, const std::string& drinkName,
	                                     int volume, MenuSize size);

	/**
	 * @brief Creates a souvenir.
	 *
	 *
	 *
	 * @param type Must be SOUVENIR.
	 * @param name The souvenir's name.
	 * @param price The souvenir's price.
	 * @param movieName The name of the movie the souvenir is related to.
	 * @return A pointer to the created product.
	 */
	std::shared_ptr<Product> createProduct(ProductType type, const std::string& name, double price,
	                                       const std::string& movieName);
};

#endif
