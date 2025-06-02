#ifndef BAR_H
#define BAR_H

#include <vector>
#include <memory>

#include "Product.h"

/**
 * @class Bar
 * @brief Singleton class that represents the bar inside the cinema.
 *
 * The Bar class stores and manages a collection of products (food, drinks, menus and
 * souvenirs) and follows the Singleton design pattern, ensuring only one instance exists.
 */
class Bar {
private:
	static int totalProducts;
	std::vector<std::shared_ptr<Product>> products;
	static std::shared_ptr<Bar> instance; ///< Singleton instance of the bar.

public:
	Bar();

	~Bar();

	/**
	 * @brief Deleted copy constructor to prevent multiple instances.
	 */
	Bar(const Bar&) = delete;

	/**
	 * @brief Deleted assignment operator to enforce Singleton.
	 */
	Bar& operator=(const Bar&) = delete;

	/**
	 * @brief Retrieves the Singleton instance of the bar.
	 * @return A pointer to the bar instance.
	 */
	static std::shared_ptr<Bar> getInstance();

	/**
	 * @brief Prints the products available at the bar.
	 *
	 * Calls the Bar::display() method to display the list of products.
	 *
	 * @param os The output stream to write to.
	 * @param bar The Bar object to print.
	 * @return A reference to the output stream.
	 */
	friend std::ostream& operator<<(std::ostream& os, const Bar& bar);

	/**
	 * @brief Displays the products available at the bar.
	 *
	 * Prints the list of products available at the bar.
	 * 
	 * @param os The output stream to write to.
	 */
	void display(std::ostream& os) const;

	/**
	 * @brief Adds a product to the bar.
	 * @param product The product to be added to the list.
	 */
	void addProduct(const std::shared_ptr<Product>& product);

	/**
	 * @brief Applies discounts to all bar products.
	 *
	 * Calls the method to apply discounts for all products in the list according to
	 * the rules for each product type.
	 */
	void applyDiscounts();

	/**
	 * @brief Applies discounts to menus.
	 *
	 * Calls the Menu::applyDiscount() method for menus in the list.
	 */
	void applyMenuDiscounts();

	const std::vector<std::shared_ptr<Product>>& getProducts() const;

	/**
	 * @brief Gets the number of products in the bar.
	 * @return The total number of products.
	 */
	static int getTotalProducts();
};

#endif
