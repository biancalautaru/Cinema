#ifndef NONEXISTENTPRODUCT_H
#define NONEXISTENTPRODUCT_H

#include "Exception.h"

class NonexistentProduct : public Exception {
public:
	NonexistentProduct();
	explicit NonexistentProduct(const std::string& message);
};

#endif
