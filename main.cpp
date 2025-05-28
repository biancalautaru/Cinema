#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <vector>
#include <set>
#include <memory>

#include "headers/Drink.h"
#include "headers/Movie.h"
#include "headers/Auditorium.h"
#include "headers/Screening.h"
#include "headers/DaySchedule.h"
#include "headers/WeekSchedule.h"
#include "headers/Client.h"
#include "headers/Reservation.h"
#include "headers/Product.h"
#include "headers/Food.h"
#include "headers/Drink.h"
#include "headers/Menu.h"
#include "headers/Souvenir.h"
#include "headers/Bar.h"
#include "headers/InvalidOption.h"
#include "headers/WrongInput.h"
#include "headers/OccupiedSeat.h"
#include "headers/Catalog.h"
#include "headers/Director.h"
#include "headers/StudentGroupOfferBuilder.h"
#include "headers/FamilyOfferBuilder.h"
#include "headers/ProductFactory.h"

int main() {
	// create movies
	Catalog<Movie> movieCatalog;
	movieCatalog.addObject({"Memento", {"Mistery", "Thriller"}, 113, 2000, "Christopher Nolan", "N-15", "2D", 35});
	movieCatalog.addObject({"Catch Me If You Can", {"Biography", "Crime", "Drama"}, 141, 2002, "Steven Spielberg", "AP-12", "2D", 35});
	movieCatalog.addObject({"The Shawshank Redemption", {"Drama"}, 142, 1994, "Frank Darabont", "N-15", "2D", 35});
	movieCatalog.addObject({"Taxi Driver", {"Crime", "Drama"}, 114, 1976, "Martin Scorsese", "N-15", "2D", 30});
	movieCatalog.addObject({"Back to the Future", {"Adventure", "Comedy", "Sci-Fi"}, 116, 1985, "Robert Zemeckis", "AP-12", "2D", 30});
	movieCatalog.addObject({"The Talented Mr. Ripley", {"Crime", "Drama", "Thriller"}, 139, 1999, "Anthony Minghella", "N-15", "2D", 35});
	movieCatalog.addObject({"Inception", {"Action", "Adventure", "Sci-Fi", "Thriller"}, 148, 2010, "Christopher Nolan", "N-15", "2D", 40});
	movieCatalog.addObject({"Whiplash", {"Drama", "Music"}, 106, 2014, "Damien Chazelle", "AP-12", "2D", 30});
	movieCatalog.addObject({"Hachi: A Dog's Tale", {"Biography", "Drama", "Family"}, 93, 2009, "Lasse Hallstrom", "AG", "2D", 25});
	movieCatalog.addObject({"The Sixth Sense", {"Drama", "Mistery", "Thriller"}, 107, 1999, "M. Night Shyamalan", "AP-12", "2D", 30});
	movieCatalog.addObject({"Liar Liar", {"Comedy", "Fantasy"}, 86, 1997, "Tom Shadyac", "AP-12", "2D", 25});
	movieCatalog.addObject({"The Search for Santa Paws", {"Adventure", "Drama", "Family", "Fantasy"}, 96, 2010, "Robert Vince", "AG", "2D", 25});
	movieCatalog.addObject({"Barbie", {"Adventure", "Comedy", "Fantasy"}, 114, 2023, "Greta Gerwig", "AP-12", "2D", 25});
	movieCatalog.addObject({"The Godfather", {"Crime", "Drama"}, 175, 1972, "Francis Ford Coppola", "N-15", "2D", 35});
	movieCatalog.addObject({"Se7en", {"Crime", "Drama", "Mistery", "Thriller"}, 127, 1995, "David Fincher", "N-15", "2D", 30});
	movieCatalog.addObject({"The Wolf of Wall Street", {"Biography", "Comedy", "Crime", "Drama"}, 180, 2013, "Martin Scorsese", "IM-18", "2D", 35});
	movieCatalog.addObject({"Casino", {"Crime", "Drama"}, 178, 1995, "Martin Scorsese", "N-15", "2D", 35});
	movieCatalog.addObject({"Avatar", {"Action", "Adventure", "Fantasy", "Sci-Fi"}, 162, 2009, "James Cameron", "AP-12", "3D", 40});
	movieCatalog.addObject({"Once Upon a Time in America", {"Crime", "Drama"}, 229, 1984, "Sergio Leone", "IM-18", "2D", 40});
	movieCatalog.addObject({"Forrest Gump", {"Comedy", "Drama", "Romance"}, 142, 1994, "Robert Zemeckis", "AP-12", "2D", 30});
	movieCatalog.addObject({"Inglourious Basterds", {"Adventure", "Drama", "War"}, 153, 2009, "Quentin Tarantino", "IM-18", "2D", 35});
	movieCatalog.addObject({"Dune: Part One", {"Action", "Adventure", "Drama", "Sci-Fi"}, 155, 2021, "Denis Villeneuve", "AP-12", "3D", 40});
	movieCatalog.addObject({"The Princess Diaries", {"Comedy", "Family", "Romance"}, 105, 2001, "Garry Marshall", "AG", "2D", 25});
	std::vector<Movie> movies = movieCatalog.getObjects();

	// create auditoriums
	Catalog<Auditorium> auditoriumCatalog;
	auditoriumCatalog.addObject({1, 5, 20});
	auditoriumCatalog.addObject({2, 8, 12});
	auditoriumCatalog.addObject({3, 5, 15});
	auditoriumCatalog.addObject({4, 7, 11});
	auditoriumCatalog.addObject({5, 9, 23});
	std::vector<Auditorium> auditoriums = auditoriumCatalog.getObjects();

	// create clients
	Catalog<Client> clientCatalog;
	clientCatalog.addObject({"Ion Popescu", "ion.popescu@gmail.com", "0749187947"});
	clientCatalog.addObject({"George Ionescu", "george.ionescu@gmail.com", "0764367341"});
	clientCatalog.addObject({"Mihai Vasile", "mihai.vasile@yahoo.com", "0737635326"});
	clientCatalog.addObject({"Alexandru Radulescu", "alexandru.radulescu@gmail.com", "0789525437"});
	clientCatalog.addObject({"Gabriel Tudor", "gabriel.tudor@hotmail.com", "0778912345"});
	clientCatalog.addObject({"Maria Popa", "maria.popa@yahoo.com", "0758369424"});
	clientCatalog.addObject({"Diana Munteanu", "diana.munteanu@hotmail.com", "0723658741"});
	clientCatalog.addObject({"Gabriela Radu", "gabriela.radu@gmail.com", "0752375437"});
	clientCatalog.addObject({"Elena Dumitrescu", "elena.dumitrescu@yahoo.com", "0765432199"});
	clientCatalog.addObject({"Ana Dobre", "ana.dobre@gmail.com", "0745123789"});
	std::vector<Client> clients = clientCatalog.getObjects();

	// generate schedule
	WeekSchedule weekSchedule;
	weekSchedule = weekSchedule.generate(movies, auditoriums);

	// create existing reservations
	std::vector<Reservation> reservations;
	std::vector<std::pair<std::string, DaySchedule>> schedule = weekSchedule.getWeek();
	weekSchedule = {};
	for (size_t i = 0; i < schedule.size(); i++) {
		std::vector<Screening> screenings = schedule[i].second.getDay();

		for (size_t j = 0; j < screenings.size(); j++) {
			std::set<int> occupied = screenings[j].getOccupied();

			std::vector<int> clientsWithoutReservations;
			for (size_t k = 0; k < clients.size(); k++)
				clientsWithoutReservations.push_back(k);

			int lastReservation = reservations.size() - 1;

			// for each screening select a random number (between 0 and size(clients))
			std::srand(std::chrono::system_clock::now().time_since_epoch().count());
			int clientsNumber = rand() % clients.size();

			while (clientsNumber--) {
				// select a random client from the remaining ones
				int clientPos = rand() % clientsWithoutReservations.size();
				const Client& client = clients[clientsWithoutReservations[clientPos]];
				clientsWithoutReservations.erase(clientsWithoutReservations.begin() + clientPos);

				// randomly select seats (between 1 and 10 + should fit on one line) and number of students
				int seatsNumber = 1 + rand() % 10;
				int rowsNumber = rand() % screenings[j].getAuditorium().getRows();
				int columnsNumber = rand() % screenings[j].getAuditorium().getColumns();
				int startColumn = std::max(0, columnsNumber - seatsNumber / 2);
				int endColumn = std::min(columnsNumber + seatsNumber / 2, screenings[j].getAuditorium().getColumns() - 1);
				seatsNumber = endColumn - startColumn + 1;
				int studentsNumber = rand() % seatsNumber;
				std::vector<int> selected;
				for (int k = startColumn; k <= endColumn; k++) {
					occupied.insert(rowsNumber * screenings[j].getAuditorium().getColumns() + k + 1);
					selected.push_back(rowsNumber * screenings[j].getAuditorium().getColumns() + k + 1);
				}

				// create reservation
				Reservation reservation;
				reservation.setClient(client);
				reservation.setSeats(selected);
				reservation.setStudents(studentsNumber);
				reservations.push_back(reservation);
			}

			screenings[j].setOccupied(occupied);
			for (size_t k = lastReservation + 1; k < reservations.size(); k++)
				reservations[k].setScreening(screenings[j]);
		}

		DaySchedule daySchedule;
		daySchedule.setDay(screenings);
		weekSchedule = weekSchedule.addDay({schedule[i].first, daySchedule});
	}

	// create products
	ProductFactory productFactory;

	std::shared_ptr<Product> smallPopcorn = productFactory.createProduct(FOOD, "Small Popcorn", 16.99, 300);
	std::shared_ptr<Product> mediumPopcorn = productFactory.createProduct(FOOD, "Medium Popcorn", 20.99, 500);
	std::shared_ptr<Product> largePopcorn = productFactory.createProduct(FOOD, "Large Popcorn", 24.99, 800);
	std::shared_ptr<Product> smallCocaCola = productFactory.createProduct(DRINK, "Small Coca-Cola", 7.99, 330);
	std::shared_ptr<Product> mediumCocaCola = productFactory.createProduct(DRINK, "Medium Coca-Cola", 9.99, 500);
	std::shared_ptr<Product> largeCocaCola = productFactory.createProduct(DRINK, "Large Coca-Cola", 12.99, 750);

	int wSmall = std::dynamic_pointer_cast<Food>(smallPopcorn)->getWeight();
	int wMedium = std::dynamic_pointer_cast<Food>(mediumPopcorn)->getWeight();
	int wLarge = std::dynamic_pointer_cast<Food>(largePopcorn)->getWeight();
	int vSmall = std::dynamic_pointer_cast<Drink>(smallCocaCola)->getVolume();
	int vMedium = std::dynamic_pointer_cast<Drink>(mediumCocaCola)->getVolume();
	int vLarge = std::dynamic_pointer_cast<Drink>(largeCocaCola)->getVolume();

	std::shared_ptr<Product> smallMenu = productFactory.createProduct(MENU, "Small Menu", 20.99, smallPopcorn->getName(), wSmall, smallCocaCola->getName(), vSmall, SMALL);
	std::shared_ptr<Product> mediumMenu = productFactory.createProduct(MENU, "Medium Menu", 26.99, mediumPopcorn->getName(), wMedium, mediumCocaCola->getName(), vMedium, MEDIUM);
	std::shared_ptr<Product> largeMenu = productFactory.createProduct(MENU, "Large Menu", 31.99, largePopcorn->getName(), wLarge, largeCocaCola->getName(), vLarge, LARGE);
	std::shared_ptr<Product> smallMediumMenu = productFactory.createProduct(MENU, "Small-Medium Menu", 23.99, smallPopcorn->getName(), wSmall, mediumCocaCola->getName(), vMedium, SPECIAL);
	std::shared_ptr<Product> mediumLargeMenu = productFactory.createProduct(MENU, "Medium-Large Menu", 28.99, mediumPopcorn->getName(), wMedium, largeCocaCola->getName(), vLarge, SPECIAL);

	std::shared_ptr<Product> duneCup = productFactory.createProduct(SOUVENIR, "Cup", 34.99, "Dune: Part One");
	std::shared_ptr<Product> barbieTShirt = productFactory.createProduct(SOUVENIR, "T-Shirt", 54.99, "Barbie");

	// add products to the bar
	Bar* bar = Bar::getInstance();
	bar->addProduct(smallPopcorn->clone());
	bar->addProduct(mediumPopcorn);
	bar->addProduct(largePopcorn);
	bar->addProduct(smallCocaCola);
	bar->addProduct(mediumCocaCola);
	bar->addProduct(largeCocaCola);
	bar->addProduct(smallMenu);
	bar->addProduct(mediumMenu);
	bar->addProduct(largeMenu);
	bar->addProduct(smallMediumMenu);
	bar->addProduct(mediumLargeMenu);
	bar->addProduct(duneCup);
	bar->addProduct(barbieTShirt);

	bar->applyPromotions();
	bar->applyMenuPromotions();

	// create offers
	Director director;

	auto* offerBuilder1 = new StudentGroupOfferBuilder();
	director.setOfferBuilder(offerBuilder1);
	director.buildOffer();
	const Offer* studentGroupOffer = director.getOffer();
	delete offerBuilder1;

	auto* offerBuilder2 = new FamilyOfferBuilder();
	director.setOfferBuilder(offerBuilder2);
	director.buildOffer();
	const Offer* familyOffer = director.getOffer();
	delete offerBuilder2;

	// interactive menu
	while (true) {
		std::cout << "|------------------ Menu ----------------|\n";
		std::cout << "| 1. View today's schedule               |\n";
		std::cout << "|----------------------------------------|\n";
		std::cout << "| 2. View this week's schedule           |\n";
		std::cout << "|----------------------------------------|\n";
		std::cout << "| 3. View movie list                     |\n";
		std::cout << "|----------------------------------------|\n";
		std::cout << "| 4. View auditorium configurations      |\n";
		std::cout << "|----------------------------------------|\n";
		std::cout << "| 5. Make a reservation                  |\n";
		std::cout << "|----------------------------------------|\n";
		std::cout << "| 6. Search movie by genre               |\n";
		std::cout << "|----------------------------------------|\n";
		std::cout << "| 7. Search auditorium by number of rows |\n";
		std::cout << "|----------------------------------------|\n";
		std::cout << "| 8. View offers                         |\n";
		std::cout << "|----------------------------------------|\n";
		std::cout << "| 9. Exit                                |\n";
		std::cout << "|----------------------------------------|\n";

		std::cout << "Enter the number of the desired option:";
		std::string line;
		int option;
		while (true) {
			try {
				std::getline(std::cin, line);
				option = 0;
				for (size_t i = 0; i < line.size() && isdigit(line[i]); i++)
					option = 10 * option + (line[i] - '0');
				if (option < 1 || option > 9)
					throw InvalidOption();
				break;
			}
			catch (const InvalidOption& e) {
				std::cout << e.what();
			}
		}

		if (option == 1) {
			auto today = std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now());
			auto dayOfTheWeek = std::chrono::weekday{std::chrono::sys_days{today}};
			int todayNumber = dayOfTheWeek.c_encoding() - 1;
			if (todayNumber == -1)
				todayNumber = 6;
			auto todaySchedule = weekSchedule.getWeek()[todayNumber];
			std::cout << "- " << todaySchedule.first << " -\n" << todaySchedule.second;
		}
		else if (option == 2)
			std::cout << weekSchedule;
		else if (option == 3)
			std::cout << movieCatalog;
		else if (option == 4)
			std::cout << auditoriumCatalog;
		else if (option == 5) {
			std::cout << "- Create reservation -\n\n";

			std::string name, email, phone;
			std::cout << "Name: ";
			std::getline(std::cin, name);
			std::cout << "Email: ";
			std::getline(std::cin, email);
			std::cout << "Phone number: ";
			std::getline(std::cin, phone);
			Client client(name, email, phone);
			clients.push_back(client);

			std::string day;
			std::cout << "Chosen day: ";
			std::getline(std::cin, day);
			if (islower(day[0]))
				day[0] = day[0] - 'a' + 'A';
			int dayNumber = -1;
			if (day == "Monday")
				dayNumber = 0;
			else if (day == "Tuesday")
				dayNumber = 1;
			else if (day == "Wednesday")
				dayNumber = 2;
			else if (day == "Thursday")
				dayNumber = 3;
			else if (day == "Friday")
				dayNumber = 4;
			else if (day == "Saturday")
				dayNumber = 5;
			else if (day == "Sunday")
				dayNumber = 6;

			std::vector<Screening> screenings, screeningsModified;
			screenings = weekSchedule.getWeek()[dayNumber].second.getDay();
			for (size_t i = 0; i < screenings.size(); i++) {
				if (i + 1 < 10)
					std::cout << " ";
				std::cout << i + 1 << ". ";
				std::cout << "| ";
				std::cout << "Time: " << screenings[i].getTime() << " | ";
				std::cout << "Aud. " << screenings[i].getAuditorium().getNumber() << " | ";
				std::cout << screenings[i].getMovie().getName() << " | ";
				int seatsNumber = screenings[i].availableSeats();
				if (seatsNumber == 1)
					std::cout << seatsNumber << " seat available";
				else
					std::cout << seatsNumber << " seats available";
				std::cout << "\n";
			}
			std::cout << "\n";

			std::cout << "Enter the number of the desired screening: ";
			std::getline(std::cin, line);
			int screeningNumber = 0;
			for (size_t i = 0; i < line.size() && isdigit(line[i]); i++)
				screeningNumber = 10 * screeningNumber + (line[i] - '0');
			screeningNumber--;
			if (screeningNumber == -1)
				screeningNumber = 0;
			std::cout << screenings[screeningNumber] << "\n";

			std::cout << "Enter the desired seats (separated by spaces): ";
			std::vector<int> seats;
			while (true) {
				try {
					while (true) {
						std::getline(std::cin, line);
						try {
							for (size_t i = 0; i < line.size(); i++)
								if (!isdigit(line[i]) && line[i] != ' ')
									throw WrongInput();
							break;
						}
						catch (const WrongInput& e) {
							std::cout << e.what();
						}
					}

					seats.clear();
					for (size_t i = 0; i < line.size(); i++)
						if (isdigit(line[i])) {
							int seat = 0;
							size_t j;
							for (j = i; isdigit(line[j]); j++)
								seat = seat * 10 + line[j] - '0';
							i = j - 1;
							seats.push_back(seat);
						}

					for (auto seat : seats) {
						if (seat < 1 || seat > screenings[screeningNumber].getAuditorium().getRows() * screenings[screeningNumber].getAuditorium().getColumns())
							throw WrongInput();
						for (auto it : screenings[screeningNumber].getOccupied())
							if (seat == it)
								throw OccupiedSeat();
					}

					break;
				}
				catch (const WrongInput& e) {
					std::cout << e.what();
				}
				catch (const OccupiedSeat& e) {
					std::cout << e.what();
				}
			}

			std::cout << "Number of student tickets (20% off): ";
			std::getline(std::cin, line);
			int students = 0;
			for (size_t i = 0; i < line.size() && isdigit(line[i]); i++)
				students = 10 * students + (line[i] - '0');

			Reservation reservation;
			reservation.setClient(client);
			reservation.setScreening(screenings[screeningNumber]);
			reservation.setSeats(seats);
			reservation.setStudents(students);
			reservations.push_back(reservation);

			std::set<int> occupied = screenings[screeningNumber].getOccupied();
			for (size_t i = 0; i < seats.size(); i++)
				occupied.insert(seats[i]);
			std::vector<std::pair<std::string, DaySchedule>> scheduleModified = weekSchedule.getWeek();
			screeningsModified = scheduleModified[dayNumber].second.getDay();
			screeningsModified[screeningNumber].setOccupied(occupied);
			scheduleModified[dayNumber].second.setDay(screeningsModified);
			weekSchedule.setWeek(scheduleModified);
			for (size_t i = 0; i < reservations.size(); i++)
				if (reservations[i].getScreening().getDay() == screenings[screeningNumber].getDay()
					&& reservations[i].getScreening().getTime() == screenings[screeningNumber].getTime()
					&& reservations[i].getScreening().getAuditorium().getNumber() == screenings[screeningNumber].getAuditorium().getNumber())
					reservations[i].setScreening(screeningsModified[screeningNumber]);

			std::cout << "Do you want to add products from the bar to the reservation? (yes/no)\n";
			std::getline(std::cin, line);
			if (line == "no") {
				std::cout << "Reservation completed successfully!\n\nReservation details:\n";
				reservations[reservations.size() - 1].displayReservation(std::cout);
			}
			else {
				reservations[reservations.size() - 1].readProducts(std::cin, std::cout, bar);
				std::cout << "Reservation completed successfully!\n\nReservation details:\n";
				reservations[reservations.size() - 1].displayReservation(std::cout);
				std::cout << "\n";
				std::cout << "Products ordered from the bar:\n";
				reservations[reservations.size() - 1].displayProducts(std::cout);
				std::cout << "\n";
				std::cout << "Total reservation price: " << reservations[reservations.size() - 1].totalPrice() << " lei\n";
			}
		}
		else if (option == 6) {
			std::cout << "Enter the genre you are searching for: ";
			std::getline(std::cin, line);
			std::string genre;
			for (auto c : line)
				genre += tolower(c);

			movieCatalog.searchObject(std::cout, [genre](const Movie& movie) {
				for (const std::string& genreList : movie.getGenre()) {
					std::string genreLower;
					for (auto c : genreList)
						genreLower += tolower(c);
					if (genreLower == genre)
						return true;
				}
				return false;
			});
		}
		else if (option == 7) {
			std::cout << "Enter the minimum number of rows you are searching for: ";
			std::getline(std::cin, line);
			int minimum = 0;
			for (size_t i = 0; i < line.size() && isdigit(line[i]); i++)
				minimum = 10 * minimum + (line[i] - '0');

			std::cout << "Enter the maximum number of rows you are searching for: ";
			std::getline(std::cin, line);
			int maximum = 0;
			for (size_t i = 0; i < line.size() && isdigit(line[i]); i++)
				maximum = 10 * maximum + (line[i] - '0');

			auditoriumCatalog.searchObject(std::cout, [minimum, maximum](const Auditorium& auditorium) {
				return auditorium.getRows() >= minimum && auditorium.getRows() <= maximum;
			});
		}
		else if (option == 8) {
			std::cout << "Existing offers:\n";
			studentGroupOffer->display(std::cout);
			familyOffer->display(std::cout);
		}
		else if (option == 9)
			break;
		std::cout << "\n";
	}
	return 0;
}
