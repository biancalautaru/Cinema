#include "../headers/Bar.h"
#include "../headers/Meniu.h"

#include <iostream>

int Bar::totalProduse = 0;

Bar::Bar() {
}

Bar::~Bar() {
}

Bar* Bar::instance = nullptr;

Bar* Bar::getInstance() {
	if (instance == nullptr)
		instance = new Bar();
	return instance;
}

std::ostream& operator<<(std::ostream& os, const Bar& bar) {
	os << "Produse bar (" << Bar::getTotalProduse() << " produse):\n";
	bar.afisare(os);
	return os;
}

void Bar::afisare(std::ostream& os) const {
	for (size_t i = 0; i < produse.size(); i++) {
		os << i + 1 << ". ";
		produse[i]->afisare(os);
	}
}

void Bar::adaugaProdus(const std::shared_ptr<Produs>& produs) {
	produse.push_back(produs);
	totalProduse++;
}

void Bar::aplicaPromotii() {
	for (auto& produs : produse)
		produs->aplicaPromotie();
}

void Bar::aplicaPromotiiMeniuri() {
	for (auto& produs : produse) {
		auto* meniu = dynamic_cast<Meniu*>(produs.get());
		if (meniu != nullptr)
			meniu->aplicaPromotie();
	}
}

const std::vector<std::shared_ptr<Produs>>& Bar::getProduse() const {
	return produse;
}

int Bar::getTotalProduse() {
	return totalProduse;
}
