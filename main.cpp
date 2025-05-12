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
#include "headers/SalaBuilder.h"
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
#include "headers/Catalog.h"
#include "headers/OptiuneInexistenta.h"
#include "headers/InputGresit.h"
#include "headers/LocOcupat.h"

int main() {
	// creare filme
	Catalog<Film> catalog_filme;
	catalog_filme.adaugaObiect({"Memento", {"Mister", "Thriller"}, 113, 2000, "Christopher Nolan", "N-15", "2D", 35});
	catalog_filme.adaugaObiect({"Catch Me If You Can", {"Biografie", "Crima", "Drama"}, 141, 2002, "Steven Spielberg", "AP-12", "2D", 35});
	catalog_filme.adaugaObiect({"The Shawshank Redemption", {"Drama"}, 142, 1994, "Frank Darabont", "N-15", "2D", 35});
	catalog_filme.adaugaObiect({"Taxi Driver", {"Crima", "Drama"}, 114, 1976, "Martin Scorsese", "N-15", "2D", 30});
	catalog_filme.adaugaObiect({"Back to the Future", {"Aventura", "Comedie", "SF"}, 116, 1985, "Robert Zemeckis", "AP-12", "2D", 30});
	catalog_filme.adaugaObiect({"The Talented Mr. Ripley", {"Crima", "Drama", "Thriller"}, 139, 1999, "Anthony Minghella", "N-15", "2D", 35});
	catalog_filme.adaugaObiect({"Inception", {"Actiune", "Aventura", "SF", "Thriller"}, 148, 2010, "Christopher Nolan", "N-15", "2D", 40});
	catalog_filme.adaugaObiect({"Whiplash", {"Drama", "Muzica"}, 106, 2014, "Damien Chazelle", "AP-12", "2D", 30});
	catalog_filme.adaugaObiect({"Hachi: A Dog's Tale", {"Biografie", "Drama", "Familie"}, 93, 2009, "Lasse Hallstrom", "AG", "2D", 25});
	catalog_filme.adaugaObiect({"The Sixth Sense", {"Drama", "Mister", "Thriller"}, 107, 1999, "M. Night Shyamalan", "AP-12", "2D", 30});
	catalog_filme.adaugaObiect({"Liar Liar", {"Comedie", "Fantastic"}, 86, 1997, "Tom Shadyac", "AP-12", "2D", 25});
	catalog_filme.adaugaObiect({"The Search for Santa Paws", {"Aventura", "Drama", "Familie", "Fantastic"}, 96, 2010, "Robert Vince","AG", "2D", 25});
	catalog_filme.adaugaObiect({"Barbie", {"Aventura", "Comedie", "Fantastic"}, 114, 2023, "Greta Gerwig", "AP-12", "2D", 25});
	catalog_filme.adaugaObiect({"The Godfather", {"Crima", "Drama"}, 175, 1972, "Francis Ford Coppola", "N-15", "2D", 35});
	catalog_filme.adaugaObiect({"Se7en", {"Crima", "Drama", "Mister", "Thriller"}, 127, 1995, "David Fincher", "N-15", "2D", 30});
	catalog_filme.adaugaObiect({"The Wolf of Wall Street", {"Biografie", "Comedie", "Crima", "Drama"}, 180, 2013, "Martin Scorsese", "IM-18", "2D", 35});
	catalog_filme.adaugaObiect({"Casino", {"Crima", "Drama"}, 178, 1995, "Martin Scorsese", "N-15", "2D", 35});
	catalog_filme.adaugaObiect({"Avatar", {"Actiune", "Aventura", "Fantastic", "SF"}, 162, 2009, "James Cameron", "AP-12", "3D", 40});
	catalog_filme.adaugaObiect({"Once Upon a Time in America", {"Crima", "Drama"}, 229, 1984, "Sergio Leone", "IM-18", "2D", 40});
	catalog_filme.adaugaObiect({"Forrest Gump", {"Comedie", "Drama", "Romantic"}, 142, 1994, "Robert Zemeckis", "AP-12", "2D", 30});
	catalog_filme.adaugaObiect({"Inglourious Basterds", {"Aventura", "Drama", "Razboi"}, 153, 2009, "Quentin Tarantino", "IM-18", "2D", 35});
	catalog_filme.adaugaObiect({"Dune: Part One", {"Actiune", "Aventura", "Drama", "SF"}, 155, 2021, "Denis Villeneuve", "AP-12", "3D", 40});
	catalog_filme.adaugaObiect({"The Princess Diaries", {"Comedie", "Familie", "Romantic"}, 105, 2001, "Garry Marshall", "AG", "2D", 25});
	std::vector<Film> filme = catalog_filme.getObiecte();

	// creare sali
	Catalog<Sala> catalog_sali;
	SalaBuilder builder;
	catalog_sali.adaugaObiect(builder.numar(1).randuri(5).coloane(20).build());
	catalog_sali.adaugaObiect(builder.numar(2).randuri(8).coloane(12).build());
	catalog_sali.adaugaObiect(builder.numar(3).randuri(5).coloane(15).build());
	catalog_sali.adaugaObiect(builder.numar(4).randuri(7).coloane(11).build());
	catalog_sali.adaugaObiect(builder.numar(5).randuri(9).coloane(23).build());
	std::vector<Sala> sali = catalog_sali.getObiecte();

	// creare clienti
	Catalog<Client> catalog_clienti;
	catalog_clienti.adaugaObiect({"Ion Popescu", "ion.popescu@gmail.com", "0749187947"});
	catalog_clienti.adaugaObiect({"George Ionescu", "george.ionescu@gmail.com", "0764367341"});
	catalog_clienti.adaugaObiect({"Mihai Vasile", "mihai.vasile@yahoo.com", "0737635326"});
	catalog_clienti.adaugaObiect({"Alexandru Radulescu", "alexandru.radulescu@gmail.com", "0789525437"});
	catalog_clienti.adaugaObiect({"Gabriel Tudor", "gabriel.tudor@hotmail.com", "0778912345"});
	catalog_clienti.adaugaObiect({"Maria Popa", "maria.popa@yahoo.com", "0758369424"});
	catalog_clienti.adaugaObiect({"Diana Munteanu", "diana.munteanu@hotmail.com", "0723658741"});
	catalog_clienti.adaugaObiect({"Gabriela Radu", "gabriela.radu@gmail.com", "0752375437"});
	catalog_clienti.adaugaObiect({"Elena Dumitrescu", "elena.dumitrescu@yahoo.com", "0765432199"});
	catalog_clienti.adaugaObiect({"Ana Dobre", "ana.dobre@gmail.com", "0745123789"});
	std::vector<Client> clienti = catalog_clienti.getObiecte();

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
	std::shared_ptr<Produs> popcorn_mic = std::make_shared<Mancare>("Popcorn Mic", 16.99, 300);
	std::shared_ptr<Produs> popcorn_mediu = std::make_shared<Mancare>("Popcorn Mediu", 20.99, 500);
	std::shared_ptr<Produs> popcorn_mare = std::make_shared<Mancare>("Popcorn Mare", 24.99, 800);
	std::shared_ptr<Produs> cola_mic = std::make_shared<Bautura>("Coca-Cola Mic", 7.99, 330);
	std::shared_ptr<Produs> cola_mediu = std::make_shared<Bautura>("Coca-Cola Mediu", 9.99, 500);
	std::shared_ptr<Produs> cola_mare = std::make_shared<Bautura>("Coca-Cola Mare", 12.99, 750);

	int g_mic = std::dynamic_pointer_cast<Mancare>(popcorn_mic)->getGramaj();
	int g_mediu = std::dynamic_pointer_cast<Mancare>(popcorn_mediu)->getGramaj();
	int g_mare = std::dynamic_pointer_cast<Mancare>(popcorn_mare)->getGramaj();
	int v_mic = std::dynamic_pointer_cast<Bautura>(cola_mic)->getVolum();
	int v_mediu = std::dynamic_pointer_cast<Bautura>(cola_mediu)->getVolum();
	int v_mare = std::dynamic_pointer_cast<Bautura>(cola_mare)->getVolum();

	std::shared_ptr<Produs> meniu_mic = std::make_shared<Meniu>("Meniu Mic", 20.99, popcorn_mic->getNume(), g_mic, cola_mic->getNume(), v_mic, MIC);
	std::shared_ptr<Produs> meniu_mediu = std::make_shared<Meniu>("Meniu Mediu", 26.99, popcorn_mediu->getNume(), g_mediu, cola_mediu->getNume(), v_mediu, MEDIU);
	std::shared_ptr<Produs> meniu_mare = std::make_shared<Meniu>("Meniu Mare", 31.99, popcorn_mare->getNume(), g_mare, cola_mare->getNume(), v_mare, MARE);
	std::shared_ptr<Produs> meniu_mic_mediu = std::make_shared<Meniu>("Meniu mic-mediu", 23.99, popcorn_mic->getNume(), g_mic, cola_mediu->getNume(), v_mediu, SPECIAL);
	std::shared_ptr<Produs> meniu_mediu_mare = std::make_shared<Meniu>("Meniu mediu-mare", 28.99, popcorn_mediu->getNume(), g_mediu, cola_mare->getNume(), v_mare, SPECIAL);
	std::shared_ptr<Produs> pahar_dune = std::make_shared<Suvenir>("Pahar", 34.99, "Dune: Part One");
	std::shared_ptr<Produs> tricou_barbie = std::make_shared<Suvenir>("Tricou", 54.99, "Barbie");

	// adaugare produse la bar
	Bar& bar = Bar::getInstance();
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
		std::cout << "|------------------ Meniu ---------------|\n";
		std::cout << "| 1. Afisare program ziua curenta        |\n";
		std::cout << "|----------------------------------------|\n";
		std::cout << "| 2. Afisare program saptamana curenta   |\n";
		std::cout << "|----------------------------------------|\n";
		std::cout << "| 3. Afisare lista filme                 |\n";
		std::cout << "|----------------------------------------|\n";
		std::cout << "| 4. Afisare configuratie sali           |\n";
		std::cout << "|----------------------------------------|\n";
		std::cout << "| 5. Creare rezervare                    |\n";
		std::cout << "|----------------------------------------|\n";
		std::cout << "| 6. Cautare film dupa gen               |\n";
		std::cout << "|----------------------------------------|\n";
		std::cout << "| 7. Cautare sala dupa numar de randuri  |\n";
		std::cout << "|----------------------------------------|\n";
		std::cout << "| 8. Iesire                              |\n";
		std::cout << "|----------------------------------------|\n";

		std::cout << "Introduceti numarul optiunii dorite:";
		std::string linie;
		int optiune;
		while (true) {
			try {
				std::getline(std::cin, linie);
				optiune = 0;
				for (size_t i = 0; i < linie.size() && isdigit(linie[i]); i++)
					optiune = 10 * optiune + (linie[i] - '0');
				if (optiune < 1 || optiune > 8)
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
			std::cout << catalog_filme;
		else if (optiune == 4)
			std::cout << catalog_sali;
		else if (optiune == 5) {
			std::cout << "- Creare rezervare -\n\n";

			std::string nume, email, telefon;
			std::cout << "Nume: ";
			std::getline(std::cin, nume);
			std::cout << "Email: ";
			std::getline(std::cin, email);
			std::cout << "Telefon: ";
			std::getline(std::cin, telefon);
			Client client(nume, email, telefon);
			clienti.push_back(client);

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
			rezervare.setClient(client);
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
		else if (optiune == 6) {
			std::cout << "Introduceti genul de film cautat: ";
			std::getline(std::cin, linie);
			std::string gen;
			for (auto c : linie)
				gen += tolower(c);

			catalog_filme.cautaObiect(std::cout, [gen](const Film& film) {
				for (auto& gen_lista: film.getGen()) {
					std::string gen_lower;
					for (auto c : gen_lista)
						gen_lower += tolower(c);
					if (gen_lower == gen)
						return true;
				}
				return false;
			});
		}
		else if (optiune == 7) {
			std::cout << "Introduceti numarul minim de randuri cautat: ";
			std::getline(std::cin, linie);
			int nr_min = 0;
			for (size_t i = 0; i < linie.size() && isdigit(linie[i]); i++)
				nr_min = 10 * nr_min + (linie[i] - '0');

			std::cout << "Introduceti numarul maxim de randuri cautat: ";
			std::getline(std::cin, linie);
			int nr_max = 0;
			for (size_t i = 0; i < linie.size() && isdigit(linie[i]); i++)
				nr_max = 10 * nr_max + (linie[i] - '0');

			catalog_sali.cautaObiect(std::cout, [nr_min, nr_max](const Sala& sala) {
				return sala.getRanduri() >= nr_min && sala.getRanduri() <= nr_max;
			});
		}
		else if (optiune == 8)
			break;
		std::cout << "\n";
	}
	return 0;
}
