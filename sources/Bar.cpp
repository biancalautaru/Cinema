#include "../headers/Bar.h"
#include "../headers/Meniu.h"

#include <iostream>

int Bar::totalProduse = 0;

Bar::Bar() {};

Bar::~Bar() {}

Bar::Bar(const std::vector<std::shared_ptr<Produs>>& produse):
	produse(produse)
{};

Bar::Bar(const Bar& copie) {
	for (auto produs: copie.produse)
		produse.push_back(produs->clone());
}

Bar& Bar::operator=(const Bar& copie) {
	Bar temp(copie);
	std::swap(*this, temp);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bar& bar) {
	bar.afisare(os);
	return os;
}

void Bar::afisare(std::ostream& os) const {
	os << "Produse bar:\n";
	for (size_t i = 0; i < produse.size(); i++) {
		os << i + 1 << ". ";
		produse[i]->afisare(os);
	}
}

void Bar::adaugaProdus(std::shared_ptr<Produs> produs) {
	produse.push_back(produs);
	totalProduse++;
}

void Bar::aplicaPromotii() {
	for (auto produs : produse)
		produs->aplicaPromotie();
}

void Bar::aplicaPromotiiMeniuri() {
	for (auto& produs : produse) {
		auto* meniu = dynamic_cast<Meniu*>(produs.get());
		if (meniu != nullptr)
			meniu->aplicaPromotie();
	}
}

// const std::vector<std::shared_ptr<Produs>>& Bar::getProduse() const {
// 	return produse;
// }
//
// int Bar::getTotalProduse() const {
// 	return totalProduse;
// }