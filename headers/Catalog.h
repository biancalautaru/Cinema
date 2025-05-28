#ifndef CATALOG_H
#define CATALOG_H

#include <iostream>
#include <vector>

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

	friend std::ostream& operator<<(std::ostream& os, const Catalog& catalog) {
		for (const T& object : catalog.objects)
			os << object << "\n";
		return os;
	}

	const std::vector<T>& getObjects() const {
		return objects;
	}

	void addObject(const T& object) {
		objects.push_back(object);
	}

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
};

#endif
