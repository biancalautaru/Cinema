#ifndef MANCARE_H
#define MANCARE_H

#include "Produs.h"

class Mancare : public Produs {
private:
	int gramaj;

public:
	Mancare();
	~Mancare() override;

	explicit Mancare(const std::string& nume, double pret, int gramaj);
	Mancare(const Mancare& copie);

	Mancare& operator=(const Mancare& copie);
	friend std::ostream& operator<<(std::ostream& os, const Mancare& mancare);

	void afisare(std::ostream& os) const override;
	std::shared_ptr<Produs> clone() const override;
	void aplicaPromotie() override;

	int getGramaj() const override;
};

#endif
