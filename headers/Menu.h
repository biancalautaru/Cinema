#ifndef MENU_H
#define MENU_H

#include "Product.h"

enum MenuSize {
	SMALL,
	MEDIUM,
	LARGE,
	SPECIAL
};

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
	friend std::ostream& operator<<(std::ostream& os, const Menu& menu);

	void display(std::ostream& os) const override;
	std::shared_ptr<Product> clone() const override;
	void applyPromotion() override;
};

#endif
