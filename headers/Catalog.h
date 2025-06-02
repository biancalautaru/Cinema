#ifndef CATALOG_H
#define CATALOG_H

#include <iostream>
#include <vector>

/**
 * @class Catalog
 * @brief A generic catalog container for storing and managing a collection of objects.
 *
 * The Catalog class is a templated container that stores a list of object of the
 * template type. It provides functionality for adding, accessing and searching for
 * objects using a given criterion.
 *
 * @tparam T The type of object stored in the catalog.
 */
template <typename T>
class Catalog {
private:
	std::vector<T> objects;

public:
	Catalog() = default;

	~Catalog() = default;

	explicit Catalog(const std::vector<T>& objects):
		objects(objects) {
	}

	Catalog(const Catalog& copy):
		objects(copy.objects) {
	}

	Catalog& operator=(const Catalog& copy) {
		objects = copy.objects;
		return *this;
	}

	/**
	 * @brief Prints all objects in the catalog.
	 *
	 * Displays information about each object in the catalog.
	 *
	 * @param os The output stream to write to.
	 * @param catalog The Catalog object to print.
	 * @return A reference to the output stream.
	 */
	friend std::ostream& operator<<(std::ostream& os, const Catalog& catalog) {
		for (const T& object : catalog.objects)
			os << object << "\n";
		return os;
	}

	/**
	 * @brief Adds a new object to the catalog.
	 * @param object The object to add.
	 */
	void addObject(const T& object) {
		objects.push_back(object);
	}

	/**
	 * @brief Searches for objects in the catalog that match  a given criterion.
	 *
	 * This method uses a callable as the search criterion. If matches are found, they
	 * are printed and if not, a message is displayed instead.
	 *
	 * @tparam C A callable type that returns true if an object matches the criterion.
	 * @param os The output stream to write to.
	 * @param criterion The callable used to evaluate each object.
	 */
	template <typename C>
	void searchObject(std::ostream& os, const C& criterion) const {
		bool ok = false;
		for (const T& object : objects)
			if (criterion(object)) {
				os << object << "\n";
				ok = true;
			}
		if (ok == false)
			os << "Nothing has been found!\n";
	}

	const std::vector<T>& getObjects() const {
		return objects;
	}
};

#endif
