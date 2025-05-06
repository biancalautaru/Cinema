#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <vector>
#include <set>
#include <memory>

#include "headers/Bautura.h"
#include "headers/Film.h"
#include "headers/Sala.h"
#include "headers/Proiectie.h"
#include "headers/ProgramZi.h"
#include "headers/ProgramSaptamana.h"
#include "headers/Client.h"
#include "headers/Rezervare.h"
#include "headers/Produs.h"
#include "headers/Mancare.h"
#include "headers/Bautura.h"
#include "headers/Meniu.h"
#include "headers/Suvenir.h"
#include "headers/Bar.h"
#include "headers/Exceptie.h"

int main() {
	// creare filme
	std::vector<Film> filme = {
		{"Memento", {"Mister", "Thriller"}, 113, 2000, "Christopher Nolan", "N-15", "2D", 35},
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

	// creare sali
	std::vector<Sala> sali = {
		{1, 5, 20},
		{2, 8, 12},
		{3, 5, 15},
		{4, 7, 11},
		{5, 9, 23}
	};

	// creare clienti
	std::vector<Client> clienti = {
		{"Ion Popescu", "ion.popescu@gmail.com", "0749187947"},
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

	// creare produse
	std::shared_ptr<Produs> popcorn_mic = std::make_shared<Mancare>("Popcorn", 16.99, 300);
	std::shared_ptr<Produs> popcorn_mediu = std::make_shared<Mancare>("Popcorn", 20.99, 500);
	std::shared_ptr<Produs> popcorn_mare = std::make_shared<Mancare>("Popcorn", 24.99, 800);
	std::shared_ptr<Produs> cola_mic = std::make_shared<Bautura>("Coca-Cola", 7.99, 330);
	std::shared_ptr<Produs> cola_mediu = std::make_shared<Bautura>("Coca-Cola", 9.99, 500);
	std::shared_ptr<Produs> cola_mare = std::make_shared<Bautura>("Coca-Cola", 12.99, 750);
	std::shared_ptr<Produs> meniu_mic = std::make_shared<Meniu>("Meniu Mic", 20.99, popcorn_mic->getNume(), popcorn_mic->getGramaj(), cola_mic->getNume(), cola_mic->getVolum(), MIC);
	std::shared_ptr<Produs> meniu_mediu = std::make_shared<Meniu>("Meniu Mediu", 26.99, popcorn_mediu->getNume(), popcorn_mediu->getGramaj(), cola_mediu->getNume(), cola_mediu->getVolum(), MEDIU);
	std::shared_ptr<Produs> meniu_mare = std::make_shared<Meniu>("Meniu Mare", 31.99, popcorn_mare->getNume(), popcorn_mare->getGramaj(), cola_mare->getNume(), cola_mare->getVolum(), MARE);
	std::shared_ptr<Produs> meniu_mic_mediu = std::make_shared<Meniu>("Meniu mic-mediu", 23.99, popcorn_mic->getNume(), popcorn_mic->getGramaj(), cola_mediu->getNume(), cola_mediu->getVolum(), SPECIAL);
	std::shared_ptr<Produs> meniu_mediu_mare = std::make_shared<Meniu>("Meniu mediu-mare", 28.99, popcorn_mediu->getNume(), popcorn_mediu->getGramaj(), cola_mare->getNume(), cola_mare->getVolum(), SPECIAL);
	std::shared_ptr<Produs> pahar_dune = std::make_shared<Suvenir>("Pahar", 34.99, "Dune: Part One");
	std::shared_ptr<Produs> tricou_barbie = std::make_shared<Suvenir>("Tricou", 54.99, "Barbie");

	// adaugare produse la bar
	Bar bar;
	bar.adaugaProdus(popcorn_mic);
	bar.adaugaProdus(popcorn_mediu);
	bar.adaugaProdus(popcorn_mare);
	bar.adaugaProdus(cola_mic);
	bar.adaugaProdus(cola_mediu);
	bar.adaugaProdus(cola_mare);
	bar.adaugaProdus(meniu_mic);
	bar.adaugaProdus(meniu_mediu);
	bar.adaugaProdus(meniu_mare);
	bar.adaugaProdus(meniu_mic_mediu);
	bar.adaugaProdus(meniu_mediu_mare);
	bar.adaugaProdus(pahar_dune);
	bar.adaugaProdus(tricou_barbie);

	bar.aplicaPromotii();
	bar.aplicaPromotiiMeniuri();

	// meniu interactiv
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
		std::string linie;
		int optiune;
		while (true) {
			try {
				std::getline(std::cin, linie);
				optiune = 0;
				for (size_t i = 0; i < linie.size() && isdigit(linie[i]); i++)
					optiune = 10 * optiune + (linie[i] - '0');
				if (optiune < 1 || optiune > 6)
					throw OptiuneInexistenta();
				break;
			}
			catch (const OptiuneInexistenta& e) {
				std::cout << e.what();
			}
		}

		if (optiune == 1) {
			auto azi = std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now());
			auto ziua_saptamanii = std::chrono::weekday{std::chrono::sys_days{azi}};
			int nr_azi = ziua_saptamanii.c_encoding() - 1;
			if (nr_azi == -1)
				nr_azi = 6;
			auto program_azi =  program_saptamana.getSaptamana()[nr_azi];
			std::cout << "- " << program_azi.first<< " -\n" << program_azi.second;
		}
		else if (optiune == 2)
			std::cout << program_saptamana;
		else if (optiune == 3)
			for (size_t i = 0; i < filme.size(); i++) {
				std::cout << filme[i];
				if (i != filme.size() - 1)
					std::cout << "----------------------------------------\n";
				else
					std::cout << "\n";
			}
		else if (optiune == 4)
			for (size_t i = 0; i < sali.size(); i++)
				std::cout << sali[i] << "\n";
		else if (optiune == 5) {
			std::cout << "- Creare rezervare -\n\n";

			std::string nume, email, telefon;
			std::cout << "Nume: ";
			std::getline(std::cin, nume);
			std::cout << "Email: ";
			std::getline(std::cin, email);
			std::cout << "Telefon: ";
			std::getline(std::cin, telefon);

			std::string zi;
			std::cout << "Ziua aleasa: ";
			std::getline(std::cin, zi);
			if (islower(zi[0]))
				zi[0] = zi[0] - 'a' + 'A';
			int nr_zi = -1;
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

			std::vector<Proiectie> proiectii, proiectii_modificat;
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
			int nr_proiectie = 0;
			for (size_t i = 0; i < linie.size() && isdigit(linie[i]); i++)
				nr_proiectie = 10 * nr_proiectie + (linie[i] - '0');
			nr_proiectie--;
			if (nr_proiectie == -1)
				nr_proiectie = 0;
			std::cout << proiectii[nr_proiectie] << "\n";

			std::vector<int> locuri;
			while (true) {
				try {
					std::cout << "Introduceti locurile dorite (separate prin spatii): ";
					while (true) {
						std::getline(std::cin, linie);
						try {
							for (size_t i = 0; i < linie.size(); i++)
								if (!isdigit(linie[i]) && linie[i] != ' ')
									throw InputGresit();
							break;
						}
						catch (const InputGresit& e) {
							std::cout << e.what();
						}
					}

					locuri.clear();
					for (size_t i = 0; i < linie.size(); i++)
						if (isdigit(linie[i])) {
							int loc = 0;
							size_t j;
							for (j = i; isdigit(linie[j]); j++)
								loc = loc * 10 + linie[j] - '0';
							i = j - 1;
							locuri.push_back(loc);
						}

					for (auto loc : locuri)
						for (auto it : proiectii[nr_proiectie].getOcupate())
							if (loc == it)
								throw LocOcupat();

					break;
				}
				catch (const LocOcupat& e) {
					std::cout << e.what();
				}
			}

			std::cout << "Numarul de bilete destinate elevilor (20% reducere): ";
			std::getline(std::cin, linie);
			int elevi = 0;
			for (size_t i = 0; i < linie.size() && isdigit(linie[i]); i++)
				elevi = 10 * elevi + (linie[i] - '0');

			Rezervare rezervare;
			rezervare.setClient({nume, email, telefon});
			rezervare.setProiectie(proiectii[nr_proiectie]);
			rezervare.setLocuri(locuri);
			rezervare.setElevi(elevi);
			rezervari.push_back(rezervare);

			std::set<int> ocupate = proiectii[nr_proiectie].getOcupate();
			for (size_t i = 0; i < locuri.size(); i++)
				ocupate.insert(locuri[i]);
			std::vector<std::pair<std::string, ProgramZi>> program_modificat = program_saptamana.getSaptamana();
			proiectii_modificat = program_modificat[nr_zi].second.getZi();
			proiectii_modificat[nr_proiectie].setOcupate(ocupate);
			program_modificat[nr_zi].second.setZi(proiectii_modificat);
			program_saptamana.setSaptamana(program_modificat);
			for (size_t i = 0; i < rezervari.size(); i++)
				if (rezervari[i].getProiectie().getZi() == proiectii[nr_proiectie].getZi()
				&& rezervari[i].getProiectie().getOra() == proiectii[nr_proiectie].getOra()
				&& rezervari[i].getProiectie().getSala().getNumar() == proiectii[nr_proiectie].getSala().getNumar())
					rezervari[i].setProiectie(proiectii_modificat[nr_proiectie]);

			std::cout << "Doriti sa adaugati produse de la bar la rezervare? (da/nu)\n";
			std::getline(std::cin, linie);
			if (linie == "nu") {
				std::cout << "Rezervarea a fost efectuata!\n\nDetalii rezervare:\n";
				rezervari[rezervari.size() - 1].afisareRezervare(std::cout);
			}
			else {
				rezervari[rezervari.size() - 1].citireProduse(std::cin, std::cout, bar);
				std::cout << "Rezervarea a fost efectuata!\n\nDetalii rezervare:\n";
				rezervari[rezervari.size() - 1].afisareRezervare(std::cout);
				std::cout << "\n";
				std::cout << "Produse comandate de la bar:\n";
				rezervari[rezervari.size() - 1].afisareProduse(std::cout);
				std::cout << "\n";
				std::cout << "Pret total rezervare: " << rezervari[rezervari.size() - 1].pretTotal() << " lei\n";
			}
		}
		else if (optiune == 6)
			break;
		std::cout << "\n";
	}
	return 0;
}
