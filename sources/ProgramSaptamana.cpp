#include "../headers/ProgramSaptamana.h"

ProgramSaptamana::ProgramSaptamana() {
}

ProgramSaptamana::~ProgramSaptamana() {
}

ProgramSaptamana::ProgramSaptamana(const std::vector<std::pair<std::string, ProgramZi>>& saptamana):
	saptamana(saptamana) {
}

ProgramSaptamana::ProgramSaptamana(const ProgramSaptamana& copie):
	saptamana(copie.saptamana) {
}

ProgramSaptamana& ProgramSaptamana::operator=(const ProgramSaptamana& copie) {
	saptamana = copie.saptamana;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const ProgramSaptamana& program) {
	for (size_t i = 0; i < program.saptamana.size(); i++)
		os << "- " << program.saptamana[i].first << " -\n" << program.saptamana[i].second << "\n";
	return os;
}

void ProgramSaptamana::setSaptamana(const std::vector<std::pair<std::string, ProgramZi>>& saptamana_) {
	saptamana = saptamana_;
}

const std::vector<std::pair<std::string, ProgramZi>>& ProgramSaptamana::getSaptamana() const {
	return saptamana;
}

ProgramSaptamana ProgramSaptamana::adaugaZi(const std::pair<std::string, ProgramZi>& program_zi) {
	saptamana.push_back(program_zi);
	ProgramSaptamana program;
	program.setSaptamana(saptamana);
	return program;
}

ProgramSaptamana ProgramSaptamana::generare(const std::vector<Film>& filme, const std::vector<Sala>& sali) {
	ProgramSaptamana program;
	for (int i = 0; i < 7; i++) {
		std::string zi;
		switch (i) {
		case 0: zi = "Luni";
			break;
		case 1: zi = "Marti";
			break;
		case 2: zi = "Miercuri";
			break;
		case 3: zi = "Joi";
			break;
		case 4: zi = "Vineri";
			break;
		case 5: zi = "Sambata";
			break;
		default: zi = "Duminica";
		}
		ProgramZi program_zi;
		program_zi = program_zi.generare(filme, sali);
		std::vector<Proiectie> proiectii = program_zi.getZi();
		for (size_t j = 0; j < proiectii.size(); j++)
			proiectii[j].setZi(zi);
		program_zi.setZi(proiectii);
		program.adaugaZi({zi, program_zi});
	}
	return program;
}
