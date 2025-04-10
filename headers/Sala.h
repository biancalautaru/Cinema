#ifndef SALA_H
#define SALA_H

#include <iostream>

class Sala {
private:
	int numar;
	int randuri;
	int coloane;

public:
	Sala();
	~Sala();

	Sala(const int numar, const int randuri, const int coloane);
	Sala(const Sala& copie);

	Sala& operator=(const Sala& copie);
	friend std::ostream& operator<<(std::ostream& os, const Sala& sala);

	void setNumar(const int numar_);
	int getNumar() const;
	void setRanduri(const int randuri_);
	int getRanduri() const;
	void setColoane(const int coloane_);
	int getColoane() const;
};

#endif