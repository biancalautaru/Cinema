#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <vector>
#include <set>

class Film {
private:
	std::string nume;
	std::vector<std::string> gen;
	int durata;
	int an;
	std::string regizor;
	std::string rating;
	std::string format;
	float pret;

public:
	Film() {};

	~Film() {};

	Film(const std::string &nume, const std::vector<std::string> &gen, const int durata, const int an, const std::string &regizor, const std::string &rating, const std::string &format, const float pret)
		: nume(nume), gen(gen), durata(durata), an(an), regizor(regizor), rating(rating), format(format), pret(pret) {}

	Film(const Film &copie)
		: nume(copie.nume), gen(copie.gen), durata(copie.durata), an(copie.an), regizor(copie.regizor), rating(copie.rating), format(copie.format), pret(copie.pret) {}

	Film &operator=(const Film &copie) {
		nume = copie.nume;
		gen = copie.gen;
		durata = copie.durata;
		an = copie.an;
		regizor = copie.regizor;
		rating = copie.rating;
		format = copie.format;
		pret = copie.pret;
		return *this;
	}

	friend std::ostream &operator<<(std::ostream &os, const Film &film) {
		os << "Nume: " << film.nume << "\n";
		os << "Gen: ";
		for (size_t i = 0; i < film.gen.size(); i++)
			if (i != film.gen.size() - 1)
				os << film.gen[i] << ", ";
			else
				os << film.gen[i] << "\n";
		os << "Durata: " << film.durata << " minute\n";
		os << "An lansare: " << film.an << "\n";
		os << "Regizor: " << film.regizor << "\n";
		os << "Rating: " << film.rating << "\n";
		os << "Format: " << film.format << "\n";
		os << "Pret normal: " << film.pret << " lei, Pret elevi: " << film.pretElevi() << " lei\n";
		return os;
	}

	void setNume(const std::string &nume_) {
		nume = nume_;
	}

	const std::string &getNume() const {
		return nume;
	}

	void setGen(const std::vector<std::string> &gen_) {
		gen = gen_;
	}

	const std::vector<std::string> &getGen() const {
		return gen;
	}

	void setDurata(const int durata_) {
		durata = durata_;
	}

	int getDurata() const {
		return durata;
	}

	void setAn(const int an_) {
		an = an_;
	}

	int getAn() const {
		return an;
	}

	void setRegizor(const std::string &regizor_) {
		regizor = regizor_;
	}

	const std::string &getRegizor() const {
		return regizor;
	}

	void setRating(const std::string &rating_) {
		rating = rating_;
	}

	const std::string &getRating() const {
		return rating;
	}

	void setFormat(const std::string &format_) {
		format = format_;
	}

	const std::string &getFormat() const {
		return format;
	}

	void setPret(const float pret_) {
		pret = pret_;
	}

	float getPret() const {
		return pret;
	}

	float pretElevi() const {
		return pret * 0.8;
	}
};

class Sala {
private:
	int numar;
	int randuri;
	int coloane;

public:
	Sala() {};

	~Sala() {};

	Sala(const int numar, const int randuri, const int coloane)
		: numar(numar), randuri(randuri), coloane(coloane) {}

	Sala(const Sala &copie)
		: numar(copie.numar), randuri(copie.randuri), coloane(copie.coloane) {}

	Sala &operator=(const Sala &copie) {
		numar = copie.numar;
		randuri = copie.randuri;
		coloane = copie.coloane;
		return *this;
	}

	friend std::ostream &operator<<(std::ostream &os, const Sala &sala) {
		os << "- Sala " << sala.numar << " -\n";
		for (int i = 0; i < 2 * sala.coloane - 4; i++)
			os << "-";
		os << " Ecran ";
		for (int i = 0; i < 2 * sala.coloane - 4; i++)
			os << "-";
		os << "\n";
		for (int i = 0; i < sala.randuri; i++) {
			for (int j = 0; j < sala.coloane; j++) {
				if (i * sala.coloane + j + 1 < 10)
					os << " ";
				if (i * sala.coloane + j + 1 < 100)
					os << " ";
				os << i * sala.coloane + j + 1;
				if (j != sala.coloane - 1)
					os << " ";
			}
			os << "\n";
		}
		return os;
	}

	void setNumar(const int numar_) {
		numar = numar_;
	}

	int getNumar() const {
		return numar;
	}

	void setRanduri(const int randuri_) {
		randuri = randuri_;
	}

	int getRanduri() const {
		return randuri;
	}

	void setColoane(const int coloane_) {
		coloane = coloane_;
	}

	int getColoane() const {
		return coloane;
	}
};

class Proiectie {
private:
	Film film;
	std::string zi;
	std::string	ora;
	Sala sala;
	std::set<int> ocupate;

public:
	Proiectie() {};

	~Proiectie() {};

	Proiectie(const Film &film, const std::string &zi, const std::string &ora, const Sala &sala, const std::set<int> &ocupate)
		: film(film), zi(zi), ora(ora), sala(sala), ocupate(ocupate) {}

	Proiectie(const Proiectie &copie)
		: film(copie.film), zi(copie.zi), ora(copie.ora), sala(copie.sala), ocupate(copie.ocupate) {}

	Proiectie &operator=(const Proiectie &copie) {
		film = copie.film;
		zi = copie.zi;
		ora = copie.ora;
		sala = copie.sala;
		ocupate = copie.ocupate;
		return *this;
	}

	friend std::ostream &operator<<(std::ostream &os, const Proiectie &proiectie) {
		os << proiectie.film.getNume() << "\n";
		os << proiectie.zi << ", ora " << proiectie.ora << "\n";
		os << "Sala " << proiectie.sala.getNumar() << "\n";
		const int &randuri = proiectie.sala.getRanduri();
		const int &coloane = proiectie.sala.getColoane();
		for (int i = 0; i < 2 * coloane - 4; i++)
			os << "-";
		os << " Ecran ";
		for (int i = 0; i < 2 * coloane - 4; i++)
			os << "-";
		os << "\n";
		for (int i = 0; i < randuri; i++) {
			for (int j = 0; j < coloane; j++) {
				if (proiectie.ocupate.find(i * coloane + j + 1) == proiectie.ocupate.end()) {
					if (i * coloane + j + 1 < 10)
						os << " ";
					if (i * coloane + j + 1 < 100)
						os << " ";
					os << i * coloane + j + 1;
				}
				else
					os << "  X";
				if (j != coloane - 1)
					os << " ";
			}
			os << "\n";
		}
		return os;
	}

	void setFilm(const Film &film_) {
		film = film_;
	}

	const Film &getFilm() const {
		return film;
	}

	void setZi(const std::string &zi_) {
		zi = zi_;
	}

	const std::string &getZi() const {
		return zi;
	}

	void setOra(const std::string &ora_) {
		ora = ora_;
	}

	const std::string &getOra() const {
		return ora;
	}

	void setSala(const Sala &sala_) {
		sala = sala_;
	}

	const Sala &getSala() const {
		return sala;
	}

	void setOcupate(const std::set<int> &ocupate_) {
		ocupate = ocupate_;
	}

	const std::set<int> &getOcupate() const {
		return ocupate;
	}

	int locuriRamase() const {
		return sala.getRanduri() * sala.getColoane() - ocupate.size();
	}
};

class ProgramZi {
private:
	std::vector<Proiectie> zi;

	void sortareProiectii() {
		std::sort(zi.begin(), zi.end(), [](const Proiectie &p1, const Proiectie &p2) {
			return p1.getOra() < p2.getOra();
		});
	}

	std::string oraString(const int &ora) {
		std::string ora_st(5, ' ');
		ora_st[0] = '0' + ora / 60 / 10;
		ora_st[1] = '0' + ora / 60 % 10;
		ora_st[2] = ':';
		ora_st[3] = '0' + ora % 60 / 10;
		ora_st[4] = '0' + ora % 60 % 10;
		return ora_st;
	}

	int urmatoareaOra(const int &ora) {
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

public:
	ProgramZi() {};

	~ProgramZi() {};

	explicit ProgramZi(const std::vector<Proiectie> &zi)
		: zi(zi) {
		sortareProiectii();
	}

	ProgramZi(const ProgramZi &copie)
		: zi(copie.zi) {}

	ProgramZi &operator=(const ProgramZi &copie) {
		zi = copie.zi;
		return *this;
	}

	friend std::ostream &operator<<(std::ostream &os, const ProgramZi &program) {
		for (size_t i = 0; i < program.zi.size(); i++) {
			const Proiectie &proiectie = program.zi[i];
			os << "Ora " << proiectie.getOra() << " | ";
			os << "Sala " << proiectie.getSala().getNumar() << " | ";
			os << proiectie.getFilm().getNume() << " | ";
			const int &locuri = proiectie.locuriRamase();
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

	void setZi(const std::vector<Proiectie> &zi_) {
		zi = zi_;
		sortareProiectii();
	}

	const std::vector<Proiectie> &getZi() const {
		return zi;
	}

	void adaugaProiectie(const Proiectie &proiectie) {
		zi.push_back(proiectie);
		sortareProiectii();
	}

	ProgramZi generare(const std::vector<Film> &filme_aux, const std::vector<Sala> &sali_aux) {
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
};

class ProgramSaptamana {
private:
	std::vector<std::pair<std::string, ProgramZi>> saptamana;
public:
	ProgramSaptamana() {};

	~ProgramSaptamana() {};

	explicit ProgramSaptamana(const std::vector<std::pair<std::string, ProgramZi>> &saptamana)
		: saptamana(saptamana) {}

	ProgramSaptamana(const ProgramSaptamana &copie)
		: saptamana(copie.saptamana) {}

	ProgramSaptamana &operator=(const ProgramSaptamana &copie) {
		saptamana = copie.saptamana;
		return *this;
	}

	friend std::ostream &operator<<(std::ostream &os, const ProgramSaptamana &program) {
		for (size_t i = 0; i < program.saptamana.size(); i++)
			os << "- " << program.saptamana[i].first << " -\n" << program.saptamana[i].second << "\n";
		return os;
	}

	void setSaptamana(const std::vector<std::pair<std::string, ProgramZi>> &saptamana_) {
		saptamana = saptamana_;
	}

	const std::vector<std::pair<std::string, ProgramZi>> &getSaptamana() const {
		return saptamana;
	}

	ProgramSaptamana adaugaZi(const std::pair<std::string, ProgramZi> &program_zi) {
		saptamana.push_back(program_zi);
		ProgramSaptamana program;
		program.setSaptamana(saptamana);
		return program;
	}

	ProgramSaptamana generare(const std::vector<Film> &filme, const std::vector<Sala> &sali) {
		ProgramSaptamana program;
		for (int i = 1; i <= 7; i++) {
			std::string zi;
			switch (i) {
				case 1:	zi = "Luni";
						break;
				case 2:	zi = "Marti";
						break;
				case 3: zi = "Miercuri";
						break;
				case 4: zi = "Joi";
						break;
				case 5: zi = "Vineri";
						break;
				case 6: zi = "Sambata";
						break;
				default: zi = "Duminica";
			}
			ProgramZi program_zi = saptamana[i].second.generare(filme, sali);
			std::vector<Proiectie> proiectii = program_zi.getZi();
			for (size_t j = 0; j < proiectii.size(); j++)
				proiectii[j].setZi(zi);
			program_zi.setZi(proiectii);
			program.saptamana.push_back({zi, program_zi});
		}
		return program;
	}
};

class Client {
private:
	std::string	nume;
	std::string	email;
	std::string	telefon;

public:
	Client() {};

	~Client() {};

	Client(const std::string &nume, const std::string &email, const std::string &telefon)
		: nume(nume), email(email), telefon(telefon) {}

	Client(const Client &copie)
		: nume(copie.nume), email(copie.email), telefon(copie.telefon) {}

	Client &operator=(const Client &copie) {
		nume = copie.nume;
		email = copie.email;
		telefon = copie.telefon;
		return *this;
	}

	friend std::ostream &operator<<(std::ostream &os, const Client &client) {
		os << "Nume: " << client.nume << "\n";
		os << "Email: " << client.email << "\n";
		os << "Telefon: " << client.telefon << "\n";
		return os;
	}

	void setNume(const std::string &nume_) {
		nume = nume_;
	}

	const std::string &getNume() const {
		return nume;
	}

	void setEmail(const std::string &email_) {
		email = email_;
	}

	const std::string &getEmail() const {
		return email;
	}

	void setTelefon(const std::string &telefon_) {
		telefon = telefon_;
	}

	const std::string &getTelefon() const {
		return telefon;
	}
};

class Rezervare {
private:
	Client client;
	Proiectie proiectie;
	std::vector<int> locuri;
	int elevi;

public:
	Rezervare() {};

	~Rezervare() {};

	Rezervare(const Client &client, const Proiectie &proiectie, const std::vector<int> &locuri, const int &elevi)
		: client(client), proiectie(proiectie), locuri(locuri), elevi(elevi) {}

	Rezervare(const Rezervare &copie)
		: client(copie.client), proiectie(copie.proiectie), locuri(copie.locuri), elevi(copie.elevi) {}

	Rezervare &operator=(const Rezervare &copie) {
		client = copie.client;
		proiectie = copie.proiectie;
		locuri = copie.locuri;
		elevi = copie.elevi;
		return *this;
	}

	friend std::ostream &operator<<(std::ostream &os, const Rezervare &rezervare) {
		os << rezervare.client;
		os << "Film: \"" << rezervare.proiectie.getFilm().getNume() << "\", ";
		os << rezervare.proiectie.getZi() << ", Ora " << rezervare.proiectie.getOra() << ", Sala " << rezervare.proiectie.getSala().getNumar() << "\n";
		os << "Locuri: ";
		for (size_t i = 0; i < rezervare.locuri.size(); i++) {
			os << rezervare.locuri[i];
			if (i != rezervare.locuri.size() - 1)
				os << ", ";
		}
		os << "\n";
		os << "Numar elevi: " << rezervare.elevi << "\n";
		os << "Pret: " << rezervare.pretRezervare() << " lei\n";
		return os;
	}

	void setClient(const Client &client_) {
		client = client_;
	}

	const Client &getClient() const {
		return client;
	}

	void setProiectie(const Proiectie &proiectie_) {
		proiectie = proiectie_;
	}

	const Proiectie &getProiectie() const {
		return proiectie;
	}

	void setLocuri(const std::vector<int> &locuri_) {
		locuri = locuri_;
	}

	const std::vector<int> &getLocuri() const {
		return locuri;
	}

	void setElevi(const int elevi_) {
		elevi = elevi_;
	}

	int getElevi() const {
		return elevi;
	}

	float pretRezervare() const {
		return (locuri.size() - elevi) * proiectie.getFilm().getPret() + elevi * proiectie.getFilm().pretElevi();
	}
};

int main() {

	return 0;
}