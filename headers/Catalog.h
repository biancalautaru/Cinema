#ifndef CATALOG_H
#define CATALOG_H

#include <iostream>
#include <vector>

template <typename T>
class Catalog {
private:
	std::vector<T> obiecte;

public:
	Catalog() {}
	~Catalog() {}

	explicit Catalog(const std::vector<T>& obiecte):
		obiecte(obiecte)
	{}

	Catalog(const Catalog& copie):
		obiecte(copie.obiecte)
	{}

	Catalog& operator=(const Catalog& copie)  {
		obiecte = copie.obiecte;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Catalog& catalog) {
		for (const T& obiect : catalog.obiecte)
			os << obiect << "\n";
		return os;
	}

	const std::vector<T>& getObiecte() const {
		return obiecte;
	}

	void adaugaObiect(const T& obiect) {
		obiecte.push_back(obiect);
	}

	template <typename C>
	void cautaObiect(std::ostream& os, const C& criteriu) const {
		bool ok = false;
		for (const T& obiect : obiecte)
			if (criteriu(obiect)) {
				os << obiect << "\n";
				ok = true;
			}
		if (ok == false)
			os << "Nu a fost gasit nimic!\n";
	}
};

#endif
