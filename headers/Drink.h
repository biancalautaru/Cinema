#ifndef DRINK_H
#define DRINK_H

#include "Product.h"

/**
 * @class Drink
 * @brief Represents a drink sold at the bar.
 *
 * The Drink class inherits from Product and adds a volume attribute.
 */
class Drink : public Product {
private:
	int volume;

public:
	Drink();

	~Drink() override;

	Drink(const std::string& name, double price, int volume);

	Drink(const Drink& copy);

	Drink& operator=(const Drink& copy);

	/**
	 * @brief Prints drink information.
	 *
	 * Calls the Drink::display() function to display the details.
	 *
	 * @param os The output stream to write to.
	 * @param drink The Drink object to print.
	 * @return A reference to the output stream.
	 */
	friend std::ostream& operator<<(std::ostream& os, const Drink& drink);

	/**
	 * @brief Displays the drink item's details.
	 *
	 * Prints the drink's name, volume and price.
	 *
	 * @param os The output stream to write to.
	 */
	void display(std::ostream& os) const override;

	/**
	 * @brief Clones the drink item.
	 * @return A pointer to a copy of the drink.
	 */
	std::shared_ptr<Product> clone() const override;

	/**
	 * @brief Applies a discount to the drink.
	 */
	void applyDiscount() override;

	int getVolume() const;
};

#endif
