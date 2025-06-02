#ifndef SOUVENIR_H
#define SOUVENIR_H

#include "Product.h"
#include <string>

/**
 * @class Souvenir
 * @brief Represents a drink sold at the bar.
 *
 * The Souvenir class inherits from Product and adds a movie name attribute.
 */
class Souvenir : public Product {
private:
	std::string movieName;

public:
	Souvenir();

	~Souvenir() override;

	explicit Souvenir(const std::string& name, double price, const std::string& movieName);

	Souvenir(const Souvenir& copy);

	Souvenir& operator=(const Souvenir& copy);

	/**
	 * @brief Prints souvenir information.
	 *
	 * Calls the Souvenir::display() function to display the details.
	 *
	 * @param os The output stream to write to.
	 * @param souvenir The Souvenir object to print.
	 * @return A reference to the output stream.
	 */
	friend std::ostream& operator<<(std::ostream& os, const Souvenir& souvenir);

	/**
	 * @brief Displays the souvenir's details.
	 *
	 * Prints the souvenir's name, the name of the movie it's related to and the price.
	 *
	 * @param os The output stream to write to.
	 */
	void display(std::ostream& os) const override;

	/**
	 * @brief Clones the souvenir.
	 * @return A pointer to a copy of the souvenir.
	 */
	std::shared_ptr<Product> clone() const override;

	/**
	 * @brief Applies a discount to the souvenir.
	 */
	void applyDiscount() override;
};

#endif
