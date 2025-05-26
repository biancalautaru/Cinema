#ifndef PROGRAMSAPTAMANA_H
#define PROGRAMSAPTAMANA_H

#include <iostream>
#include <vector>
#include "ProgramZi.h"

class ProgramSaptamana {
private:
	std::vector<std::pair<std::string, ProgramZi>> saptamana;

public:
	ProgramSaptamana();
	~ProgramSaptamana();

	explicit ProgramSaptamana(const std::vector<std::pair<std::string, ProgramZi>>& saptamana);
	ProgramSaptamana(const ProgramSaptamana& copie);

	ProgramSaptamana& operator=(const ProgramSaptamana& copie);
	friend std::ostream& operator<<(std::ostream& os, const ProgramSaptamana& program);

	void setSaptamana(const std::vector<std::pair<std::string, ProgramZi>>& saptamana_);
	const std::vector<std::pair<std::string, ProgramZi>>& getSaptamana() const;

	ProgramSaptamana adaugaZi(const std::pair<std::string, ProgramZi>& program_zi);
	ProgramSaptamana generare(const std::vector<Film>& filme, const std::vector<Sala>& sali);
};

#endif
