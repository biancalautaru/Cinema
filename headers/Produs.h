#ifndef PRODUS_H
#define PRODUS_H

#include <string>
#include <memory>

class Produs {
protected:
	static int totalProduse;
	std::string nume;
	float pret;

public:
	Produs();
	virtual ~Produs();

	Produs(const std::string& nume, float pret);
	Produs(const Produs& copie);

	Produs& operator=(const Produs& copie);
	friend std::ostream& operator<<(std::ostream& os, const Produs& produs);

	virtual void afisare(std::ostream& os) const = 0;
	virtual std::shared_ptr<Produs> clone() = 0;
	virtual void aplicaPromotie() = 0;

	void setNume(const std::string& nume_);
	const std::string& getNume() const;
	void setPret(float pret_);
	float getPret() const;
};

#endif