#ifndef FOOD_H
#define FOOD_H

#include "Product.h"

/**
 * @class Food
 * @brief Represents a food item sold at the bar.
 *
 * The Food class inherits from Product and adds a weight attribute.
 */
class Food : public Product {
private:
	int weight;

public:
	Food();

	~Food() override;

	explicit Food(const std::string& name, double price, int weight);

	Food(const Food& copy);

	Food& operator=(const Food& copy);

	/**
	 * @brief Prints food information.
	 *
	 * Calls the Food::display() function to display the details.
	 *
	 * @param os The output stream to write to.
	 * @param food The Food object to print.
	 * @return A reference to the output stream.
	 */
	friend std::ostream& operator<<(std::ostream& os, const Food& food);

	/**
	 * @brief Displays the food item's details.
	 *
	 * Prints the food's name, weight and price.
	 *
	 * @param os The output stream to write to.
	 */
	void display(std::ostream& os) const override;

	/**
	 * @brief Clones the food item.
	 * @return A pointer to a copy of the food.
	 */
	std::shared_ptr<Product> clone() const override;

	/**
	 * @brief Applies a discount to the food item.
	 */
	void applyDiscount() override;

	int getWeight() const;
};

#endif
