#ifndef RESERVATION_H
#define RESERVATION_H

#include <memory>

#include "Client.h"
#include "Screening.h"
#include "Product.h"
#include "Bar.h"


/**
 * @class Reservation
 * @brief Represents a reservation for tickets to a movie screening and
 * (optionally) for products from the bar.
 *
 * The Reservation class contains all the information related to a reservation:
 * the client, the screening, the chosen seats, the number of student tickets
 * and a list of products reserved from the bar.
 */
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

	/**
	 * @brief Prints all the information about a reservation.
	 *
	 * Calls the Reservation::displayReservation and Reservation::displayProducts methods.
	 * 
	 * @param os The output stream to write to.
	 * @param reservation The Reservation object to print.
	 * @return A reference to the output stream.
	 */
	friend std::ostream& operator<<(std::ostream& os, const Reservation& reservation);

	/**
	 * @brief Prints all the information about a reservation.
	 *
	 * Displays the client's information and the information for the screening,
	 * as well as the reserved seats and the number of student tickets
	 * along with their price.
	 *
	 * @param os The output stream to write to.
	 */
	void displayReservation(std::ostream& os) const;

	/**
	 * @brief Prints information about the reserved products.
	 *
	 * Displays the list of products that have been added to the reservation.
	 *
	 * @param os The output stream to write to.
	 */
	void displayProducts(std::ostream& os) const;

	/**
	 * @brief Reads a list of desired products from the user and adds them
	 * to the reservation.
	 *
	 * Displays the list of available products using Bar::display, prompts
	 * the user to input the desired products and adds them to the reservation
	 * after validating the input and handling incorrect entries.
	 *
	 * @param is The input stream to read from.
	 * @param os The output stream to write to.
	 * @param bar The Bar object to choose products from.
	 */
	void readProducts(std::istream& is, std::ostream& os, const std::shared_ptr<Bar>& bar);
	
	void setClient(const Client& client_);

	void setScreening(const Screening& screening_);

	const Screening& getScreening() const;

	void setSeats(const std::vector<int>& seats_);

	void setStudents(const int students_);

	/**
	 * @brief Adds a new product to the reservation.
	 * @param product The product to be added to the product list.
	 */
	void addProduct(const std::shared_ptr<Product>& product);

	/**
	 * @brief Calculates the price of the tickets.
	 *
	 * Calculates the total cost of the reserved tickets applying a discount
	 * for student tickets.
	 *
	 * @return The price of the tickets.
	 */
	double reservationPrice() const;

	/**
	 * @brief Calculates the total price of the reservation.
	 *
	 * Calls the Reservation::reservationPrice method to get the price of the tickets
	 * and adds the price of each product to it.
	 *
	 * @return The price of the whole reservation.
	 */
	double totalPrice() const;
};

#endif
