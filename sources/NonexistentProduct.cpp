#include "../headers/NonexistentProduct.h"

NonexistentProduct::NonexistentProduct():
	Exception("Enter numbers corresponding to existing products: ") {
}

NonexistentProduct::NonexistentProduct(const std::string& message):
	Exception(message) {
}
