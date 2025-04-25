#include "../headers/ProgramZi.h"

#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>

void ProgramZi::sortareProiectii() {
	std::sort(zi.begin(), zi.end(), [](const Proiectie& p1, const Proiectie& p2) {
		return p1.getOra() < p2.getOra();
	});
}

std::string ProgramZi::oraString(const int& ora) {
	std::string ora_st(5, ' ');
	ora_st[0] = '0' + ora / 60 / 10;
	ora_st[1] = '0' + ora / 60 % 10;
	ora_st[2] = ':';
	ora_st[3] = '0' + ora % 60 / 10;
	ora_st[4] = '0' + ora % 60 % 10;
	return ora_st;
}

int ProgramZi::urmatoareaOra(const int& ora) {
	int min = ora % 60;
	if (min == 0 || min == 15 || min == 30 || min == 45)
		return ora + 30;
	if (min < 15)
		return ora + 15 - min + 30;
	if (min < 30)
		return ora + 30 - min + 30;
	if (min < 45)
		return ora + 45 - min + 30;
	return ora + 60 - min + 30;
}

ProgramZi::ProgramZi() {};

ProgramZi::~ProgramZi() {};

ProgramZi::ProgramZi(const std::vector<Proiectie>& zi):
	zi(zi) {
	sortareProiectii();
}

ProgramZi::ProgramZi(const ProgramZi& copie):
	zi(copie.zi)
{}

ProgramZi& ProgramZi::operator=(const ProgramZi& copie) {
	zi = copie.zi;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const ProgramZi& program) {
	for (size_t i = 0; i < program.zi.size(); i++) {
		const Proiectie& proiectie = program.zi[i];
		os << "Ora " << proiectie.getOra() << " | ";
		os << "Sala " << proiectie.getSala().getNumar() << " | ";
		os << proiectie.getFilm().getNume() << " | ";
		const int& locuri = proiectie.locuriRamase();
		if (locuri == 1)
			os << locuri << " loc ramas";
		else
			if (locuri % 100 >= 20)
				os << locuri << " de locuri ramase";
			else
				os << locuri << " locuri ramase";
		os << "\n";
	}
	return os;
}

void ProgramZi::setZi(const std::vector<Proiectie>& zi_) {
	zi = zi_;
	sortareProiectii();
}

const std::vector<Proiectie>& ProgramZi::getZi() const {
	return zi;
}

void ProgramZi::adaugaProiectie(const Proiectie& proiectie) {
	zi.push_back(proiectie);
	sortareProiectii();
}

ProgramZi ProgramZi::generare(const std::vector<Film>& filme_aux, const std::vector<Sala>& sali_aux) {
	std::vector<Film> filme = filme_aux;
	std::vector<Sala> sali = sali_aux;
	long long seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(filme.begin(), filme.end(), std::default_random_engine(seed));
	std::shuffle(sali.begin(), sali.end(), std::default_random_engine(seed));

	std::vector<int> filmeAG, filmeIM, filme3D, filmeRest;
	for (size_t i = 0; i < filme.size(); i++)
		if (filme[i].getRating() == "AG")
			filmeAG.push_back(i);
		else
			if (filme[i].getRating() == "IM-18")
				filmeIM.push_back(i);
			else
				if (filme[i].getFormat() == "3D")
					filme3D.push_back(i);
				else
					filmeRest.push_back(i);

	ProgramZi program;
	std::vector<int> sali_ore;

	int start = 720;
	for (size_t i = 0; i < sali.size(); i++)
		sali_ore.push_back(start);

	for (size_t i = 0; i < filmeAG.size(); i++)
		for (size_t j = 0; j < sali_ore.size(); j++) {
			int final = urmatoareaOra(sali_ore[j] + filme[filmeAG[i]].getDurata());
			if (final <= 960) {
				Proiectie proiectie(filme[filmeAG[i]], "", oraString(sali_ore[j]), sali[j], {});
				sali_ore[j] = final;
				program.adaugaProiectie(proiectie);
				break;
			}
		}

	for (size_t i = 0; i < filme3D.size(); i++)
		for (size_t j = 0; j < sali_ore.size(); j++) {
			int final = urmatoareaOra(sali_ore[j] + filme[filme3D[i]].getDurata());
			if (final <= 1410) {
				Proiectie proiectie(filme[filme3D[i]], "", oraString(sali_ore[j]), sali[j], {});
				sali_ore[j] = final;
				program.adaugaProiectie(proiectie);
				break;
			}
		}

	start = 960;
	for (size_t i = 0; i < sali.size(); i++)
		if (sali_ore[i] < start)
			sali_ore[i] = start;

	for (size_t i = 0; i < filmeRest.size(); i++)
		for (size_t j = 0; j < sali_ore.size(); j++) {
			int final = urmatoareaOra(sali_ore[j] + filme[filmeRest[i]].getDurata());
			if (final <= 1410) {
				Proiectie proiectie(filme[filmeRest[i]], "", oraString(sali_ore[j]), sali[j], {});
				sali_ore[j] = final;
				program.adaugaProiectie(proiectie);
				break;
			}
		}

	start = 1200;
	for (size_t i = 0; i < sali.size(); i++)
		if (sali_ore[i] < start)
			sali_ore[i] = start;

	for (size_t i = 0; i < filmeIM.size(); i++)
		for (size_t j = 0; j < sali_ore.size(); j++) {
			int final = urmatoareaOra(sali_ore[j] + filme[filmeIM[i]].getDurata());
			if (final <= 1470) {
				Proiectie proiectie(filme[filmeIM[i]], "", oraString(sali_ore[j]), sali[j], {});
				sali_ore[j] = final;
				program.adaugaProiectie(proiectie);
				break;
			}
		}

	return program;
}