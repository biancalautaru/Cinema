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

	void adaugaZi(const std::pair<std::string, ProgramZi> &program) {
		saptamana.push_back(program);
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
	// creare filme
	std::vector<Film> filme = {
		{"memento", {"Mister"}, 112, 2001, "Christopher Nolan", "N", "3D", 30},
		{"Catch Me If You Can", {"Biografie", "Crima", "Drama"}, 141, 2002, "Steven Spielberg", "AP-12", "2D", 35},
		{"The Shawshank Redemption", {"Drama"}, 142, 1994, "Frank Darabont", "N-15", "2D", 35},
		{"Taxi Driver", {"Crima", "Drama"}, 114, 1976, "Martin Scorsese", "N-15", "2D", 30},
		{"Back to the Future", {"Aventura", "Comedie", "SF"}, 116, 1985, "Robert Zemeckis", "AP-12", "2D", 30},
		{"The Talented Mr. Ripley", {"Crima", "Drama", "Thriller"}, 139, 1999, "Anthony Minghella", "N-15", "2D", 35},
		{"Inception", {"Actiune", "Aventura", "SF", "Thriller"}, 148, 2010, "Christopher Nolan", "N-15", "2D", 40},
		{"Whiplash", {"Drama", "Muzica"}, 106, 2014, "Damien Chazelle", "AP-12", "2D", 30},
		{"Hachi: A Dog's Tale", {"Biografie", "Drama", "Familie"}, 93, 2009, "Lasse Hallstrom", "AG", "2D", 25},
		{"The Sixth Sense", {"Drama", "Mister", "Thriller"}, 107, 1999, "M. Night Shyamalan", "AP-12", "2D", 30},
		{"Liar Liar", {"Comedie", "Fantastic"}, 86, 1997, "Tom Shadyac", "AP-12", "2D", 25},
		{"The Search for Santa Paws", {"Aventura", "Drama", "Familie", "Fantastic"}, 96, 2010, "Robert Vince","AG", "2D", 25},
		{"Barbie", {"Aventura", "Comedie", "Fantastic"}, 114, 2023, "Greta Gerwig", "AP-12", "2D", 25},
		{"The Godfather", {"Crima", "Drama"}, 175, 1972, "Francis Ford Coppola", "N-15", "2D", 35},
		{"Se7en", {"Crima", "Drama", "Mister", "Thriller"}, 127, 1995, "David Fincher", "N-15", "2D", 30},
		{"The Wolf of Wall Street", {"Biografie", "Comedie", "Crima", "Drama"}, 180, 2013, "Martin Scorsese", "IM-18", "2D", 35},
		{"Casino", {"Crima", "Drama"}, 178, 1995, "Martin Scorsese", "N-15", "2D", 35},
		{"Avatar", {"Actiune", "Aventura", "Fantastic", "SF"}, 162, 2009, "James Cameron", "AP-12", "3D", 40},
		{"Once Upon a Time in America", {"Crima", "Drama"}, 229, 1984, "Sergio Leone", "IM-18", "2D", 40},
		{"Forrest Gump", {"Comedie", "Drama", "Romantic"}, 142, 1994, "Robert Zemeckis", "AP-12", "2D", 30},
		{"Inglourious Basterds", {"Aventura", "Drama", "Razboi"}, 153, 2009, "Quentin Tarantino", "IM-18", "2D", 35},
		{"Dune: Part One", {"Actiune", "Aventura", "Drama", "SF"}, 155, 2021, "Denis Villeneuve", "AP-12", "3D", 40},
		{"The Princess Diaries", {"Comedie", "Familie", "Romantic"}, 105, 2001, "Garry Marshall", "AG", "2D", 25}
	};

	std::string nume_film0 = filme[0].getNume();
	nume_film0[0] = 'M';
	filme[0].setNume(nume_film0);
	std::vector<std::string> gen0 = filme[0].getGen();
	gen0.push_back({"Thriller"});
	filme[0].setGen(gen0);
	int durata0 = filme[0].getDurata();
	durata0++;
	filme[0].setDurata(durata0);
	int an0 = filme[0].getAn();
	an0--;
	filme[0].setAn(an0);
	std::string regizor0 = filme[0].getRegizor();
	regizor0[0] = 'C';
	filme[0].setRegizor(regizor0);
	std::string rating0 = filme[0].getRating();
	rating0 += "-15";
	filme[0].setRating(rating0);
	std::string format0 = filme[0].getFormat();
	format0[0] = '2';
	filme[0].setFormat(format0);
	float pret0 = filme[0].getPret();
	pret0 += 5;
	filme[0].setPret(pret0);

	// creare sali
	std::vector<Sala> sali = {
		{0, 4, 23},
		{2, 8, 12},
		{3, 5, 15},
		{4, 7, 11},
		{5, 9, 23}
	};

	int numar0 = sali[0].getNumar();
	numar0++;
	sali[0].setNumar(numar0);
	int randuri0 = sali[0].getRanduri();
	randuri0 += 2;
	sali[0].setRanduri(randuri0);
	int coloane0 = sali[0].getColoane();
	coloane0 -= 3;
	sali[0].setColoane(coloane0);

	// creare clienti
	std::vector<Client> clienti = {
		{"ion Popescu", "ion.Popescu@gmail.com", "0849187947"},
		{"George Ionescu", "george.ionescu@gmail.com", "0764367341"},
		{"Mihai Vasile", "mihai.vasile@yahoo.com", "0737635326"},
		{"Alexandru Radulescu", "alexandru.radulescu@gmail.com", "0789525437"},
		{"Gabriel Tudor", "gabriel.tudor@hotmail.com", "0778912345"},
		{"Maria Popa", "maria.popa@yahoo.com", "0758369424"},
		{"Diana Munteanu", "diana.munteanu@hotmail.com", "0723658741"},
		{"Gabriela Radu", "gabriela.radu@gmail.com", "0752375437"},
		{"Elena Dumitrescu", "elena.dumitrescu@yahoo.com", "0765432199"},
		{"Ana Dobre", "ana.dobre@gmail.com", "0745123789"}
	};

	std::string nume0 = clienti[0].getNume();
	nume0[0] = 'I';
	clienti[0].setNume(nume0);
	std::string email0 = clienti[0].getEmail();
	email0[4] = 'p';
	clienti[0].setEmail(email0);
	std::string telefon0 = clienti[0].getTelefon();
	telefon0[1] = '7';
	clienti[0].setTelefon(telefon0);

	// generare program
	ProgramSaptamana program_saptamana;
	program_saptamana = program_saptamana.generare(filme, sali);

	// creare rezervari existente
	std::vector<Rezervare> rezervari;
	std::vector<std::pair<std::string, ProgramZi>> program = program_saptamana.getSaptamana();
	for (size_t i = 0; i < program.size(); i++) {
		std::vector<Proiectie> proiectii = program[i].second.getZi();

		for (size_t j = 0; j < proiectii.size(); j++) {
			std::set<int> ocupate = proiectii[j].getOcupate();

			std::vector<int> clienti_fara_rezervare;
			for (size_t k = 0; k < clienti.size(); k++)
				clienti_fara_rezervare.push_back(k);

			int ultima_rezervare = rezervari.size() - 1;

			// pentru fiecare proiectie, selectez un nr random (intre 0 si size clienti)
			std::srand(std::chrono::system_clock::now().time_since_epoch().count());
			int nr_clienti = rand() % clienti.size();

			while (nr_clienti--) {
				// selectez un client random din cei ramasi
				int poz_client = rand() % clienti_fara_rezervare.size();
				const Client &client = clienti[clienti_fara_rezervare[poz_client]];
				clienti_fara_rezervare.erase(clienti_fara_rezervare.begin() + poz_client);

				// selectez random locurile (intre 1 si 10 + sa aiba loc pe un rand) si numarul elevilor
				int nr_locuri = 1 + rand() % 10;
				int nr_rand = rand() % proiectii[j].getSala().getRanduri();
				int nr_coloana = rand() % proiectii[j].getSala().getColoane();
				int col_start = std::max(0, nr_coloana - nr_locuri / 2);
				int col_final = std::min(nr_coloana + nr_locuri / 2, proiectii[j].getSala().getColoane() - 1);
				nr_locuri = col_final - col_start + 1;
				int nr_elevi = rand() % nr_locuri;
				std::vector<int> ocupate_rezervare;
				for (int k = col_start; k <= col_final; k++) {
					ocupate.insert(nr_rand * proiectii[j].getSala().getColoane() + k + 1);
					ocupate_rezervare.push_back(nr_rand * proiectii[j].getSala().getColoane() + k + 1);
				}

				// creez rezervarea
				Rezervare rezervare;
				rezervare.setClient(client);
				rezervare.setLocuri(ocupate_rezervare);
				rezervare.setElevi(nr_elevi);
				rezervari.push_back(rezervare);
			}

			proiectii[j].setOcupate(ocupate);
			for (size_t k = ultima_rezervare + 1; k < rezervari.size(); k++)
				rezervari[k].setProiectie(proiectii[j]);
		}

		ProgramZi program_zi;
		program_zi.setZi(proiectii);
		program_saptamana.adaugaZi({program[i].first, program_zi});
	}

	if (!rezervari.empty()) {
		Client client0 = rezervari[0].getClient();
		client0 = clienti[1];
		rezervari[0].setClient(client0);
		std::vector<int> locuri0 = rezervari[0].getLocuri();
		if (locuri0.size() > 1)
			locuri0.erase(locuri0.begin());
		rezervari[0].setLocuri(locuri0);
		int elevi0 = rezervari[0].getElevi();
		if (elevi0 == 1)
			elevi0 = 0;
		rezervari[0].setElevi(elevi0);
		if (rezervari.size() >= 2) {
			Proiectie proiectie0 = rezervari[0].getProiectie();
			proiectie0.setFilm(rezervari[1].getProiectie().getFilm());
			proiectie0.setOra(rezervari[1].getProiectie().getOra());
			proiectie0.setSala(rezervari[1].getProiectie().getSala());
			rezervari[0].setProiectie(proiectie0);
		}
	}

	// meniu interactiv
	auto azi = std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now());
	auto ziua_saptamanii = std::chrono::weekday{azi};
	auto program_azi =  program_saptamana.getSaptamana()[ziua_saptamanii.c_encoding() - 1];
	std::string nume, email, telefon, zi, locuri_string;
	std::vector<Proiectie> proiectii, proiectii_modificat;
	std::vector<int> locuri;
	std::set<int> ocupate;
	int nr_zi, nr_proiectie, elevi;
	std::vector<std::pair<std::string, ProgramZi>> program_modificat;
	bool repeat;
	while (true) {
		std::cout << "|---------------- Meniu ---------------|\n";
		std::cout << "| 1. Afisare program ziua curenta      |\n";
		std::cout << "|--------------------------------------|\n";
		std::cout << "| 2. Afisare program saptamana curenta |\n";
		std::cout << "|--------------------------------------|\n";
		std::cout << "| 3. Afisare lista filme               |\n";
		std::cout << "|--------------------------------------|\n";
		std::cout << "| 4. Afisare configuratie sali         |\n";
		std::cout << "|--------------------------------------|\n";
		std::cout << "| 5. Creare rezervare                  |\n";
		std::cout << "|--------------------------------------|\n";
		std::cout << "| 6. Iesire                            |\n";
		std::cout << "|--------------------------------------|\n";
		std::cout << "Introduceti numarul optiunii dorite:";
		int optiune;
		if (!(std::cin >> optiune))
			return 0;
		switch (optiune) {
			case 1:
				std::cout << "- " << program_azi.first<< " -\n" << program_azi.second;
				break;
			case 2:
				std::cout << program_saptamana;
				break;
			case 3:
				for (size_t i = 0; i < filme.size(); i++) {
					std::cout << filme[i];
					if (i != filme.size() - 1)
						std::cout << "----------------------------------------\n";
					else
						std::cout << "\n";
				}
				break;
			case 4:
				for (size_t i = 0; i < sali.size(); i++)
					std::cout << sali[i] << "\n";
				break;
			case 5:
				std::cout << "Nume: ";
				std::cin.ignore();
				std::getline(std::cin, nume);
				std::cout << "Email: ";
				std::cin >> email;
				std::cout << "Telefon: ";
				std::cin >> telefon;

				std::cout << "Ziua aleasa: ";
				std::cin >> zi;
				if (islower(zi[0]))
					zi[0] = zi[0] - 'a' + 'A';
				nr_zi = -1;
				if (zi == "Luni")
					nr_zi = 0;
				else if (zi == "Marti")
					nr_zi = 1;
				else if (zi == "Miercuri")
					nr_zi = 2;
				else if (zi == "Joi")
					nr_zi = 3;
				else if (zi == "Vineri")
					nr_zi = 4;
				else if (zi == "Sambata")
					nr_zi = 5;
				else if (zi == "Duminica")
					nr_zi = 6;

				proiectii = program_saptamana.getSaptamana()[nr_zi].second.getZi();
				for (size_t i = 0; i < proiectii.size(); i++) {
					if (i + 1 < 10)
						std::cout << " ";
					std::cout << i + 1 << ". ";
					std::cout << "| ";
					std::cout << "Ora " << proiectii[i].getOra() << " | ";
					std::cout << "Sala " << proiectii[i].getSala().getNumar() << " | ";
					std::cout << proiectii[i].getFilm().getNume() << " | ";
					int nr_locuri = proiectii[i].locuriRamase();
					if (nr_locuri == 1)
						std::cout << nr_locuri << " loc ramas";
					else
						if (nr_locuri >= 20)
							std::cout << nr_locuri << " de locuri ramase";
						else
							std::cout << nr_locuri << " locuri ramase";
					std::cout << "\n";
				}
				std::cout << "\n";
				std::cout << "Introduceti numarul proiectiei dorite: ";
				std::cin >> nr_proiectie;
				std::cin.ignore();
				nr_proiectie--;
				std::cout << proiectii[nr_proiectie] << "\n";
				repeat = true;
				while (repeat) {
					std::cout << "Introduceti locurile dorite (separate prin spatii): ";
					std::getline(std::cin, locuri_string);
					locuri.clear();
					for (int i = 0; locuri_string[i] != '\0'; i++)
						if (isdigit(locuri_string[i])) {
							int loc = 0;
							int j;
							for (j = i; isdigit(locuri_string[j]); j++)
								loc = loc * 10 + locuri_string[j] - '0';
							i = j - 1;
							locuri.push_back(loc);
						}
					repeat = false;
					for (size_t i = 0; i < locuri.size(); i++)
						for (auto it : proiectii[nr_proiectie].getOcupate())
							if (locuri[i] == it) {
								std::cout << "Alegeti locuri care nu sunt ocupate deja!\n\n";
								repeat = true;
								break;
							}
				}
				std::cout << "Numarul de bilete destinate elevilor (20% reducere): ";
				std::cin >> elevi;
				rezervari.push_back({{nume, email, telefon}, proiectii[nr_proiectie] , locuri, elevi});
				ocupate = proiectii[nr_proiectie].getOcupate();
				for (size_t i = 0; i < locuri.size(); i++)
					ocupate.insert(locuri[i]);
				program_modificat = program_saptamana.getSaptamana();
				proiectii_modificat = program_modificat[nr_zi].second.getZi();
				proiectii_modificat[nr_proiectie].setOcupate(ocupate);
				program_modificat[nr_zi].second.setZi(proiectii_modificat);
				program_saptamana.setSaptamana(program_modificat);
				for (size_t i = 0; i < rezervari.size(); i++)
					if (rezervari[i].getProiectie().getZi() == proiectii[nr_proiectie].getZi()
					&& rezervari[i].getProiectie().getOra() == proiectii[nr_proiectie].getOra()
					&& rezervari[i].getProiectie().getSala().getNumar() == proiectii[nr_proiectie].getSala().getNumar())
						rezervari[i].setProiectie(proiectii_modificat[nr_proiectie]);
				std::cout << "Rezervarea a fost efectuata!\n\nDetalii rezervare:\n" << rezervari[rezervari.size() - 1];
				break;
			case 6:
				return 0;
			default:
				std::cout << "Introduceti un numar valid!";
		}
		std::cout << "\n";
	}
	return 0;
}