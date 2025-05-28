#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <memory>

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
	friend std::ostream& operator<<(std::ostream& os, const Product& product);

	virtual void display(std::ostream& os) const = 0;
	virtual std::shared_ptr<Product> clone() const = 0;
	virtual void applyPromotion() = 0;

	const std::string& getName() const;
	double getPrice() const;
};

#endif
