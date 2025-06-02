#ifndef MENU_H
#define MENU_H

#include "Product.h"

/**
 * @enum MenuSize
 * @brief Defines available menu sizes.
 */
enum MenuSize {
	SMALL,
	MEDIUM,
	LARGE,
	SPECIAL
};

/**
 * @class Menu
 * @brief Represents a menu sold at the bar that contains a food item and a drink.
 *
 * The Menu class inherits from Product and adds attributes for a food item's name and weight,
 * a drink item's name and volume and its size.
 */
class Menu : public Product {
private:
	std::string foodName;
	int weight;
	std::string drinkName;
	int volume;
	MenuSize size;

public:
	Menu();

	~Menu() override;

	Menu(const std::string& name, double price, const std::string& foodName, int weight,
	      const std::string& drinkName, int volume, const MenuSize& size);

	Menu(const Menu& copy);

	Menu& operator=(const Menu& copy);

	/**
	 * @brief Prints menu information.
	 *
	 * Calls the Menu::display() function to display the details.
	 *
	 * @param os The output stream to write to.
	 * @param menu The Menu object to print.
	 * @return A reference to the output stream.
	 */
	friend std::ostream& operator<<(std::ostream& os, const Menu& menu);

	/**
	 * @brief Displays the menu's details.
	 *
	 * Prints the menu's size, the food's name and weight, the drink's name and weight
	 * and the whole menu's price.
	 *
	 * @param os The output stream to write to.
	 */
	void display(std::ostream& os) const override;

	/**
	 * @brief Clones the menu item.
	 * @return A pointer to a copy of the menu.
	 */
	std::shared_ptr<Product> clone() const override;

	/**
	 * @brief Applies a discount to the menu.
	 */
	void applyDiscount() override;
};

#endif
