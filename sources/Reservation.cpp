#include "../headers/Reservation.h"
#include "../headers/WrongInput.h"
#include "../headers/NonexistentProduct.h"

#include <iomanip>

Reservation::Reservation() {
}

Reservation::~Reservation() {
}

Reservation::Reservation(const Client& client, const Screening& screening, const std::vector<int>& seats, const int& students,
                     const std::vector<std::shared_ptr<Product>>& products):
	client(client),
	screening(screening),
	seats(seats),
	students(students),
	products(products) {
}

Reservation::Reservation(const Reservation& copy):
	client(copy.client),
	screening(copy.screening),
	seats(copy.seats),
	students(copy.students),
	products(copy.products) {
}

Reservation& Reservation::operator=(const Reservation& copy) {
	client = copy.client;
	screening = copy.screening;
	seats = copy.seats;
	students = copy.students;
	products = copy.products;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Reservation& reservation) {
	reservation.displayReservation(os);
	reservation.displayProducts(os);
	return os;
}

void Reservation::displayReservation(std::ostream& os) const {
	os << std::fixed << std::setprecision(2);
	os << client;
	os << "Movie: \"" << screening.getMovie().getName() << "\", ";
	os << screening.getDay() << ", Time: " << screening.getTime() << ", Aud. " << screening.getAuditorium().getNumber() << "\n";
	os << "Seats: ";
	for (size_t i = 0; i < seats.size(); i++) {
		os << seats[i];
		if (i != seats.size() - 1)
			os << ", ";
	}
	os << "\n";
	os << "Number of students (20% off): " << students << "\n";
	os << "Price: " << reservationPrice() << " lei\n";
}

void Reservation::displayProducts(std::ostream& os) const {
	for (const auto& product : products)
		product->display(os);
}

void Reservation::readProducts(std::istream& is, std::ostream& os, const Bar* bar) {
	bar->display(os);
	os << "\n";

	os << "Enter the numbers corresponding to the desired products (separated by spaces): ";
	std::vector<int> productsNumbers;
	std::string line;
	while (true) {
		try {
			while (true) {
				std::getline(is, line);
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

			productsNumbers.clear();
			for (size_t i = 0; i < line.size(); i++)
				if (isdigit(line[i])) {
					int nr = 0;
					size_t j;
					for (j = i; isdigit(line[j]); j++)
						nr = nr * 10 + line[j] - '0';
					i = j - 1;
					nr--;
					productsNumbers.push_back(nr);
				}

			for (auto nr : productsNumbers)
				if (nr < 0 || nr > static_cast<int>(bar->getProducts().size()) - 1)
					throw NonexistentProduct();
			break;
		}
		catch (const NonexistentProduct& e) {
			std::cout << e.what();
		}
	}

	for (auto nr : productsNumbers)
		addProduct(bar->getProducts()[nr]);
}

void Reservation::setClient(const Client& client_) {
	client = client_;
}

void Reservation::setScreening(const Screening& screening_) {
	screening = screening_;
}

const Screening& Reservation::getScreening() const {
	return screening;
}

void Reservation::setSeats(const std::vector<int>& seats_) {
	seats = seats_;
}

void Reservation::setStudents(const int students_) {
	students = students_;
}

void Reservation::addProduct(const std::shared_ptr<Product>& product) {
	products.push_back(product);
}

double Reservation::reservationPrice() const {
	return (seats.size() - students) * screening.getMovie().getPrice() + students * screening.getMovie().studentPrice();
}

double Reservation::totalPrice() const {
	double total = reservationPrice();
	for (const auto& product : products)
		total += product->getPrice();
	return total;
}
