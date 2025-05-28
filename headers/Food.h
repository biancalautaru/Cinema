#ifndef FOOD_H
#define FOOD_H

#include "Product.h"

class Food : public Product {
private:
	int weight;

public:
	Food();
	~Food() override;

	explicit Food(const std::string& name, double price, int weight);
	Food(const Food& copy);

	Food& operator=(const Food& copy);
	friend std::ostream& operator<<(std::ostream& os, const Food& food);

	void display(std::ostream& os) const override;
	std::shared_ptr<Product> clone() const override;
	void applyPromotion() override;

	int getWeight() const;
};

#endif
