#ifndef BAR_H
#define BAR_H

#include <vector>
#include <memory>

#include "Product.h"

class Bar {
private:
	static int totalProducts;
	std::vector<std::shared_ptr<Product>> products;

	Bar();
	~Bar();

	Bar(const Bar&) = delete;
	Bar& operator=(const Bar&) = delete;

	static Bar* instance;

public:
	static Bar* getInstance();

	friend std::ostream& operator<<(std::ostream& os, const Bar& bar);

	void display(std::ostream& os) const;
	void addProduct(const std::shared_ptr<Product>& product);
	void applyPromotions();
	void applyMenuPromotions();

	const std::vector<std::shared_ptr<Product>>& getProducts() const;
	static int getTotalProducts();
};

#endif
