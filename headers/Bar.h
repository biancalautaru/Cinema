#ifndef BAR_H
#define BAR_H

#include <vector>
#include <memory>

#include "Produs.h"

class Bar {
private:
	static int totalProduse;
	std::vector<std::shared_ptr<Produs>> produse;

public:
	Bar();
	~Bar();

	explicit Bar(const std::vector<std::shared_ptr<Produs>>& produse);
	Bar(const Bar& copie);

	Bar& operator=(const Bar& copie);
	friend std::ostream& operator<<(std::ostream& os, const Bar& bar);

	void afisare(std::ostream& os) const;
	void adaugaProdus(const std::shared_ptr<Produs>& produs);
	void aplicaPromotii();
	void aplicaPromotiiMeniuri();

	const std::vector<std::shared_ptr<Produs>>& getProduse() const;
	static int getTotalProduse();
};

#endif
