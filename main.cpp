#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <vector>
#include <set>
#include "headers/Film.h"
#include "headers/Sala.h"
#include "headers/Proiectie.h"
#include "headers/ProgramZi.h"
#include "headers/ProgramSaptamana.h"
#include "headers/Client.h"
#include "headers/Rezervare.h"

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
	program_saptamana = {};
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
				const Client& client = clienti[clienti_fara_rezervare[poz_client]];
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
		program_saptamana = program_saptamana.adaugaZi({program[i].first, program_zi});
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
	auto ziua_saptamanii = std::chrono::weekday{std::chrono::sys_days{azi}};
	int nr_azi = ziua_saptamanii.c_encoding() - 1;
	if (nr_azi == -1)
		nr_azi = 6;
	auto program_azi =  program_saptamana.getSaptamana()[nr_azi];
	std::string nume, email, telefon, zi, linie;
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
		std::getline(std::cin, linie);
		int optiune = 0;
		for (size_t i = 0; i < linie.size()&&  isdigit(linie[i]); i++)
			optiune = 10 * optiune + (linie[i] - '0');
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
				std::getline(std::cin, nume);
				std::cout << "Email: ";
				std::getline(std::cin, email);
				std::cout << "Telefon: ";
				std::getline(std::cin, telefon);

				std::cout << "Ziua aleasa: ";
				std::getline(std::cin, zi);
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
				std::getline(std::cin, linie);
				nr_proiectie = 0;
				for (size_t i = 0; i < linie.size()&&  isdigit(linie[i]); i++)
					nr_proiectie = 10 * nr_proiectie + (linie[i] - '0');
				nr_proiectie--;
				if (nr_proiectie == -1)
					nr_proiectie = 0;
				std::cout << proiectii[nr_proiectie] << "\n";
				repeat = true;
				while (repeat) {
					std::cout << "Introduceti locurile dorite (separate prin spatii): ";
					std::getline(std::cin, linie);
					locuri.clear();
					for (size_t i = 0; i < linie.size(); i++)
						if (isdigit(linie[i])) {
							int loc = 0;
							int j;
							for (j = i; isdigit(linie[j]); j++)
								loc = loc * 10 + linie[j] - '0';
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
				std::getline(std::cin, linie);
				elevi = 0;
				for (size_t i = 0; i < linie.size()&&  isdigit(linie[i]); i++)
					elevi = 10 * elevi + (linie[i] - '0');
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