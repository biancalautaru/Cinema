#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <memory>

/**
 * @class Product
 * @brief Abstract class that represents a product sold at the bar.
 *
 * The Product class contains information about the name of a product and its price.
 * It serves as an interface for all concrete product types.
 */
class Product {
protected:
	std::string name;
	double price;

public:
	Product();

	virtual ~Product();

	Product(const std::string& name, double price);

	Product(const Product& copy);

	Product& operator=(const Product& copy);

	/**
	 * @brief Prints product information.
	 *
	 * Displays the product's name and price.
	 *
	 * @param os The output stream to write to.
	 * @param product The Product object to print.
	 * @return A reference to the output stream.
	 */
	friend std::ostream& operator<<(std::ostream& os, const Product& product);

	/**
	 * @brief Displays the product's details.
	 *
	 * Must be implemented by the derived classes to define how the product is printed.
	 *
	 * @param os The output stream to write to.
	 */
	virtual void display(std::ostream& os) const = 0;

	/**
	 * @brief Creates a copy of the product.
	 *
	 * Is used to implement polymorphic cloning.
	 *
	 * @return A pointer to a new copy of the product.
	 */
	virtual std::shared_ptr<Product> clone() const = 0;

	/**
	 * @brief Applies a discount to the product.
	 *
	 * Must be implemented by the derived classes to apply the price adjustments.
	 */
	virtual void applyDiscount() = 0;

	const std::string& getName() const;

	double getPrice() const;
};

#endif
