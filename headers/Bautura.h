#ifndef BAUTURA_H
#define BAUTURA_H

#include "Produs.h"

class Bautura : public Produs {
private:
	int volum;

public:
	Bautura();
	~Bautura();

	Bautura(const std::string&nume, float pret, int volum);
	Bautura(const Bautura& copie);

	Bautura& operator=(const Bautura& copie);
	friend std::ostream& operator<<(std::ostream& os, const Bautura& bautura);

	void afisare(std::ostream& os) const override;
	std::shared_ptr<Produs> clone();
	void aplicaPromotie() override;

	void setVolum(int volum_);
	int getVolum() const;
};

#endif
