#ifndef MENIU_H
#define MENIU_H

#include "Produs.h"

enum MarimeMeniu {
	MIC,
	MEDIU,
	MARE,
	SPECIAL
};

class Meniu : public Produs {
private:
	std::string nume_mancare;
	int gramaj;
	std::string nume_bautura;
	int volum;
	MarimeMeniu marime;

public:
	Meniu();
	~Meniu() override;

	Meniu(const std::string& nume, double pret, const std::string& nume_mancare, int gramaj,
	      const std::string& nume_bautura, int volum, const MarimeMeniu& marime);
	Meniu(const Meniu& copie);

	Meniu& operator=(const Meniu& copie);
	friend std::ostream& operator<<(std::ostream& os, const Meniu& meniu);

	void afisare(std::ostream& os) const override;
	std::shared_ptr<Produs> clone() const override;
	void aplicaPromotie() override;
};

#endif
