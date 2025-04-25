#ifndef MENIU_H
#define MENIU_H

#include "Produs.h"
#include "Mancare.h"
#include "Bautura.h"

enum MarimeMeniu {
	MIC,
	MEDIU,
	MARE,
	SPECIAL
};

class Meniu : public Produs {
private:
	std::shared_ptr<Mancare> mancare;
	std::shared_ptr<Bautura> bautura;
	MarimeMeniu marime;

public:
	Meniu();
	~Meniu() override;

	Meniu(const std::string& nume, double pret, const std::shared_ptr<Produs>& mancare, const std::shared_ptr<Produs>& bautura, const MarimeMeniu& marime);
	Meniu(const Meniu& copie);

	Meniu& operator=(const Meniu& copie);
	friend std::ostream& operator<<(std::ostream& os, const Meniu& meniu);

	void afisare(std::ostream& os) const override;
	std::shared_ptr<Produs> clone() override;
	void aplicaPromotie() override;
};

#endif