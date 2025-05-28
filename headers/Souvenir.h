#ifndef SOUVENIR_H
#define SOUVENIR_H

#include "Product.h"
#include <string>

class Souvenir : public Product {
private:
	std::string movieName;

public:
	Souvenir();
	~Souvenir() override;

	explicit Souvenir(const std::string& name, double price, const std::string& movieName);
	Souvenir(const Souvenir& copy);

	Souvenir& operator=(const Souvenir& cpopy);
	friend std::ostream& operator<<(std::ostream& os, const Souvenir& souvenir);

	void display(std::ostream& os) const override;
	std::shared_ptr<Product> clone() const override;
	void applyPromotion() override;
};

#endif
