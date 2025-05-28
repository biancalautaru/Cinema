#ifndef RESERVATION_H
#define RESERVATION_H

#include <memory>

#include "Client.h"
#include "Screening.h"
#include "Product.h"
#include "Bar.h"

class Reservation {
private:
	Client client;
	Screening screening;
	std::vector<int> seats;
	int students;
	std::vector<std::shared_ptr<Product>> products;

public:
	Reservation();
	~Reservation();

	Reservation(const Client& client, const Screening& screening, const std::vector<int>& seats, const int& students,
	          const std::vector<std::shared_ptr<Product>>& products);
	Reservation(const Reservation& copy);

	Reservation& operator=(const Reservation& copy);
	friend std::ostream& operator<<(std::ostream& os, const Reservation& reservation);
	void displayReservation(std::ostream& os) const;
	void displayProducts(std::ostream& os) const;
	void readProducts(std::istream& is, std::ostream& os, const Bar* bar);

	void setClient(const Client& client_);
	void setScreening(const Screening& screening_);
	const Screening& getScreening() const;
	void setSeats(const std::vector<int>& seats_);
	void setStudents(const int students_);

	void addProduct(const std::shared_ptr<Product>& product);
	double reservationPrice() const;
	double totalPrice() const;
};

#endif
