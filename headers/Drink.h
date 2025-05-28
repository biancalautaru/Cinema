#ifndef DRINK_H
#define DRINK_H

#include "Product.h"

class Drink : public Product {
private:
	int volume;

public:
	Drink();
	~Drink() override;

	Drink(const std::string& name, double price, int volume);
	Drink(const Drink& copy);

	Drink& operator=(const Drink& copy);
	friend std::ostream& operator<<(std::ostream& os, const Drink& drink);

	void display(std::ostream& os) const override;
	std::shared_ptr<Product> clone() const override;
	void applyPromotion() override;

	int getVolume() const;
};

#endif
