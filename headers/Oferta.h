#ifndef OFERTA_H
#define OFERTA_H

#include <iostream>
#include <ostream>
#include <string>

class Oferta {
private:
	std::string nume;
	int bilete;
	int procent;

public:
	Oferta();
	~Oferta();

	Oferta(const std::string& nume, int bilete, int procent);
	Oferta(const Oferta& copie);

	Oferta& operator=(const Oferta& copie);

	void setNume(const std::string& nume_);
	void setBilete(int bilete_);
	void setProcent(int procent_);

	void afisare(std::ostream& os) const;
};

#endif
