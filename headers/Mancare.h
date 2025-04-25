#ifndef MANCARE_H
#define MANCARE_H

#include "Produs.h"

class Mancare : public Produs {
private:
	int gramaj;

public:
	Mancare();
	~Mancare();

	explicit Mancare(const std::string& nume, float pret, int gramaj);
	Mancare(const Mancare& copie);

	Mancare& operator=(const Mancare& copie);
	friend std::ostream& operator<<(std::ostream& os, const Mancare& mancare);

	void afisare(std::ostream& os) const override;
	std::shared_ptr<Produs> clone();
	void aplicaPromotie() override;

	void setGramaj(int gramaj_);
	int getGramaj() const;
};

#endif
