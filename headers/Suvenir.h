#ifndef SUVENIR_H
#define SUVENIR_H

#include "Produs.h"
#include <string>

class Suvenir : public Produs {
private:
	std::string nume_film;

public:
	Suvenir();
	~Suvenir() override;

	explicit Suvenir(const std::string& nume, double pret, const std::string& nume_film);
	Suvenir(const Suvenir& copie);

	Suvenir& operator=(const Suvenir& copie);
	friend std::ostream& operator<<(std::ostream& os, const Suvenir& suvenir);

	void afisare(std::ostream& os) const override;
	std::shared_ptr<Produs> clone() override;
	void aplicaPromotie() override;
};

#endif
